var myText = null

function createQMLObjectFromFile(){
    if(myText) myText.destroy()
    var component = Qt.createComponent("MyText.qml");
    myText = component.createObject(root, {"anchors.fill": root});
}

function createQMLObjectFromString(){
    if(myText) myText.destroy()
    myText = Qt.createQmlObject('import QtQuick 2.0; Item {anchors.fill: parent; Text { anchors.centerIn: parent; text: "This is a QML string"; font.pixelSize: 50} }', root);
}
