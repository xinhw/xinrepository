#include "alipay.h"

Alipay::Alipay(OpenapiTransportBase *openapiTransport, QObject *parent) : QObject(parent)
{
    this->openapiTransport = openapiTransport;


}

