#ifndef REFUNDREQUEST_H
#define REFUNDREQUEST_H
#include "requestbase.h"
#include "refundresponse.h"

class RefundRequest : public RequestBase
{
public:
    RefundRequest();

    QString getApiMethodName() const;
    QString getResponseName() const;

    JSON_PROPERTY(QString, OutRequestNo, out_request_no)
    JSON_PROPERTY(QString, RefundAmount, refund_amount)
    JSON_PROPERTY(QString, RefundReason, refund_reason)
    JSON_PROPERTY(QString, StoreId, store_id)
    JSON_PROPERTY(QString, TerminalId, terminal_id)

};

#endif // REFUNDREQUEST_H
