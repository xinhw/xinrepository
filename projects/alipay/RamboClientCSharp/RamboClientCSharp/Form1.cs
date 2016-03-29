using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Net;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace RamboClientCSharp
{
    public partial class Form1 : Form
    {
   
        OpenapiRamboProxy openapiRamboProxy;
        RamboClient ramboClient;

        String cityCode = "000000";

        public Form1()
        {
            InitializeComponent();

            foreach (string portName in SerialPort.GetPortNames())
                comboBox1.Items.Add(portName);
          
            comboBox2.Items.Add(VoucherConfirmRequest.GetMethodName());
            comboBox2.Items.Add(VoucherQueryRequest.GetMethodName());
            comboBox2.Items.Add(VoucherCancelRequest.GetMethodName());
            comboBox2.Items.Add(VoucherUploadRequest.GetMethodName());
            comboBox2.SelectedIndex = 0;

            comboBox1.SelectedIndex = 0;

            comboBox1_SelectedIndexChanged(null, null);
            comboBox2_SelectedIndexChanged(null, null);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                String service = comboBox2.Text;
                String Parameters = textBox1.Text;
                JObject result = openapiRamboProxy.invoke(service, JObject.Parse(Parameters));
                
                Thread t = new Thread(new ThreadStart(() => {
                    JObject result2 = openapiRamboProxy.invoke(service, JObject.Parse(Parameters));
                }));

                t.Start();

                textBox2.Text = result.ToString(Formatting.Indented);
            }
            catch(Exception err)
            {
                textBox2.Text = err.Message;
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(ramboClient != null)
            {
                ramboClient.Close();
            }

            ramboClient = new RamboClient(comboBox1.Text);
            openapiRamboProxy = new OpenapiRamboProxy(ramboClient);
            ramboClient.Open();
        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(comboBox2.Text == VoucherConfirmRequest.GetMethodName())
            {                
                VoucherConfirmRequest parameters = new VoucherConfirmRequest();
                parameters.CityCode = cityCode;
                parameters.BizRequestId = Dns.GetHostName();
                parameters.BizInfoExt = JsonConvert.SerializeObject(new { servicePoint = "a1", terminalId = "a2" });
                parameters.OperateTime = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
                parameters.TicketNo = "test";

                JObject jObject = JsonHelper.FromRamboObject(parameters);             
                textBox1.Text = jObject.ToString(Formatting.Indented);
            }
            else if (comboBox2.Text == VoucherQueryRequest.GetMethodName())
            {
                VoucherQueryRequest parameters = new VoucherQueryRequest();
                parameters.CityCode = cityCode;
                parameters.TicketNo = "test";

                JObject jObject = JsonHelper.FromRamboObject(parameters);
                textBox1.Text = jObject.ToString(Formatting.Indented);
            }
            else if (comboBox2.Text == VoucherCancelRequest.GetMethodName())
            {
                VoucherCancelRequest parameters = new VoucherCancelRequest();
                parameters.CityCode = cityCode;
                parameters.BizInfoExt = JsonConvert.SerializeObject(new { servicePoint = "a1", terminalId = "a2" });
                parameters.OperateTime = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
                parameters.TicketNo = "test";

                JObject jObject = JsonHelper.FromRamboObject(parameters);
                textBox1.Text = jObject.ToString(Formatting.Indented);
            }
            else if (comboBox2.Text == VoucherUploadRequest.GetMethodName())
            {
                VoucherUploadRequest parameters = new VoucherUploadRequest();
                parameters.CityCode = cityCode;
                parameters.BizInfoExt = JsonConvert.SerializeObject(new { servicePoint = "a1", terminalId = "a2" });
                parameters.OperateTime = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
                parameters.TicketNo = "test";

                JObject jObject = JsonHelper.FromRamboObject(parameters);
                textBox1.Text = jObject.ToString(Formatting.Indented);
            }
        }
    }
}
