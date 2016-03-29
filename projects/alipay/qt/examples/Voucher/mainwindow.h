#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../src/rambo/ramboclient.h"
#include "../../src/rambo/openapiramboproxy.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void onQrCodeReceived(QString code);

private slots:
    void onQueryFinished();
    void onConfirmFinished();

    bool eventFilter(QObject *obj, QEvent *event);
    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;

    QString cityCode;
    QString qrCode;

    RamboClient* ramboClient;
    OpenapiRamboProxy* openapiRamboProxy;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *keyEvent);
};

#endif // MAINWINDOW_H
