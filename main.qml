import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

import Planet.Simulation 1.0

Window {
    visible: true
    width: 1500
    height: 1500
    title: qsTr("Hello World")

    function computeBarycentre() {
        var sumX = sim.ma*sim.xa + sim.mb*sim.xb;
        var sumY = sim.ma*sim.ya + sim.mb*sim.yb;
        barycentre.x = sumX / (sim.ma + sim.mb);
        barycentre.y = sumY / (sim.ma + sim.mb);
    }

    Simulation {
        id: sim
        Component.onCompleted: {
            sim.defaultInit();

            }

        onA_moved: {
            earth.x = sim.xa
            earth.y = sim.ya
            computeBarycentre();
            //console.log("Earth pos : " + sim.xa + ", " + sim.ya)
        }

        onB_moved: {
            moon.x = sim.xb
            moon.y = sim.yb
            //console.log("Moon pos : " + sim.xb + ", " + sim.yb)
        }
    }



    Planet {
        id: earth

        name: "Terre"
        radius: 100
        color: "#0088FF"
    }

    Planet {
        id: moon

        name: "Lune"
        radius: 15
        color: "#888888"
    }

    Planet {
        id: barycentre
        name: "Barycentre"
        radius: 5
        color: "red"
    }

    Timer {
        interval: 10;
        repeat: true;
        running: true;
        onTriggered: sim.advance()
    }

    /*MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            Qt.quit();
        }
    }//*/
}
