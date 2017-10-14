#-------------------------------------------------
#
# Project created by QtCreator 2017-10-10T08:49:37
#
#-------------------------------------------------

QT += qml quick

TARGET = MyWidget
TEMPLATE = lib
CONFIG += staticlib

SOURCES += mywidget.cpp

HEADERS += mywidget.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES +=
