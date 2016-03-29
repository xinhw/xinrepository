#ifndef VOUCHERQUERYRESPONSE_H
#define VOUCHERQUERYRESPONSE_H
#include "responsebase.h"

class VoucherQueryResponse : public ResponseBase
{
public:
    VoucherQueryResponse();

    JSON_PROPERTY(QString, TradeNo, trade_no)
    JSON_PROPERTY(QString, Amount, amount)
    JSON_PROPERTY(QString, StartStation, start_station)
    JSON_PROPERTY(QString, EndStation, end_station)
    JSON_PROPERTY(QString, Quantity, quantity)
    JSON_PROPERTY(QString, Status, status)
    JSON_PROPERTY(QString, TicketPrice, ticket_price)
    JSON_PROPERTY(QString, StartStationName, start_station_name)
    JSON_PROPERTY(QString, EndStationName, end_station_name)

};

#endif // VOUCHERQUERYRESPONSE_H
