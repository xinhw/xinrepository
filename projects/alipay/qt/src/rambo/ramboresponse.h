#ifndef RAMBORESPONSE_H
#define RAMBORESPONSE_H
#include "../qjson/jsonobject.h"

class RamboResponse : public QObject, public JsonObject
{
    Q_OBJECT
    Q_ENUMS(RamboError)
public:
    explicit RamboResponse(QObject* parent = 0);

    enum RamboError{NoError,DriversError,Timeout,InternalError};

    JSON_PROPERTY(QString, Id, id)
    JSON_PROPERTY(int, ErrorCode, error_code)
    JSON_PROPERTY(QVariantMap, Result, result)

signals:
    void finished();
};

#endif // RAMBORESPONSE_H
