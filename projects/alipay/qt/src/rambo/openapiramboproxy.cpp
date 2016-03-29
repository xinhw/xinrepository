#include "openapiramboproxy.h"
#include <QMetaObject>
OpenapiRamboProxy::OpenapiRamboProxy(RamboClient *ramboClient, QObject *parent) :
    OpenapiTransportBase(parent)
{
    this->ramboClient = ramboClient;
}

OpenapiResponse *OpenapiRamboProxy::invoke(const OpenapiRequest &request)
{
    RamboResponse* ramboResponse = ramboClient->invoke("OpenapiRambo", request.toVariantMap());
    connect(ramboResponse, SIGNAL(finished()), SLOT(onFinished()));
    OpenapiResponse* response = new OpenapiResponse(ramboResponse);
    return response;
}

void OpenapiRamboProxy::onFinished()
{
    RamboResponse* ramboResponse = (RamboResponse*)sender();
    OpenapiResponse* response = ramboResponse->findChild<OpenapiResponse*>(OpenapiResponse::staticMetaObject.className());
    qDebug() <<"OpenapiRamboProxy::onFinished()";
    qDebug() <<"rambo error=" << ramboResponse->getErrorCode();

    response->fromVariantMap(ramboResponse->getResult());
    qDebug() <<"transport error=" << response->getErrorCode();
    qDebug() <<"transport error string=" << response->getErrorString();
    emit finished(response);
    QMetaObject::invokeMethod(response, "finished");
}

