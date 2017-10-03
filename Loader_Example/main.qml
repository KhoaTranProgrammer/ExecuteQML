import QtQuick 2.3

Rectangle {
    width: 720
    height: 480
    color: "light green"

    Loader {
        id: myLoader
        anchors.fill: parent
        source: "MyText.qml"
    }

    Component {
        id: id_myText
        Item {
            anchors.fill: parent
            Text{
                anchors.centerIn: parent
                text: "This is a Component object"
                font.pixelSize: 50
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if(myLoader.source == ""){
                myLoader.sourceComponent = null
                myLoader.source = "MyText.qml"
            }else{
                myLoader.source = ""
                myLoader.sourceComponent = id_myText
            }
        }
    }
}
