#include "mainwindow.h"
#include <QApplication>

MainWindow* gw = 0;

void debugMessageDisplayFunc(QtMsgType type, const char *msg)
{
    const char* msgTypeStr = NULL;
    switch (type) {
    case QtDebugMsg:
        msgTypeStr = "Debug";
        break;
    case QtWarningMsg:
        msgTypeStr = "Warning";
        break;
    case QtCriticalMsg:
        msgTypeStr = "Critical";
        break;
    case QtFatalMsg:
        msgTypeStr = "Fatal";
    default:
        return;
    }
    QTime now = QTime::currentTime();
    QString formattedMessage =
            QString::fromLatin1("%1 %2 %3")
            .arg(now.toString("hh:mm:ss:zzz"))
            .arg(msgTypeStr).arg(QString::fromLocal8Bit(msg));

    if(gw!= NULL)
    {
        gw->appendDebugString(formattedMessage);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    gw = &w;
    //qInstallMsgHandler(debugMessageDisplayFunc);

    return a.exec();
}
