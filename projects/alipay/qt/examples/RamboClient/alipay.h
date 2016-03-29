#ifndef ALIPAY_H
#define ALIPAY_H

#include <QObject>
#include "../../src/openapi/openapitransportbase.h"

class Alipay : public QObject
{
    Q_OBJECT
public:
    explicit Alipay(OpenapiTransportBase *openapiTransport, QObject *parent = 0);



signals:

public slots:

private:
    OpenapiTransportBase *openapiTransport;
};

#endif // ALIPAY_H
