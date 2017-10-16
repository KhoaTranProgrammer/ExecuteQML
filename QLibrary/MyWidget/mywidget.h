#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QObject>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickView>
#include <QtQuick>
#include <QDebug>
#include "mywidget_global.h"

class MyWidget;

extern "C" MYWIDGETSHARED_EXPORT MyWidget* createNewWidget(QQmlEngine* engine, QObject* parent, QUrl source);

class MYWIDGETSHARED_EXPORT MyWidget : public QObject
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
