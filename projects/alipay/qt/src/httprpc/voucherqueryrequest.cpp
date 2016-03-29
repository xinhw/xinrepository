#include "voucherqueryrequest.h"

VoucherQueryRequest::VoucherQueryRequest()
{

}

QString VoucherQueryRequest::getApiMethodName() const
{
    return "alipay.commerce.cityfacilitator.voucher.query";
}

QString VoucherQueryRequest::getResponseName() const
{
    return "alipay_commerce_cityfacilitator_voucher_query_response ";
}

