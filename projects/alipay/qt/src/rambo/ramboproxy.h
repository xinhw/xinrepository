#ifndef RAMBOPROXY_H
#define RAMBOPROXY_H

#include <QObject>
#include <QVariantMap>

class RamboProxy : public QObject
{
    Q_OBJECT
private:
    explicit RamboProxy(QObject *parent = 0);
    ~RamboProxy();

public:


signals:
    void reply(QVariantMap parameters);

private:
    QString id;
    QString rambo;

    friend class RamboClient;
};

#endif // RAMBOPROXY_H
