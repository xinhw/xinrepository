#ifndef RAMBOCLIENT_H
#define RAMBOCLIENT_H

#include <QtCore>
#include "ramboproxy.h"
#include "ramborequest.h"
#include "ramboresponse.h"
#include "../qextserialport/serialporttransport.h"

class RamboClient : public QObject
{
    Q_OBJECT
public:
    explicit RamboClient(QString serialPort, int requestTimeout = 3*60*1000 ,QObject *parent = 0);
    ~RamboClient();

    RamboResponse* invoke(const QString &rambo, const QVariantMap &parameters);

signals:

    void finished(RamboResponse* response);
public slots:
    void onSerialPortReceived(QString data);
    void onRequestTimeout();
private:

    QMap<QString, RamboResponse*> ramboResponseMap;
    SerialPortTransport* serialPortTransport;
    int requestTimeout;
};

#endif // RAMBOCLIENT_H
