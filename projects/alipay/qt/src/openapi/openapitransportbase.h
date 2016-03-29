#ifndef OPENAPITRANSPORTBASE_H
#define OPENAPITRANSPORTBASE_H

#include <QObject>
#include "openapirequest.h"
#include "openapiresponse.h"

class OpenapiTransportBase : public QObject
{
    Q_OBJECT
public:
    explicit OpenapiTransportBase(QObject *parent = 0);

    virtual OpenapiResponse* invoke(const OpenapiRequest& request) = 0;

public slots:
};

#endif // OPENAPITRANSPORTBASE_H
