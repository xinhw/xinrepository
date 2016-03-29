#-------------------------------------------------
#
# Project created by QtCreator 2016-01-11T16:22:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Voucher
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

include(../../src/rambo/rambo.pri)
include(../../src/rpcmodle/rpcmodle.pri)
include(../../src/openapi/openapi.pri)
