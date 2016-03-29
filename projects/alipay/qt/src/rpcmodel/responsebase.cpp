#include "responsebase.h"

ResponseBase::ResponseBase()
{

}

void ResponseBase::fromOpenapiResponse(const OpenapiResponse& response)
{
    this->originalObject = response.getResult();
}



