#ifndef CANCELREQUEST_H
#define CANCELREQUEST_H

#include "requestbase.h"
#include "responsebase.h"
#include "cancelresponse.h"

class CancelRequest : public RequestBase
{
public:
    CancelRequest();

    QString getApiMethodName() const;
    QString getResponseName() const;

    JSON_PROPERTY(QString, OutTradeNo, out_trade_no)
};

#endif // CANCELREQUEST_H
