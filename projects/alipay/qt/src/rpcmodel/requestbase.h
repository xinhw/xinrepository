#ifndef REQUESTBASE_H
#define REQUESTBASE_H
#include "responsebase.h"
#include "../openapi/openapirequest.h"

class RequestBase : public JsonObject
{
public:
    RequestBase();
    OpenapiRequest toOpenapiRequest() const;
    virtual QString getApiMethodName() const = 0;
};

#endif // REQUESTBASE_H
