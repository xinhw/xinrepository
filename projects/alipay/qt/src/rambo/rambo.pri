HEADERS += \
    $$PWD/rambobase.h \
    $$PWD/ramborequest.h \
    $$PWD/ramboresponse.h \
    $$PWD/ramboservice.h \
    $$PWD/ramboclient.h \
    $$PWD/openapiramboproxy.h

SOURCES += \
    $$PWD/rambobase.cpp \
    $$PWD/ramborequest.cpp \
    $$PWD/ramboresponse.cpp \
    $$PWD/ramboservice.cpp \
    $$PWD/ramboclient.cpp \
    $$PWD/openapiramboproxy.cpp

include(../../src/qextserialport/qextserialport.pri)
include(../../src/qjson/qjson.pri)
