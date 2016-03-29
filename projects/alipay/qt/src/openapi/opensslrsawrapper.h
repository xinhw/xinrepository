#ifndef OPENSSLRSAWRAPPER_H
#define OPENSSLRSAWRAPPER_H
#include <QtCore>

#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/objects.h>
#include <openssl/x509.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>

class OpensslRsaWrapper
{
public:
    OpensslRsaWrapper();
    OpensslRsaWrapper(const QByteArray& privateKey);
    ~OpensslRsaWrapper();

    void setPrivateKey(const QByteArray& privateKey);

    QString sign(const QByteArray& message);

private:
    EVP_PKEY* pkey;
};

#endif // OPENSSLRSAWRAPPER_H
