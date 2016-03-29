
#include <QCoreApplication>
#include <QTest>

#include "testcancelrequest.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestCancelRequest testCancelRequest;
    QTest::qExec(&testCancelRequest);

    return a.exec();
}
