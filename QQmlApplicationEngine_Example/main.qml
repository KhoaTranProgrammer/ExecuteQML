import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    Text{
        id: id_text
        text: qsTr("Hello World")
        verticalAlignment: Text.AlignVCenter
        anchors.centerIn: parent
    }
}
