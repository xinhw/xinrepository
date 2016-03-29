#ifndef OPENAPIREQUEST_H
#define OPENAPIREQUEST_H
#include "../qjson/jsonobject.h"

class OpenapiRequest : public JsonObject
{
public:
    OpenapiRequest();

    JSON_PROPERTY(QString, MethodName, method_name)
    JSON_PROPERTY(QVariantMap, Parameters, parameters)
};

#endif // OPENAPIREQUEST_H
