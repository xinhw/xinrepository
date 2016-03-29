#include "vouchercancelrequest.h"

VoucherCancelRequest::VoucherCancelRequest()
{

}


QString VoucherCancelRequest::getApiMethodName() const
{
    return "alipay.commerce.cityfacilitator.voucher.cancel";
}

QString VoucherCancelRequest::getResponseName() const
{
    return "alipay_commerce_cityfacilitator_voucher_cancel_response";
}
