#include "refundrequest.h"

RefundRequest::RefundRequest()
{

}

QString RefundRequest::getApiMethodName() const
{
    return "alipay.trade.refund";
}

QString RefundRequest::getResponseName() const
{
    return "alipay_trade_fefund_response";
}
