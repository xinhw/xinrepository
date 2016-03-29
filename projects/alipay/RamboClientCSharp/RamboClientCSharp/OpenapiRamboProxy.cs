using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Text;

namespace RamboClientCSharp
{
    class TransportException : Exception
    {
        public int ErrorCode { get; set; }
        public String ErrorString { get; set; }
        public TransportException(int code, String msg) : base(msg)
        {
            ErrorCode = code;
            ErrorString = msg;
        } 
    }

    class OpenapiRamboProxy
    {
        class Request
        {
            public String MethodName { get; set; }
            public JObject Parameters { get; set; }
        }

        class Response
        {
            public int ErrorCode { get; set; }
            public String ErrorString { get; set; }
            public String ResultName { get; set; }
            public JObject Result { get; set; }
        }

        RamboClient ramboClient = null;
        public OpenapiRamboProxy(RamboClient ramboClient)
        {
            this.ramboClient = ramboClient;
        }

        public JObject invoke(String methodName, JObject parameters)
        {
            Request request = new Request();
            request.MethodName = methodName;
            request.Parameters = parameters;
            JObject responseObject = ramboClient.Invoke("OpenapiRambo", JsonHelper.FromRamboObject(request));
            Response response = JsonHelper.ToRamboObject<Response>(responseObject);
            if(response.ErrorCode != 0)
            {
                throw new TransportException(response.ErrorCode, response.ErrorString);
            }

            return response.Result;
        }

        //public T invoke<T,U>(U u) where U : OpenapiRequestBase where T : OpenapiResponseBase
        //{
        //    JObject parameters = JsonHelper.FromRamboObject(u);
        //    JObject result = invoke(u.GetMethodName(), parameters);
        //    return JsonHelper.ToRamboObject<T>(result);
        //}
    }
}
