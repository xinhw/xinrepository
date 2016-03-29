#include "precreaterequest.h"

PrecreateRequest::PrecreateRequest()
{

}

QString PrecreateRequest::getApiMethodName() const
{
    return "alipay.trade.precreate";
}

QString PrecreateRequest::getResponseName() const
{
    return "alipay_trade_precreate_response";
}

