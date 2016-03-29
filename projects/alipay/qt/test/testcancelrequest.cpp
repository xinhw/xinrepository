#include "testcancelrequest.h"
#include <QTest>

TestCancelRequest::TestCancelRequest(QObject *parent) : QObject(parent)
{

}

void TestCancelRequest::initTestCase()
{
    openapiSigner = new OpenapiSigner("2015110900742485", ":/rsa_private_key.pem", this);
    httpRpcTransport = new HttpRpcTransport(openapiSigner, this);

    httpRpcTransport->setProxy(QNetworkProxy(QNetworkProxy::HttpProxy, "127.0.0.1", 8888));
}

void TestCancelRequest::testRequest()
{
    CancelRequest request;
    request.setOutTradeNo("ttttt");

    CancelResponse* response = (CancelResponse*)httpRpcTransport->post(request);

    connect(httpRpcTransport, SIGNAL(finished(ResponseBase*)), SLOT(onCancelFinished(ResponseBase*)));

    QEventLoop loop;
    QTimer::singleShot(90 * 1000, &loop, SLOT(quit()));
    QObject::connect(httpRpcTransport, SIGNAL(finished(ResponseBase*)), &loop, SLOT(quit()));

    loop.exec();


}

void TestCancelRequest::onCancelFinished(ResponseBase*)
{


}

void TestCancelRequest::cleanupTestCase()
{

}


