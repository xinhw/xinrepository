#ifndef QUERYRESPONSE_H
#define QUERYRESPONSE_H
#include "responsebase.h"
#include "createandpayresponse.h"

class QueryResponse : public ResponseBase
{
public:
    QueryResponse();

    JSON_PROPERTY(QString, TradeNo, trade_no)
    JSON_PROPERTY(QString, OutTradeNo, out_trade_no)
    JSON_PROPERTY(QString, BuyerUserId, buyer_user_id)
    JSON_PROPERTY(QString, BuyerLogonId, buyer_logon_id)
    JSON_PROPERTY(QString, TotalAmount, total_amount)
    JSON_PROPERTY(QString, ReceiptAmount, receipt_amount)

    JSON_PROPERTY(QString, StoreName, store_name)
    JSON_PROPERTY(QString, StoreId, store_id)
    JSON_PROPERTY(QString, SendPayDate, send_pay_date)
    JSON_PROPERTY(QString, TerminalId, terminal_id)
    JSON_PROPERTY(QString, TradeStatus, trade_status)
    JSON_LIST_PROPERTY(FundBill, FundBillList, fund_bill_list)

};

#endif // QUERYRESPONSE_H
