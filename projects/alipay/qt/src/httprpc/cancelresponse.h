#ifndef CANCELRESPONSE_H
#define CANCELRESPONSE_H
#include "responsebase.h"

class CancelResponse : public ResponseBase
{
public:
    CancelResponse();    

    JSON_PROPERTY(QString, TradeNo, trade_no)
    JSON_PROPERTY(QString, OutTradeNo, out_trade_no)
    JSON_PROPERTY(QString, RetryFlag, retry_flag)
    JSON_PROPERTY(QString, Action, action)
};

#endif // CANCELRESPONSE_H
