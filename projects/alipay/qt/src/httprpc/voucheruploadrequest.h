#ifndef VOUCHERUPLOADREQUEST_H
#define VOUCHERUPLOADREQUEST_H
#include "requestbase.h"
#include "voucheruploadresponse.h"

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

#endif // VOUCHERUPLOADREQUEST_H
