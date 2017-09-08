import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 100
    height: 100
    color: "light blue"

    ListView {
        anchors.fill: parent
        model: myModel
        delegate: Text { text: modelData }
    }
}
