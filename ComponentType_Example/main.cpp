#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView view;
    view.setSource(QUrl("qrc:/main.qml"));
    QObject::connect(view.engine(), SIGNAL(quit()), &view, SLOT(close()));
    view.setMinimumSize(QSize(200, 200));
    view.show();
    return app.exec();
}
