HEADERS += \
    $$PWD/openapirequest.h \
    $$PWD/openapiresponse.h \
    $$PWD/openapitransport.h \
    $$PWD/openapisigner.h \
    $$PWD/opensslrsawrapper.h \
    $$PWD/openapitransportbase.h

SOURCES += \
    $$PWD/openapirequest.cpp \
    $$PWD/openapiresponse.cpp \
    $$PWD/openapitransport.cpp \
    $$PWD/openapisigner.cpp \
    $$PWD/opensslrsawrapper.cpp \
    $$PWD/openapitransportbase.cpp


QT += network

win32{
LIBS += -llibeay32
LIBS += -lssleay32
}

unix{
LIBS += -lssl
LIBS += -lcrypto
LIBS += -L/home/forlinx/work/openssl-1.0.2e
INCLUDEPATH += /home/forlinx/work/openssl-1.0.2e/include
}


