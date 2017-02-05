import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Planet {
        anchors.centerIn: parent
        name: "Terre"
        radius: 20
        color: "#0088FF"
    }

    /*MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            Qt.quit();
        }
    }//*/
}
