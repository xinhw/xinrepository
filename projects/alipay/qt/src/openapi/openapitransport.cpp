#include "openapitransport.h"


OpenapiTransport::OpenapiTransport(QString openapiUrl, QString mCloudMonitorUrl, OpenapiSigner *openapiSigner, int requestTimeout, QObject *parent) :
    OpenapiTransportBase(parent)
{
    this->openapiSigner = openapiSigner;
    this->requestTimeout = requestTimeout;
    this->openapiUrl = QUrl(openapiUrl);
    this->mCloudMonitorUrl = QUrl(mCloudMonitorUrl);

    connect(&networkAccessManager, SIGNAL(finished(QNetworkReply*)), SLOT(onPostFinished(QNetworkReply*)));
    connect(&networkAccessManager,
            SIGNAL(sslErrors(QNetworkReply*,const QList<QSslError> &)),
            SLOT(onSslErrors(QNetworkReply*,const QList<QSslError> &)));    
}

OpenapiTransport::~OpenapiTransport()
{

}

void OpenapiTransport::setProxy(const QNetworkProxy &proxy)
{
    networkAccessManager.setProxy(proxy);
}

OpenapiResponse* OpenapiTransport::invoke(const OpenapiRequest& request)
{
    qDebug()<< "OpenapiTransport::invoke()" << request.toString();

    QMap<QString,QString> requestContent;

    requestContent.insert("charset", "utf-8");
    requestContent.insert("method", request.getMethodName());
    requestContent.insert("timestamp", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    requestContent.insert("version", "1.0");
    requestContent.insert("biz_content", JsonObject::toJsonString(request.getParameters()));

    openapiSigner->sign(requestContent);
    QNetworkRequest networkRequest;

    if(request.getMethodName() == "monitor.heartbeat.syn")
    {
        networkRequest.setUrl(mCloudMonitorUrl);
    }
    else
    {
        networkRequest.setUrl(openapiUrl);
    }
    networkRequest.setRawHeader("Content-type", "application/x-www-form-urlencoded;charset=UTF-8");
    networkRequest.setRawHeader("Accept", "text/html, application/xhtml+xml, */*");

    QNetworkReply* networkReply = networkAccessManager.post(networkRequest, urlEncoding(requestContent));

    QString resultName = request.getMethodName();
    resultName.append("_response");
    resultName.replace('.', '_');

    OpenapiResponse* response = new OpenapiResponse(networkReply);
    response->setResultName(resultName);

    QTimer *timer = new QTimer(response);
    timer->setInterval(requestTimeout);
    timer->start();

    connect(timer, SIGNAL(timeout()), SLOT(onTimeout()));
    connect(networkReply, SIGNAL(finished()), response, SIGNAL(finished()));
    return response;    
}

void OpenapiTransport::onPostFinished(QNetworkReply* networkReply)
{
    OpenapiResponse* response =
            networkReply->findChild<OpenapiResponse*>(OpenapiResponse::staticMetaObject.className());
    QTimer* timer = (QTimer*)response->children().at(0);
    timer->stop();

    QByteArray responseData;
    QString responseString;
    if(networkReply->error() == QNetworkReply::NoError)
    {
        responseData = networkReply->readAll();
        responseString = QString::fromUtf8(responseData);
        QVariantMap responseObject = JsonObject::fromJsonString(responseString);
        QVariantMap result = responseObject.value(response->getResultName()).toMap();
        response->setResult(result);
    }

    response->setErrorCode(networkReply->error());
    response->setErrorString(networkReply->errorString());

    qDebug()<< "OpenapiTransport::onPostFinished()" << responseString;
    emit finished(response);
    response->deleteLater();
}

void OpenapiTransport::onTimeout()
{
    QTimer* timer = (QTimer*)sender();
    timer->stop();
    OpenapiResponse* response = (OpenapiResponse*)timer->parent();
    QNetworkReply* networkReply = (QNetworkReply*)response->parent();
    networkReply->abort();
}

void OpenapiTransport::onSslErrors(QNetworkReply *networkReply, const QList<QSslError> &sslErrors)
{
    qDebug() << sslErrors;
}

QByteArray OpenapiTransport::urlEncoding(const QMap<QString, QString>& data)
{
    QByteArray resultData;
    QMap<QString, QString>::const_iterator iter;

    for(iter = data.constBegin(); iter != data.constEnd(); ++iter)
    {
        resultData.append(iter.key().toUtf8().toPercentEncoding());
        resultData.append('=');
        resultData.append(iter.value().toUtf8().toPercentEncoding());
        resultData.append('&');
    }

    if(!resultData.isEmpty())
    {
        resultData.remove(resultData.length()-1, 1);
    }

    return resultData;
}

