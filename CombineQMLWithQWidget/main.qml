import QtQuick 2.3
import Speed 1.0

Rectangle {
    id: root
    width: 400
    height: 400
    color: "black"

    property int numberIndexs: 15
    property int startAngle: 234
    property int angleLength: 18
    property int maxSpeed: 280

    Speed {
        id: mySpeed
    }

    Image {
        anchors.fill: parent
        source: "speed.png"
    }

    SpeedNeedle {
        anchors {
            top: parent.top
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
        }
        value: mySpeed.speed
        startAngle: root.startAngle
        angleLength: root.angleLength / (root.maxSpeed / (root.numberIndexs - 1))
    }
}
