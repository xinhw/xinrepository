#ifndef VOUCHERCONFIRMREQUEST_H
#define VOUCHERCONFIRMREQUEST_H
#include "requestbase.h"

class VoucherConfirmRequest : public RequestBase
{
public:
    VoucherConfirmRequest();

    JSON_PROPERTY(QString, TicketNo, ticket_no)
    JSON_PROPERTY(QString, TradeNo, trade_no)
    JSON_PROPERTY(QString, CityCode, city_code)
    JSON_PROPERTY(QString, BizRequestId, biz_request_id)
    JSON_PROPERTY(QString, OutBizNo, out_biz_no)
    JSON_PROPERTY(QString, ExchangeIds, exchange_ids)
    JSON_PROPERTY(QString, OperateTime, operate_time)
    JSON_PROPERTY(QVariantMap, BizInfoExt, biz_info_ext)
    JSON_PROPERTY(QString, Amount, amount)
    JSON_PROPERTY(QString, StartStation, start_station)
    JSON_PROPERTY(QString, EndStation, end_station)
    JSON_PROPERTY(QString, Quantity, quantity)
    JSON_PROPERTY(QString, TicketPrice, ticket_price)

    QString getApiMethodName() const;    

};

#endif // VOUCHERCONFIRMREQUEST_H
