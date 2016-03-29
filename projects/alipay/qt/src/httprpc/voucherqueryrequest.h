#ifndef VOUCHERQUERYREQUEST_H
#define VOUCHERQUERYREQUEST_H
#include "requestbase.h"
#include "voucherqueryresponse.h"

class VoucherQueryRequest : public RequestBase
{
public:
    VoucherQueryRequest();

    JSON_PROPERTY(QString, TicketNo, ticket_no)
    JSON_PROPERTY(QString, TradeNo, trade_no)
    JSON_PROPERTY(QString, CityCode, city_code)

    QString getApiMethodName() const;
    QString getResponseName() const;


};

#endif // VOUCHERQUERYREQUEST_H
