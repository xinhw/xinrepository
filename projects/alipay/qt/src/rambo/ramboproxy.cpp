#include "ramboproxy.h"

RamboProxy::RamboProxy(QObject *parent) : QObject(parent)
{

}

RamboProxy::~RamboProxy()
{

}

void RamboProxy::invoke(const QVariantMap &parameters)
{
    emit internalInvoke(parameters);
}

