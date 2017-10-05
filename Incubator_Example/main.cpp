#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>

int main(int argc, char* argv[])
{
    QGuiApplication app(argc,argv);
    QQuickView view;
    view.setSource(QUrl("qrc:///main.qml"));
    view.resize(720, 480);
    view.show();
    return app.exec();
}
