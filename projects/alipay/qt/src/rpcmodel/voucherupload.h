#ifndef VOUCHERUPLOAD_H
#define VOUCHERUPLOAD_H

#include "requestbase.h"

class VoucherUploadRequest : public RequestBase
{
public:
    VoucherUploadRequest();

    JSON_PROPERTY(QString, TicketNo, ticket_no)
    JSON_PROPERTY(QString, TradeNo, trade_no)
    JSON_PROPERTY(QString, CityCode, city_code)
    JSON_PROPERTY(QString, ExchangeIds, exchange_ids)
    JSON_PROPERTY(QString, BizInfoExt, biz_info_ext)
    JSON_PROPERTY(QString, OperateTime, operate_time)

    QString getApiMethodName() const;

};

class VoucherUploadResponse : public ResponseBase
{
public:
    VoucherUploadResponse();

};


#endif // VOUCHERUPLOAD_H
