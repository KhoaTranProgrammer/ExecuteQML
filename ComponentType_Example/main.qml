import QtQuick 2.3

Item {
    id: root
    anchors.fill: parent

    Component {
        id: redSquare
        Rectangle {
            anchors.fill: parent
            color: "light green"
            radius: width / 2
            MouseArea {
                anchors.fill: parent
                onClicked: Qt.quit()
            }
        }
    }

    Component.onCompleted: {
        redSquare.createObject(root)
    }
}
