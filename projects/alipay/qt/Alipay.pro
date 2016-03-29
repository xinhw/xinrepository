QT += core network
QT -= gui

TARGET = Alipay
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    httprpctransport.cpp \
    openapisigner.cpp \
    responsebase.cpp \
    requestbase.cpp \
    cancelrequest.cpp \
    cancelresponse.cpp \
    opensslrsawrapper.cpp

HEADERS += \
    httprpctransport.h \
    openapisigner.h \
    responsebase.h \
    requestbase.h \
    cancelrequest.h \
    cancelresponse.h \
    opensslrsawrapper.h

LIBS += -llibeay32
LIBS += -lssleay32
