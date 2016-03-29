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

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

    void onOpenapiFinished(OpenapiResponse* response);

    void on_comboBox_2_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QString cityCode;

    RamboClient* ramboClient;
    OpenapiRamboProxy* openapiRamboProxy;
};

#endif // MAINWINDOW_H
