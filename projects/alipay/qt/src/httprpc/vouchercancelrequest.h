#ifndef VOUCHERCANCELREQUEST_H
#define VOUCHERCANCELREQUEST_H
#include "requestbase.h"
#include "vouchercancelresponse.h"

class VoucherCancelRequest : public RequestBase
{
public:
    VoucherCancelRequest();

    JSON_PROPERTY(QString, TradeNo, trade_no)
    JSON_PROPERTY(QString, TicketNo, ticket_no)
    JSON_PROPERTY(QString, CityCode, city_code)
    JSON_PROPERTY(QString, OperateTime, operate_time)
    JSON_PROPERTY(QVariantMap, BizInfoExt, biz_info_ext)



    QString getApiMethodName() const;
    QString getResponseName() const;


};

#endif // VOUCHERCANCELREQUEST_H
