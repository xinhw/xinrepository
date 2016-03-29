#include "requestbase.h"


RequestBase::RequestBase()
{

}

OpenapiRequest RequestBase::toOpenapiRequest()
{
    OpenapiRequest request;
    request.setApiMethodName(this->getApiMethodName());
    request.setBizContent(this->originalObject);
}
