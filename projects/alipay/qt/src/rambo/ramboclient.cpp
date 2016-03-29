#include "ramboclient.h"

RamboClient::RamboClient(QString serialPort, int requestTimeout, QObject *parent)
    : QObject(parent)
{
    serialPortTransport = new SerialPortTransport(serialPort,this);
    this->requestTimeout = requestTimeout;

    connect(serialPortTransport,
            SIGNAL(received(QString)),
            SLOT(onSerialPortReceived(QString)));

    serialPortTransport->start();
}

RamboClient::~RamboClient()
{
    serialPortTransport->stop();
}

RamboResponse* RamboClient::invoke(const QString &rambo, const QVariantMap &parameters)
{
    QString id = QUuid::createUuid().toString();    

    RamboRequest request;
    request.setId(id);
    request.setRambo(rambo);
    request.setParameters(parameters);
    serialPortTransport->send(request.toString());

    RamboResponse *response = new RamboResponse();
    response->setId(id);

    if(requestTimeout != -1)
    {
        QTimer* timer = new QTimer(response);
        connect(timer, SIGNAL(timeout()), SLOT(onRequestTimeout()));
        timer->setInterval(requestTimeout);
        timer->start();
    }

    ramboResponseMap.insert(id, response);
    return response;
}

void RamboClient::onSerialPortReceived(QString data)
{
    RamboResponse responseData;
    responseData.fromString(data);
    QMap<QString, RamboResponse*>::iterator iter
            = ramboResponseMap.find(responseData.getId());
    if(iter == ramboResponseMap.end())
        return;

    RamboResponse* response = *iter;
    response->fromVariantMap(responseData.toVariantMap());
    emit finished(response);
    QMetaObject::invokeMethod(response, "finished");
    response->disconnect(response);
    response->deleteLater();
    ramboResponseMap.remove(response->getId());
}

void RamboClient::onRequestTimeout()
{
    QTimer* timer = (QTimer*)sender();
    RamboResponse* response = (RamboResponse*)timer->parent();

    QMap<QString, RamboResponse*>::iterator iter
            = ramboResponseMap.find(response->getId());
    if(iter == ramboResponseMap.end())
        return;

    if(serialPortTransport->driversEnable())
        response->setErrorCode(RamboResponse::Timeout);
    else
        response->setErrorCode(RamboResponse::DriversError);

    emit finished(response);
    QMetaObject::invokeMethod(response, "finished");
    response->disconnect(response);
    response->deleteLater();
    ramboResponseMap.remove(response->getId());
}
