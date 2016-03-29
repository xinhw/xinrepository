#ifndef RAMBOSERVICE_H
#define RAMBOSERVICE_H

#include <QtCore>
#include "rambobase.h"
#include "serialporttransport.h"

class RamboService : public QObject
{
    Q_OBJECT
public:
    explicit RamboService(QString serialPort, QObject *parent = 0);

    void start();
    void stop();

    void addRambo(RamboBase* rambo);

signals:

private slots:
    void onSerialPortReceived(QString data);
    void onRamboReply(QString id, QVariantMap json);
    void onRamboDestroyed(QObject *ramboObject);
public slots:

private:

    SerialPortTransport* serialPortTransport;
    QMap<QString, RamboBase*> rambosMap;
};

#endif // RAMBOSERVICE_H
