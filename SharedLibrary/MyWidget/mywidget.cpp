#include "mywidget.h"


MyWidget::MyWidget(QQmlEngine* engine, QObject* parent, QUrl source)
{
    qDebug() << "MyWidget::" << Q_FUNC_INFO;
    m_component = new QQmlComponent(engine);
    m_component->setData("import QtQuick 2.0; Rectangle { anchors.fill: parent; anchors.margins: 50; color: \"yellow\"; opacity: 0.5; radius: 50; Text{ anchors.centerIn: parent; text: \"New Widget\"; font.pixelSize: 50; }}", source);
    m_quickItem = qobject_cast<QQuickItem*>(m_component->create());
    m_quickItem->setParentItem(qobject_cast<QQuickItem*>(parent));
}

MyWidget::~MyWidget()
{
    qDebug() << "MyWidget::" << Q_FUNC_INFO;
    delete m_component;
    delete m_quickItem;
}
