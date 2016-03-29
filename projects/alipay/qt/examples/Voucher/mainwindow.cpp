#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../../src/rpcmodle/voucherquery.h"
#include "../../src/rpcmodle/voucherconfirm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->installEventFilter(this);
    //ui->plainTextEdit->installEventFilter(this);

    ramboClient = new RamboClient("com4", 3*60*1000, this);
    openapiRamboProxy = new OpenapiRamboProxy(ramboClient, this);

    cityCode = "000000";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onQrCodeReceived(QString code)
{
    QStringList sl = code.split(QRegExp("[=&]"), QString::SkipEmptyParts);
    int i = sl.indexOf("ticket_no");
    QString ticketNo = sl[i+1];

    VoucherQueryRequest request;
    request.setCityCode(cityCode);
    request.setTicketNo(code);

    OpenapiResponse* response = openapiRamboProxy->invoke(request.toOpenapiRequest());
    connect(response, SIGNAL(finished()), SLOT(onQueryFinished()));

}

void MainWindow::onQueryFinished()
{
    OpenapiResponse* response = (OpenapiResponse*)sender();

    VoucherQueryResponse qrueryResponse;
    qrueryResponse.fromOpenapiResponse(*response);

    ui->plainTextEdit->appendPlainText(qrueryResponse.toString(true));
    VoucherConfirmRequest confirmRequest;

    confirmRequest.setCityCode(cityCode);
    confirmRequest.setBizRequestId(QString::number(QDateTime::currentMSecsSinceEpoch()));
    confirmRequest.setOperateTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    confirmRequest.setTradeNo(qrueryResponse.getTradeNo());

    QVariantMap info;
    info["servicePoint"] = "asdf";
    info["terminalId"] = "asdf";
    confirmRequest.setBizInfoExt(JsonObject::toJsonString(info));

    qDebug() << "MainWindow::onQueryFinished()" << confirmRequest.toString();

    OpenapiResponse* confirmResponse = openapiRamboProxy->invoke(confirmRequest.toOpenapiRequest());
    connect(confirmResponse, SIGNAL(finished()), SLOT(onConfirmFinished()));
}

void MainWindow::onConfirmFinished()
{
    OpenapiResponse* response = (OpenapiResponse*)sender();
    VoucherConfirmResponse confirmResponse;
    confirmResponse.fromOpenapiResponse(*response);

    ui->plainTextEdit->appendPlainText(confirmResponse.toString(true));
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        qDebug("Ate key press %d", keyEvent->text());

        if(keyEvent->text() == "\r")
        {

            ui->plainTextEdit->appendPlainText(qrCode);
            onQrCodeReceived(qrCode);
            qrCode.clear();
        }
        else
        {
            qrCode.append(keyEvent->text());
        }

    }

    // standard event processing
    return QObject::eventFilter(obj, event);

}


void MainWindow::keyPressEvent(QKeyEvent *keyEvent)
{
    return;
    qDebug("Ate key press %d", keyEvent->text());
    if(keyEvent->text() == "\r")
    {
        ui->plainTextEdit->appendPlainText(qrCode);
        onQrCodeReceived(qrCode);
        qrCode.clear();
    }
    else
    {
        qrCode.append(keyEvent->text());
    }
}

void MainWindow::on_lineEdit_returnPressed()
{
    onQrCodeReceived(ui->lineEdit->text());
}
