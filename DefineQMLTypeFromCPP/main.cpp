#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "cpuinfo.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView view;

    qmlRegisterType<CpuInfo>("CpuInfo", 1, 0, "CpuInfo");
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    return app.exec();
}
