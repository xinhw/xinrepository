using Newtonsoft.Json;
using Newtonsoft.Json.Converters;
using Newtonsoft.Json.Linq;
using Newtonsoft.Json.Serialization;
using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace RamboClientCSharp
{
    public enum RamboError
    {
        NoError,
        DriversError,
        Timeout,
        InternalError
    }

    public class RamboException : Exception
    {
        RamboError ErrorCode { get; set; }
        public RamboException(RamboError code)
        {
            ErrorCode = code;
        }

        public RamboException(RamboError code, String message) : base(message)
        {
            ErrorCode = code;
        }
    }

    class RamboClient : IDisposable
    {
        class Request
        {
            public string Rambo { get; set; }
            public string Id { get; set; }
            public JObject Parameters { get; set; }
        }

        class Response
        {
            public string Id { get; set; }
            public RamboError ErrorCode { get; set; }
            public JObject Result { get; set; }
        }

        class RamboInfo
        {
            public ManualResetEvent ManualEvent;
            public Timer Timer;
            public RamboError Error;
            public JObject Result;
        }        

        SerialPort serialPort = new SerialPort();
        byte[] endBytes = new byte[1];

        List<ArraySegment<byte>> readingBuffers = new List<ArraySegment<byte>>();
        int readingBufferLength = 0;

        Dictionary<String, RamboInfo> ramboInfoDictionary = new Dictionary<string, RamboInfo>();
        int requestTimeout;
        public RamboClient(String serialName, int requestTimeout = 1 * 60 * 1000)        {
            serialPort = new SerialPort(serialName, 19200, Parity.None, 8, StopBits.Two);
            serialPort.DataReceived += SerialPort_DataReceived;    
            endBytes[0] = 0;
            this.requestTimeout = requestTimeout;
        }

        private void SerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            var buffer = new byte[serialPort.BytesToRead];
            int received = serialPort.Read(buffer, 0, buffer.Length);
            int pos = 0;
            for (int i = 0; i < received; ++i)
            {
                if (buffer[i] == 0)
                {
                    int dataLength = i - pos;
                    int messageLength = dataLength + readingBufferLength;
                    if (messageLength != 0)
                    {
                        var messageBytes = new byte[messageLength];
                        int messageBytesPos = 0;
                        foreach (var segment in readingBuffers)
                        {
                            Array.Copy(segment.Array, segment.Offset, messageBytes, messageBytesPos, segment.Count);
                            messageBytesPos += segment.Count;
                        }

                        Array.Copy(buffer, pos, messageBytes, messageBytesPos, dataLength);

                        String message = Encoding.UTF8.GetString(messageBytes);
                        Response response = JsonHelper.DeserializeRamboObject<Response>(message);
                        OnFinished(response.Id, response.ErrorCode, response.Result);
                    }

                    readingBuffers.Clear();
                    readingBufferLength = 0;
                    pos = i + 1;
                }
            }

            if (pos != received)
            {
                readingBuffers.Add(new ArraySegment<byte>(buffer, pos, received - pos));
                readingBufferLength += received - pos;
            }
        }

        public void Open()
        {
            serialPort.Open();
        }

        public void Close()
        {
            serialPort.Close();
        }       

        public JObject Invoke(String rambo, JObject parameters)
        {
            String id = Guid.NewGuid().ToString();

            var ramboInfo = new RamboInfo();
            ramboInfo.ManualEvent = new ManualResetEvent(false);
            ramboInfo.Timer = new Timer(OnRamboTimeout, id, requestTimeout, Timeout.Infinite);

            lock (ramboInfoDictionary)
            {
                ramboInfoDictionary.Add(id, ramboInfo);
            }

            Request request = new Request()
            {
                Rambo = rambo,
                Id = id,
                Parameters = parameters
            };

            var requestString = JsonHelper.SerializeRamboObject(request);
            var requestData = Encoding.UTF8.GetBytes(requestString);

            serialPort.Write(requestData, 0, requestData.Length);
            serialPort.Write(endBytes, 0, 1);

            ramboInfo.ManualEvent.WaitOne();

            if (ramboInfo.Error != RamboError.NoError)
                throw new RamboException(ramboInfo.Error);

            return ramboInfo.Result;
        }

        void OnFinished(String id, RamboError error, JObject result)
        {
            RamboInfo ramboInfo = null;
            lock (ramboInfoDictionary)
            {
                if (ramboInfoDictionary.TryGetValue(id, out ramboInfo))
                {
                    ramboInfoDictionary.Remove(id);
                }
            }

            if (ramboInfo != null)
            {
                ramboInfo.Error = error;
                ramboInfo.Result = result;
                ramboInfo.ManualEvent.Set();
            }
        }

        void OnRamboTimeout(Object o)
        {
            var id = (String)o;
            OnFinished(id, RamboError.Timeout, null);
        }

        public void Dispose()
        {
            serialPort.Dispose();
        }
    }
}
