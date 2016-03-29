#ifndef OPENAPIRAMBOPROXY_H
#define OPENAPIRAMBOPROXY_H

#include <QObject>

#include "../../src/rambo/ramboclient.h"
#include "../../src/openapi/openapitransportbase.h"

class OpenapiRamboProxy : public OpenapiTransportBase
{
    Q_OBJECT
public:
    explicit OpenapiRamboProxy(RamboClient* ramboClient, QObject *parent = 0);

public slots:
    OpenapiResponse* invoke(const OpenapiRequest& request);
signals:
    void finished(OpenapiResponse* response);
private slots:
    void onFinished();
private:
    RamboClient* ramboClient;
};

#endif // OPENAPIRAMBOPROXY_H
