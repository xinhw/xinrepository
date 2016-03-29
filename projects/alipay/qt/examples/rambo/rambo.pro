#-------------------------------------------------
#
# Project created by QtCreator 2015-12-31T16:35:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rambo

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    openapirambo.cpp

HEADERS  += mainwindow.h \
    openapirambo.h

FORMS    += mainwindow.ui


INCLUDEPATH += ../../src

# 辛宏伟添加，否则报错找不到openssl/rsa.h文件
INCLUDEPATH += D:/tools/OpenSSL-Win64/include

include(../../src/rambo/rambo.pri)
include(../../src/openapi/openapi.pri)
include(../../src/rpcmodel/rpcmodel.pri)

unix{

    opensslPath=/home/forlinx/work/openssl-1.0.2e
    targetPath=/forlinx/work/rambo

    target.files = rambo
    target.path = $$targetPath
    INSTALLS += target

    openapi.files = $$PWD/openapi.ini
    openapi.path = $$targetPath
    INSTALLS += openapi

    cacert.files = $$PWD/cacert.pem
    cacert.path = $$targetPath
    INSTALLS += cacert

    rambosh.files = $$PWD/rambo.sh
    rambosh.path = $$targetPath
    INSTALLS += rambosh

    QtCore.files = $$[QT_INSTALL_LIBS]/libQtCore.so.$$[QT_VERSION]
    QtCore.path = $$targetPath
    INSTALLS += QtCore

    QtGui.files = $$[QT_INSTALL_LIBS]/libQtGui.so.$$[QT_VERSION]
    QtGui.path = $$targetPath
    INSTALLS += QtGui

    QtNetwork.files = $$[QT_INSTALL_LIBS]/libQtNetwork.so.$$[QT_VERSION]
    QtNetwork.path = $$targetPath
    INSTALLS += QtNetwork

}

DISTFILES += \
    rambo.sh \
    cacert.pem

LIBS += -LD:/tools/OpenSSL-Win64/lib -llibeay32 -lssleay32

