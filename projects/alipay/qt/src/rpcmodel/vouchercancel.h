#ifndef VOUCHERCANCEL_H
#define VOUCHERCANCEL_H
#include "requestbase.h"

class VoucherCancelRequest : public RequestBase
{
public:
    VoucherCancelRequest();

    JSON_PROPERTY(QString, TradeNo, trade_no)
    JSON_PROPERTY(QString, TicketNo, ticket_no)
    JSON_PROPERTY(QString, CityCode, city_code)
    JSON_PROPERTY(QString, OperateTime, operate_time)
    JSON_PROPERTY(QString, BizInfoExt, biz_info_ext)

    QString getApiMethodName() const;
};

class VoucherCancelResponse : public ResponseBase
{
public:
    VoucherCancelResponse();
};



#endif // VOUCHERCANCEL_H
