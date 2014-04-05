import QtQuick 2.0
import com.thoughtworks.gameservers 1.0 as TW

Item {
    clip: true
    Rectangle {
        anchors { fill: parent; margins: 5 }
        radius: 5
        border.color: 'red'

        Text {
            anchors.centerIn: parent
            text: host + ':' + port + '\n' + pinger.latency + ' ms'
        }

        Timer {
            interval: 2000; repeat: true; running: true
            onTriggered: pinger.ping(host, port)
        }

        TW.Pinger {
            id: pinger
        }
    }
}
