import QtQuick 2.3

Rectangle {
    width: 200
    height: 200
    color: "light green"
    radius: width / 2

    MouseArea {
        anchors.fill: parent
        onClicked: Qt.quit()
    }
}
