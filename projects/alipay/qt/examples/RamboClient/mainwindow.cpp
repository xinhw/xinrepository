#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QHostInfo>

#include "../../src/rpcmodel/voucherconfirm.h"
#include "../../src/rpcmodel/voucherquery.h"
#include "../../src/rpcmodel/voucherupload.h"
#include "../../src/rpcmodel/vouchercancel.h"
#include "../../src/qextserialport/qextserialenumerator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ramboClient(0),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
    foreach (QextPortInfo info, ports)
    {
        ui->comboBox_2->addItem(info.portName);
    }

    cityCode = "000000";

    on_comboBox_activated(ui->comboBox->currentText());
    on_comboBox_2_activated(ui->comboBox_2->currentText());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    OpenapiRequest request;
    request.fromString(ui->plainTextEdit->toPlainText());
    openapiRamboProxy->invoke(request);
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    qDebug() << arg1;

    if(arg1 == "VoucherConfirm")
    {
        VoucherConfirmRequest parameters;
        parameters.setBizRequestId(QHostInfo::localHostName());
        parameters.setCityCode(cityCode);

        QVariantMap info;
        info["servicePoint"] = "asdf";
        info["terminalId"] = "asdf";
        parameters.setBizInfoExt(JsonObject::toJsonString(info));
        parameters.setOperateTime(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
        parameters.setTicketNo("");

        ui->plainTextEdit->setPlainText(parameters.toOpenapiRequest().toString(true));
    }
    else if(arg1 == "VoucherQuery")
    {
        VoucherQueryRequest parameters;

        parameters.setTicketNo("");
        parameters.setCityCode(cityCode);


        ui->plainTextEdit->setPlainText(parameters.toOpenapiRequest().toString(true));
    }
    else if(arg1 == "VoucherCancel")
    {
        VoucherCancelRequest parameters;

        QVariantMap info;
        info["servicePoint"] = "asdf";
        info["terminalId"] = "asdf";
        parameters.setBizInfoExt(JsonObject::toJsonString(info));
        parameters.setCityCode(cityCode);
        parameters.setOperateTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        parameters.setTicketNo("");

        ui->plainTextEdit->setPlainText(parameters.toOpenapiRequest().toString(true));
    }
    else if(arg1 == "VoucherUpload")
    {
        VoucherQueryRequest parameters;

        parameters.setCityCode(cityCode);
        parameters.setTicketNo("");

        ui->plainTextEdit->setPlainText(parameters.toOpenapiRequest().toString(true));
    }


}

void MainWindow::onOpenapiFinished(OpenapiResponse *response)
{
    ui->plainTextEdit_2->setPlainText(response->toString(true));
}


void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    if(ramboClient != 0)
    {
        ramboClient->deleteLater();
        openapiRamboProxy->deleteLater();
    }

    ramboClient = new RamboClient(arg1, 1*60*1000, this);
    openapiRamboProxy = new OpenapiRamboProxy(ramboClient, this);

    connect(openapiRamboProxy,
            SIGNAL(finished(OpenapiResponse*)),
            SLOT(onOpenapiFinished(OpenapiResponse*)));
}
