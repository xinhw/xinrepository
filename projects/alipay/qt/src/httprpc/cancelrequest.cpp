#include "cancelrequest.h"

CancelRequest::CancelRequest()
{

}

QString CancelRequest::getApiMethodName() const
{
    return "alipay.trade.cancel";
}

QString CancelRequest::getResponseName() const
{
    return "alipay_trade_cancel_response";
}
