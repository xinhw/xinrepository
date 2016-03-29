#ifndef VOUCHERUPLOADRESPONSE_H
#define VOUCHERUPLOADRESPONSE_H
#include "responsebase.h"

class VoucherUploadResponse : public ResponseBase
{
public:
    VoucherUploadResponse();

    QString getResponseName() const;
};

#endif // VOUCHERUPLOADRESPONSE_H
