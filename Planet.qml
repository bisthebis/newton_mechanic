import QtQuick 2.7

Item  {
    property alias color: circle.color;
    property alias radius : circle.radius;
    property alias name: nameText.text


    Rectangle {
        visible: true;
        id: circle
        anchors.centerIn: parent
        width: radius * 2;
        height: width;
        color: "red"

    }

    Text {
        z: 1
        id: nameText
        text: "Anonymous object";
        anchors.centerIn: parent;
        font.pointSize: 8;
        color: "black"
    }

}
