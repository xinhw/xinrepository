#ifndef CREATEANDPAYRESPONSE_H
#define CREATEANDPAYRESPONSE_H
#include "responsebase.h"


class FundBill : public JsonObject
{
public:
    JSON_PROPERTY(QString, FundChannel, fund_channel)
    JSON_PROPERTY(QString, Amount, amount)
};

class CreateAndPayResponse : public ResponseBase
{
public:
    CreateAndPayResponse();

    JSON_PROPERTY(QString, TradeNo, trade_no)
    JSON_PROPERTY(QString, OutTradeNo, out_trade_no)
    JSON_PROPERTY(QString, BuyerUserId, buyer_user_id)
    JSON_PROPERTY(QString, BuyerLogonId, buyer_logon_id)
    JSON_PROPERTY(QString, TotalAmount, total_amount)
    JSON_PROPERTY(QString, ReceiptAmount, receipt_amount)
    JSON_PROPERTY(QString, InvoiceAmount, invoice_amount)
    JSON_PROPERTY(QString, BuyerPayAmount, buyer_pay_amount)
    JSON_PROPERTY(QString, PointAmount, point_amount)
    JSON_PROPERTY(QString, GmtPayment, gmt_payment)
    JSON_PROPERTY(QString, StoreName, store_name)
    JSON_LIST_PROPERTY(FundBill, FundBillList, fund_bill_list)

};

#endif // CREATEANDPAYRESPONSE_H
