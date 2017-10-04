import QtQuick 2.3
import "CreateQMLObject.js" as MyScript

Rectangle {
    id: root
    anchors.fill: parent
    color: "light green"
    property int i: 0

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if(i % 2 == 0) MyScript.createQMLObjectFromString()
            else MyScript.createQMLObjectFromFile()
            i++
        }
    }
}
