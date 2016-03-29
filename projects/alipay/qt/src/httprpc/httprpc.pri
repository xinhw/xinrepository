include(../qjson/qjson.pri)

QT += network

LIBS += -llibeay32
LIBS += -lssleay32

HEADERS += \
    $$PWD/voucherconfirmrequest.h \
    $$PWD/voucherconfirmresponse.h \
    $$PWD/voucheruploadrequest.h \
    $$PWD/voucheruploadresponse.h

SOURCES += \
    $$PWD/voucherconfirmrequest.cpp \
    $$PWD/voucherconfirmresponse.cpp \
    $$PWD/voucheruploadrequest.cpp \
    $$PWD/voucheruploadresponse.cpp
