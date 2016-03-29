#include "openapisigner.h"
#include <QFile>

OpenapiSigner::OpenapiSigner(const QString& appId, const QString& privateKeyPath, QObject *parent):
    QObject(parent)
{
    this->appId = appId;

    QFile file(privateKeyPath);

    if(file.open(QFile::ReadOnly))
    {
        QByteArray privateKeyData = file.readAll();
        opensslRsaWrapper.setPrivateKey(privateKeyData);
        file.close();
    }
}

void OpenapiSigner::sign(QMap<QString, QString>& data)
{
    data.insert("app_id", appId);
    data.insert("sign_type", "RSA");

    QString signContent = GetSignContent(data);
    QString sign = opensslRsaWrapper.sign(signContent.toUtf8());

    data.insert("sign", sign);
}

QString OpenapiSigner::GetSignContent(const QMap<QString, QString>& data)
{
    QMap<QString, QString> ::const_iterator iter;
    QStringList sb;
    for(iter = data.constBegin(); iter != data.constEnd(); ++iter)
    {
        sb.append(QString("%1=%2").arg(iter.key(), iter.value()));
    }

    return sb.join("&");
}
