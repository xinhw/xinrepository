#ifndef PRECREATERESPONSE_H
#define PRECREATERESPONSE_H
#include "responsebase.h"

class PrecreateResponse : public ResponseBase
{
public:
    PrecreateResponse();

    JSON_PROPERTY(QString, OutTradeNo, out_trade_no)
    JSON_PROPERTY(QString, QrCode, qr_code)

};

#endif // PRECREATERESPONSE_H
