#include "createandpayrequest.h"

CreateAndPayRequest::CreateAndPayRequest()
{

}

QString CreateAndPayRequest::getApiMethodName() const
{
    return "alipay.trade.pay";
}

QString CreateAndPayRequest::getResponseName() const
{
    return "alipay_trade_pay_response";
}



