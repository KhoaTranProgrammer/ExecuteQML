import QtQuick 2.0

Rectangle {
    color: "light green"
    radius: width / 2

    MouseArea {
        anchors.fill: parent
        onClicked: Qt.quit()
    }
}
