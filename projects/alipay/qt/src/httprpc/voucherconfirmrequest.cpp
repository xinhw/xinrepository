#include "voucherconfirmrequest.h"

VoucherConfirmRequest::VoucherConfirmRequest()
{

}

QString VoucherConfirmRequest::getApiMethodName() const
{
    return "alipay.commerce.cityfacilitator.voucher.confirm";
}
