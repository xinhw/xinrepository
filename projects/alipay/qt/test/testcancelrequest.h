#ifndef TESTCANCELREQUEST_H
#define TESTCANCELREQUEST_H

#include <QObject>

#include "src/httprpc/openapisigner.h"
#include "src/httprpc/httprpctransport.h"
#include "src/httprpc/cancelrequest.h"

class TestCancelRequest : public QObject
{
    Q_OBJECT
public:
    explicit TestCancelRequest(QObject *parent = 0);

signals:

public slots:
    void onCancelFinished(ResponseBase*);
private slots:
    void initTestCase();

    void testRequest();

    void cleanupTestCase();
private:

    OpenapiSigner* openapiSigner;
    HttpRpcTransport* httpRpcTransport;

};

#endif // TESTCANCELREQUEST_H
