#ifndef VOUCHERCONFIRMRESPONSE_H
#define VOUCHERCONFIRMRESPONSE_H
#include "responsebase.h"

class VoucherConfirmResponse : public ResponseBase
{
public:
    VoucherConfirmResponse();

    JSON_PROPERTY(QString, Amount, amount)
    JSON_PROPERTY(QString, StartStation, start_station)
    JSON_PROPERTY(QString, EndStation, end_station)
    JSON_PROPERTY(QString, Quantity, quantity)
    JSON_PROPERTY(QString, Status, status)
    JSON_PROPERTY(QString, TicketPrice, ticket_price)
    JSON_PROPERTY(QString, StartStationName, start_station_name)
    JSON_PROPERTY(QString, EndStationName, end_station_name)

    QString getResponseName() const;
};

#endif // VOUCHERCONFIRMRESPONSE_H
