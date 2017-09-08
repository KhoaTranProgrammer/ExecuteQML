#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QStringListModel>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlEngine engine;
    QQmlContext *context = new QQmlContext(engine.rootContext());
    QStringList dataList;
    dataList.append("Item 1");
    dataList.append("Item 2");
    context->setContextProperty("myModel", QVariant::fromValue(dataList));
    QQmlComponent component(&engine, QUrl("qrc:/main.qml"));
    component.create(context);

    return app.exec();
}
