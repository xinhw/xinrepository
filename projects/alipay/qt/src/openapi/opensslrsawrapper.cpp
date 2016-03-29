#include "opensslrsawrapper.h"

OpensslRsaWrapper::OpensslRsaWrapper()
{
    pkey = NULL;
}

OpensslRsaWrapper::OpensslRsaWrapper(const QByteArray &privateKey)
{
    pkey = NULL;
    setPrivateKey(privateKey);
}

OpensslRsaWrapper::~OpensslRsaWrapper()
{
    if(pkey != NULL) EVP_PKEY_free(pkey);
}

void OpensslRsaWrapper::setPrivateKey(const QByteArray& privateKey)
{
    pkey = EVP_PKEY_new();

    BIO *bio;
    bio = BIO_new_mem_buf((void*)privateKey.data(), privateKey.length());

    EVP_PKEY* ret = PEM_read_bio_PrivateKey(bio, &pkey, 0, 0);
    BIO_free_all(bio);
}

QString OpensslRsaWrapper::sign(const QByteArray& message)
{
    int err;
    unsigned int sig_len = 4096;
    QByteArray sig_buf(sig_len, '\0');

    EVP_MD_CTX md_ctx;

    EVP_SignInit(&md_ctx, EVP_sha1());
    EVP_SignUpdate(&md_ctx, message.data(), message.length());

    err = EVP_SignFinal(&md_ctx, (unsigned char *)sig_buf.data(), &sig_len, pkey);

    if(err != 1)
        return QString();

    sig_buf.resize(sig_len);
    return sig_buf.toBase64();
}
