#-------------------------------------------------
#
# Project created by QtCreator 2017-10-12T10:20:40
#
#-------------------------------------------------

QT       += qml quick

TARGET = MyWidget
TEMPLATE = lib

DEFINES += MYWIDGET_LIBRARY

SOURCES += mywidget.cpp

HEADERS += mywidget.h\
        mywidget_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
