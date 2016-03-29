#ifndef OPENAPITRANSPORT_H
#define OPENAPITRANSPORT_H

#include <QtCore>
#include <QtNetwork>

#include "openapirequest.h"
#include "openapiresponse.h"
#include "openapisigner.h"
#include "openapitransportbase.h"

#define OPENAPI_TIME_OUT_CODE 600
#define OPENAPI_TIME_OUT_STRING "http transport timeout!"

class OpenapiTransport : public OpenapiTransportBase
{
    Q_OBJECT
public:
    explicit OpenapiTransport(QString openapiUrl,
                              QString mCloudMonitorUrl,
                              OpenapiSigner* openapiSigner,
                              int requestTimeout = 2* 60 * 1000,
                              QObject *parent = 0);
    ~OpenapiTransport();

    void setProxy(const QNetworkProxy& proxy);

public slots:
    OpenapiResponse* invoke(const OpenapiRequest& request);
signals:
    void finished(OpenapiResponse* response);

private slots:
    void onPostFinished(QNetworkReply* networkReply);

    void onTimeout();
    void onSslErrors(QNetworkReply* networkReply,const QList<QSslError> &sslErrors);

private:
    QByteArray urlEncoding(const QMap<QString, QString>& data);

private:
    QNetworkAccessManager networkAccessManager;
    OpenapiSigner* openapiSigner;
    QUrl openapiUrl;
    QUrl mCloudMonitorUrl;

    int requestTimeout;
};

#endif // OPENAPITRANSPORT_H
