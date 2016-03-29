#ifndef RAMBOREQUEST_H
#define RAMBOREQUEST_H
#include "../qjson/jsonobject.h"

class RamboRequest : public JsonObject
{
public:

    JSON_PROPERTY(QString, Rambo, rambo)
    JSON_PROPERTY(QString, Id, id)
    JSON_PROPERTY(QVariantMap, Parameters, parameters)
};

#endif // RAMBOREQUEST_H
