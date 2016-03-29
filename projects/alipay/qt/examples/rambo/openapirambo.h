#ifndef OPENAPIRAMBO_H
#define OPENAPIRAMBO_H

#include "../../src/rambo/rambobase.h"
#include "../../src/openapi/openapitransport.h"

class OpenapiRambo : public RamboBase
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit OpenapiRambo(QObject *parent = 0);

    void invoke(QString id, QVariantMap parameters);

signals:

public slots:
    void onOpenapiTransportFinished(OpenapiResponse* response);

private:
    OpenapiSigner* openapiSigner;
    OpenapiTransport* openapiTransport;
    QMap<OpenapiResponse*,QString> openapiResponseMap;
};

#endif // OPENAPIRAMBO_H
