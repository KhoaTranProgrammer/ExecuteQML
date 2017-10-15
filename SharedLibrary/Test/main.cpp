#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QtQuick>
#include "mywidget.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc,argv);

    QQuickView view;
    view.setSource(QUrl("qrc:///main.qml"));
    view.resize(720, 480);
    view.show();

    MyWidget widget(view.engine(), view.rootObject(), view.source());

    return app.exec();
}
