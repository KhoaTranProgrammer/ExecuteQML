import QtQuick 2.3

Rectangle {
    id: root
    anchors.fill: parent
    color: "light green"

    Component.onCompleted: {
        var component = Qt.createComponent("MyText.qml");
        var incubator = component.incubateObject(root, {"anchors.fill": root});
    }
}
