#ifndef REFUNDRESPONSE_H
#define REFUNDRESPONSE_H
#include "responsebase.h"
#include "createandpayresponse.h"

class RefundResponse : public ResponseBase
{
public:
    RefundResponse();

    JSON_PROPERTY(QString, TradeNo, trade_no)
    JSON_PROPERTY(QString, OutTradeNo, out_trade_no)
    JSON_PROPERTY(QString, BuyerUserId, buyer_user_id)
    JSON_PROPERTY(QString, BuyerLogonId, buyer_logon_id)
    JSON_PROPERTY(QString, FundChange, fund_change)
    JSON_PROPERTY(QString, RefundFee, refund_fee)
    JSON_PROPERTY(QString, SendBackFee, send_back_fee)
    JSON_PROPERTY(QString, GmtRefundPay, gmt_refund_pay)
    JSON_PROPERTY(QString, StoreName, store_name)
    JSON_LIST_PROPERTY(FundBill, RefundDetailItemList, refund_detail_item_list)

};

#endif // REFUNDRESPONSE_H
