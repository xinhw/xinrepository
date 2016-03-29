#ifndef OPENAPIRESPONSE_H
#define OPENAPIRESPONSE_H
#include "../qjson/jsonobject.h"

class OpenapiResponse : public QObject, public JsonObject
{
    Q_OBJECT
public:
    explicit OpenapiResponse(QObject *parent = 0);

    JSON_PROPERTY(int, ErrorCode, error_code)
    JSON_PROPERTY(QString, ErrorString, error_string)
    JSON_PROPERTY(QString, ResultName, result_name)
    JSON_PROPERTY(QVariantMap, Result, result)

signals:
    void finished();
};

#endif // OPENAPIRESPONSE_H
