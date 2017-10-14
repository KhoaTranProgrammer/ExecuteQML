#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QObject>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickView>
#include <QtQuick>
#include <QDebug>

class MyWidget : public QObject
{
    Q_OBJECT
public:
    MyWidget(QQmlEngine* engine, QObject* parent, QUrl source);
    ~MyWidget();

private:
    QQmlComponent *m_component;
    QQuickItem *m_quickItem;
};

#endif // MYWIDGET_H
