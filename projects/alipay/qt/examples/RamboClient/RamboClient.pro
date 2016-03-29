#-------------------------------------------------
#
# Project created by QtCreator 2016-01-04T11:51:35
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RamboClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    alipay.cpp

HEADERS  += mainwindow.h \
    alipay.h

FORMS    += mainwindow.ui

include(../../src/rambo/rambo.pri)
include(../../src/rpcmodel/rpcmodel.pri)
include(../../src/openapi/openapi.pri)


# 辛宏伟添加，否则报错找不到openssl/rsa.h文件
INCLUDEPATH += D:/tools/OpenSSL-Win64/include


LIBS += -LD:/tools/OpenSSL-Win64/lib -llibeay32 -lssleay32
