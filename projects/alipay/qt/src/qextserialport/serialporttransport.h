#ifndef SERIALPORTTRANSPORT_H
#define SERIALPORTTRANSPORT_H

#include <QObject>
#include "qextserialport.h"

class SerialPortTransport : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortTransport(QString name, QObject *parent = 0);

    void start();
    void stop();

    bool driversEnable();

public slots:
    void send(QString data);
signals:
    void received(QString);

private slots:
    void onReadyRead();
    void onDsrChanged(bool);
private:

    QextSerialPort *serialPort;
    QByteArray endBytes;

    QByteArray readingBuffer;

    bool driversStatus;
};

#endif // SERIALPORTTRANSPORT_H
