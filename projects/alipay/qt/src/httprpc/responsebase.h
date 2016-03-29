#ifndef RESPONSEBASE_H
#define RESPONSEBASE_H
#include "../openapi/openapiresponse.h"

class ResponseBase : public JsonObject
{

public:

    ResponseBase();

    void fromOpenapiResponse(const OpenapiResponse& response);

    JSON_PROPERTY(QString, Code, code)
    JSON_PROPERTY(QString, Msg, msg)
    JSON_PROPERTY(QString, SubCode, sub_code)
    JSON_PROPERTY(QString, SubMsg, sub_msg)
    JSON_PROPERTY(int, NetworkErrorCode, NetworkErrorCode)
    JSON_PROPERTY(int, HttpCode, HttpCode)

    virtual QString getResponseName() const = 0;

};

#endif // RESPONSEBASE_H
