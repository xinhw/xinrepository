#ifndef RAMBOBASE_H
#define RAMBOBASE_H
#include <QtCore>

class RamboBase : public QObject
{
    Q_OBJECT
public:
    explicit RamboBase(QObject *parent = 0);

    virtual void invoke(QString id, QVariantMap parameters) = 0;

signals:
    void reply(QString id, QVariantMap result);


    friend class RamboService;
};

#endif // RAMBOBASE_H
