#ifndef CREATEANDPAYREQUEST_H
#define CREATEANDPAYREQUEST_H
#include "requestbase.h"
#include "createandpayresponse.h"

class GoodsInfo : public JsonObject
{
public:

    JSON_PROPERTY(QString, AlipayGoodsId, alipay_goods_id)
    JSON_PROPERTY(QString, Body, body)
    JSON_PROPERTY(QString, GoodsCategory, goods_category)
    JSON_PROPERTY(QString, GoodsId, goods_id)
    JSON_PROPERTY(QString, GoodsName, goods_name)
    JSON_PROPERTY(QString, Price, price)
    JSON_PROPERTY(QString, Quantity, quantity)
};

class RoyaltyDetailInfo : public JsonObject
{
public:
    JSON_PROPERTY(QString, Amount, amount)
    JSON_PROPERTY(QString, BatchNo, batch_no)
    JSON_PROPERTY(QString, Desc, desc)
    JSON_PROPERTY(QString, OutRelationId, out_relation_id)
    JSON_PROPERTY(QString, SerialNo, serial_no)
    JSON_PROPERTY(QString, TransIn, trans_in)
    JSON_PROPERTY(QString, TransInType, trans_in_type)
    JSON_PROPERTY(QString, TransOut, trans_out)
    JSON_PROPERTY(QString, TransOutType, trans_out_type)
};

class RoyaltyInfo : public JsonObject
{
public:
    JSON_PROPERTY(QString, RoyaltyType, royalty_type)
    JSON_LIST_PROPERTY(RoyaltyDetailInfo, RoyaltyDetailInfos, royalty_detail_infos)

};


class CreateAndPayRequest : public RequestBase
{
public:
    CreateAndPayRequest();
    QString getApiMethodName() const;
    QString getResponseName() const;

    JSON_PROPERTY(QString, OutTradeNo, out_trade_no)
    JSON_PROPERTY(QString, Scene, scene)
    JSON_PROPERTY(QString, AuthCode, auth_code)
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
    JSON_PROPERTY(QString, TimeoutExpress, timeout_express)

    //JSON_PROPERTY(RoyaltyInfo, RoyaltyInfo, royalty_info)
    JSON_LIST_PROPERTY(GoodsInfo, GoodsDetail, goods_detail)


};

#endif // CREATEANDPAYREQUEST_H
