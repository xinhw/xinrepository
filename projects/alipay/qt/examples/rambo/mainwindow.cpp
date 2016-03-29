#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../rpcmodel/voucherconfirm.h"

#include <QSslConfiguration>
#include <QSslCertificate>
#include "../../src/qextserialport/qextserialenumerator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ramboService(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir dir(QApplication::applicationDirPath());
    QSettings settings(dir.absoluteFilePath("openapi.ini"), QSettings::IniFormat);
    QString serialPort = settings.value("serial_port").toString();
    qDebug() << "serialPort=" <<serialPort;
    ramboService = new RamboService(serialPort, this);
    openapiRambo = new OpenapiRambo(this);
    ramboService->addRambo(openapiRambo);
    ramboService->start();

#if defined(Q_OS_LINUX)
    QSslConfiguration configuration = QSslConfiguration::defaultConfiguration();
    configuration.setCaCertificates(QSslCertificate::fromPath(dir.absoluteFilePath("cacert.pem")));
    QSslConfiguration::setDefaultConfiguration(configuration);
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendDebugString(const QString &msg)
{
    if(ui->plainTextEdit->document()->characterCount() > 65535)
    {
        ui->plainTextEdit->clear();
    }

    ui->plainTextEdit->appendPlainText(msg);
    ui->plainTextEdit->ensureCursorVisible();
}
