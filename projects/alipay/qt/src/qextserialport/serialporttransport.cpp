#include "serialporttransport.h"
#include <QDebug>

SerialPortTransport::SerialPortTransport(QString name, QObject *parent) :
    driversStatus(false),
    QObject(parent)
{
    serialPort = new QextSerialPort(name.toLatin1(), QextSerialPort::EventDriven);
    serialPort->setBaudRate(BAUD115200);
    serialPort->setFlowControl(FLOW_OFF);
    serialPort->setParity(PAR_NONE);
    serialPort->setDataBits(DATA_8);
    serialPort->setStopBits(STOP_1);
    endBytes = QByteArray("\0", 1);
}

void SerialPortTransport::start()
{
    if (serialPort->open(QIODevice::ReadWrite) == true) {
        connect(serialPort, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        connect(serialPort, SIGNAL(dsrChanged(bool)), this, SLOT(onDsrChanged(bool)));
        if (!(serialPort->lineStatus() & LS_DSR))
            qDebug() << "warning: device is not turned on";
        qDebug() << "listening for data on" << serialPort->portName();
    }
    else {
        qDebug() << "device failed to open:" << serialPort->errorString();
    }
}

void SerialPortTransport::stop()
{
    serialPort->close();
}

bool SerialPortTransport::driversEnable()
{
    return driversStatus;
}

void SerialPortTransport::send(QString data)
{
    qDebug() << "SerialPortTransport::send()";
    qDebug() << data;
    serialPort->write(data.toUtf8());
    serialPort->write(endBytes);
}

void SerialPortTransport::onReadyRead()
{
    qDebug() << "SerialPortTransport::onReadyRead()";
    QByteArray bytes;
    int a = serialPort->bytesAvailable();
    bytes.resize(a);
    serialPort->read(bytes.data(), bytes.size());
    int curPos = 0;
    for(int i =0; i< bytes.length(); ++i)
    {
        if(bytes[i] == '\0')
        {
            QByteArray messageBytes = bytes.mid(curPos, i - curPos);

            if(readingBuffer.length() != 0)
            {
                messageBytes.prepend(readingBuffer);
                readingBuffer.clear();
            }
            curPos = i + 1;
            if(messageBytes.length() != 0)
            {
                qDebug() << QString::fromUtf8(messageBytes);
                emit received(QString::fromUtf8(messageBytes));
            }
        }
    }

    if(curPos != bytes.length() + 1)
        readingBuffer.append(bytes.mid(curPos));
}

void SerialPortTransport::onDsrChanged(bool status)
{
    if(!status)
    {
        readingBuffer.clear();
    }

    driversStatus = status;
}

