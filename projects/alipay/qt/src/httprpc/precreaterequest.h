#ifndef PRECREATEREQUEST_H
#define PRECREATEREQUEST_H
#include "responsebase.h"
#include "createandpayrequest.h"
#include "precreateresponse.h"

class PrecreateRequest : public RequestBase
{
public:
    PrecreateRequest();

    QString getApiMethodName() const;
    QString getResponseName() const;

    JSON_PROPERTY(QString, OutTradeNo, out_trade_no)
    JSON_PROPERTY(QString, SellerId, seller_id)
    JSON_PROPERTY(QString, TotalAmount, total_amount)
    JSON_PROPERTY(QString, DiscountableAmount, discountable_amount)
    JSON_PROPERTY(QString, UndiscountableAmount, undiscountable_amount)
    JSON_PROPERTY(QString, Subject, subject)
    JSON_PROPERTY(QString, Body, body)
    JSON_PROPERTY(QString, OperatorId, operator_id)
    JSON_PROPERTY(QString, StoreId, store_id)
    JSON_PROPERTY(QString, TerminalId, terminal_id)
    JSON_PROPERTY(QString, ExtendParams, extend_params)
    JSON_PROPERTY(QString, TimeExpire, time_expire)


    //JSON_PROPERTY(RoyaltyInfo, RoyaltyInfo, royalty_info)
    JSON_LIST_PROPERTY(GoodsInfo, GoodsDetail, goods_detail)

};

#endif // PRECREATEREQUEST_H
