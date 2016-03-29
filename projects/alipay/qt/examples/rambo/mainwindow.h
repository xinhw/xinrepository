#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMetaObject>
#include "openapirambo.h"
#include "../../src/rambo/ramboservice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void appendDebugString(const QString& msg);

private slots:

private:
    Ui::MainWindow *ui;

    OpenapiRambo* openapiRambo;
    RamboService* ramboService;
};

#endif // MAINWINDOW_H
