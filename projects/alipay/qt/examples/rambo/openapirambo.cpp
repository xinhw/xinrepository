#include "openapirambo.h"
#include <QApplication>

OpenapiRambo::OpenapiRambo(QObject *parent) : RamboBase(parent)
{
    QDir dir(QApplication::applicationDirPath());
    QSettings settings(dir.absoluteFilePath("openapi.ini"), QSettings::IniFormat);

    QString appId = settings.value("app_id").toString();
    QString openApiUrl = settings.value("open_api_url", "https://openapi.alipay.com/gateway.do").toString();
    QString mCloudMonitorUrl = settings.value("m_cloud_monitor_url", "http://mcloudmonitor.com/gateway.do").toString();

    int requestTimeout = settings.value("request_timeout", 90*1000).toInt();
    QString proxy = settings.value("proxy").toString();

    qDebug() << "appId = " << appId;
    qDebug() << "openApiUrl = " << openApiUrl;
    qDebug() << "mCloudMonitorUrl = " << mCloudMonitorUrl;
    qDebug() << "proxy = " << proxy;

    openapiSigner = new OpenapiSigner(appId, dir.absoluteFilePath("openapi.ini"), this);
    openapiTransport = new OpenapiTransport(openApiUrl, mCloudMonitorUrl, openapiSigner, requestTimeout, this);
    connect(openapiTransport,
            SIGNAL(finished(OpenapiResponse*)),
            SLOT(onOpenapiTransportFinished(OpenapiResponse*)));

    if(!proxy.isEmpty())
    {
        QStringList sl = proxy.split(':');
        openapiTransport->setProxy(QNetworkProxy(QNetworkProxy::HttpProxy, sl[0], sl[1].toInt()));
    }
}

void OpenapiRambo::invoke(QString id, QVariantMap parameters)
{
    OpenapiRequest request = JsonObject::fromVariantMap<OpenapiRequest>(parameters);
    OpenapiResponse* response = openapiTransport->invoke(request);

    openapiResponseMap[response] = id;
}

void OpenapiRambo::onOpenapiTransportFinished(OpenapiResponse *response)
{
    QString id = openapiResponseMap[response];
    emit this->reply(id, response->toVariantMap());
    openapiResponseMap.remove(response);
}

