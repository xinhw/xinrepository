#ifndef OPENAPISIGNER_H
#define OPENAPISIGNER_H
#include <QObject>
#include <QMap>
#include "opensslrsawrapper.h"

class OpenapiSigner : QObject
{
    Q_OBJECT
public:
    OpenapiSigner(const QString& appId, const QString& privateKeyPath, QObject* parent = 0);
    void sign(QMap<QString, QString> &data);

    QString GetSignContent(const QMap<QString, QString>& data);

private:
    QString appId;
    OpensslRsaWrapper opensslRsaWrapper;
};

#endif // OPENAPISIGNER_H
