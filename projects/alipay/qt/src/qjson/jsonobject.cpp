#include "jsonobject.h"
#include "../../src/qjson/parser.h"
#include "../../src/qjson/serializer.h"

JsonObject::JsonObject()
{

}

JsonObject::JsonObject(const QString& data)
{
    fromString(data);
}

JsonObject::JsonObject(const QVariantMap& variantMap)
{
    this->originalObject = variantMap;
}

QString JsonObject::toString(bool indent) const
{
    return toJsonString(originalObject, indent);
}

QVariantMap JsonObject::toVariantMap() const
{
    return originalObject;
}

void JsonObject::fromString(const QString &data)
{
    originalObject = fromJsonString(data);
}

void JsonObject::fromVariantMap(const QVariantMap &variantMap)
{
    originalObject = variantMap;
}

QString JsonObject::toJsonString(const QVariantMap &jsonObject, bool indent)
{
    QJson::Serializer serializer;

    serializer.setIndentMode(indent? QJson::IndentFull : QJson::IndentNone);
    bool ok = false;
    QByteArray serialized = serializer.serialize(jsonObject, &ok);

    QStringList sl;
    QString serializedStr = QString::fromUtf8(serialized);

    int idx = 0;
    int lastIdx = 0;
    while((idx = serializedStr.indexOf("\\u", idx)) != -1)
    {
        if(idx != lastIdx)
            sl.append(serializedStr.mid(lastIdx, idx - lastIdx));
        QString strHex = serializedStr.mid(idx + 2, 4);
        int nHex = strHex.toInt(0, 16);
        sl.append(QString(QChar(nHex)));
        idx+=6;
        lastIdx = idx;
    }

    sl.append(serializedStr.mid(lastIdx, serializedStr.length() - lastIdx));

    return sl.join(QString());
}

QVariantMap JsonObject::fromJsonString(const QString& jsonString)
{
    QVariantMap originalObject;
    QJson::Parser parser;
    bool ok;
    originalObject = parser.parse( jsonString.toUtf8(), &ok ).toMap();
    return originalObject;
}

