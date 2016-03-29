#include "ramboservice.h"
#include "ramborequest.h"
#include "ramboresponse.h"

RamboService::RamboService(QString serialPort, QObject *parent) : QObject(parent)
{
    serialPortTransport = new SerialPortTransport(serialPort, this);
    connect(serialPortTransport, SIGNAL(received(QString)), SLOT(onSerialPortReceived(QString)));
}

void RamboService::start()
{
    serialPortTransport->start();
}

void RamboService::stop()
{
    serialPortTransport->stop();
}

void RamboService::addRambo(RamboBase* rambo)
{
    connect(rambo, SIGNAL(reply(QString,QVariantMap)), SLOT(onRamboReply(QString,QVariantMap)));
    connect(rambo, SIGNAL(destroyed(QObject*)), SLOT(onRamboDestroyed(QObject*)));

    rambosMap.insert(rambo->metaObject()->className(), rambo);
}

void RamboService::onRamboReply(QString id, QVariantMap json)
{
    RamboResponse response;

    response.setId(id);
    response.setResult(json);

    serialPortTransport->send(response.toString());
}

void RamboService::onRamboDestroyed(QObject *ramboObject)
{
    QString id = ramboObject->objectName();
    rambosMap.remove(id);
}

void RamboService::onSerialPortReceived(QString data)
{
    RamboRequest ramboRequest = JsonObject::fromJsonString<RamboRequest>(data);

    QMap<QString, RamboBase*>::iterator iter
            = rambosMap.find(ramboRequest.getRambo());

    if(iter == rambosMap.end())
    {
        RamboResponse response;
        response.setId(ramboRequest.getId());
        response.setErrorCode(RamboResponse::InternalError);
        serialPortTransport->send(response.toString());
        return;
    }

    RamboBase* rambo = iter.value();
    rambo->invoke(ramboRequest.getId(), ramboRequest.getParameters());
}

