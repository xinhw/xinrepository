#include "requestbase.h"


RequestBase::RequestBase()
{

}

OpenapiRequest RequestBase::toOpenapiRequest() const
{
    OpenapiRequest request;
    request.setMethodName(this->getApiMethodName());
    request.setParameters(this->originalObject);
    return request;
}
