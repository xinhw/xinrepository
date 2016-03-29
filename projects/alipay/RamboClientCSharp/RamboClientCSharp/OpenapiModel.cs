using System;
using System.Collections.Generic;
using System.Text;

namespace RamboClientCSharp
{
    class OpenapiRequestBase
    {
    }

    class OpenapiResponseBase
    {
        String Code { get; set; }
        String Msg { get; set; }
        String SubCode { get; set; }
        String SubMsg { get; set; }
    }

    class VoucherCancelRequest : OpenapiRequestBase
    {
        public String TradeNo { get; set; }
        public String TicketNo { get; set; }
        public String CityCode { get; set; }
        public String OperateTime { get; set; }
        public String BizInfoExt { get; set; }

        public static String GetMethodName()
        {
            return "alipay.commerce.cityfacilitator.voucher.cancel";
        }
    }

    class VoucherCancelResponse : OpenapiResponseBase
    {
    }

    class VoucherConfirmRequest : OpenapiRequestBase
    {
        public String TicketNo { get; set; }
        public String TradeNo { get; set; }
        public String CityCode { get; set; }
        public String BizRequestId { get; set; }
        public String OutBizNo { get; set; }
        public String ExchangeIds { get; set; }
        public String OperateTime { get; set; }
        public String BizInfoExt { get; set; }
        public String Amount { get; set; }
        public String StartStation { get; set; }
        public String EndStation { get; set; }
        public String Quantity { get; set; }
        public String TicketPrice { get; set; }

        public static String GetMethodName()
        {
            return "alipay.commerce.cityfacilitator.voucher.confirm";
        }
    }

    class VoucherConfirmResponse : OpenapiResponseBase
    {
        public String Amount { get; set; }
        public String StartStation { get; set; }
        public String EndStation { get; set; }
        public String Quantity { get; set; }
        public String Status { get; set; }
        public String TicketPrice { get; set; }
        public String StartStationName { get; set; }
        public String EndStationName { get; set; }    
    }

    class VoucherQueryRequest : OpenapiRequestBase
    {
        public String TicketNo { get; set; }
        public String TradeNo { get; set; }
        public String CityCode { get; set; }

        public static string GetMethodName()
        {
            return "alipay.commerce.cityfacilitator.voucher.query";
        }
    }

    class VoucherQueryResponse : OpenapiResponseBase
    {
        public String TradeNo { get; set; }
        public String Amount { get; set; }
        public String StartStation { get; set; }
        public String EndStation { get; set; }
        public String Quantity { get; set; }
        public String Status { get; set; }
        public String TicketPrice { get; set; }
        public String StartStationName { get; set; }
        public String EndStationName { get; set; }
       
    }

    class VoucherUploadRequest : OpenapiRequestBase
    {
        public String TicketNo { get; set; }
        public String TradeNo { get; set; }
        public String CityCode { get; set; }
        public String ExchangeIds { get; set; }
        public String BizInfoExt { get; set; }
        public String OperateTime { get; set; }


        public static string GetMethodName()
        {
            return "alipay.commerce.cityfacilitator.voucher.upload";
        }
    }

    class VoucherUploadResponse : OpenapiResponseBase
    {

    }
}
