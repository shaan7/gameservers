import QtQuick 2.1
import QtQuick.Controls 1.0
import com.thoughtworks.gameservers 1.0 as TW

ApplicationWindow {
    title: qsTr("Hello World")
    width: 320
    height: 1024

    ListView {
        anchors.fill: parent

        model: GameServers {}
        delegate: GameServerDelegate { width: parent.width; height: 100 }
    }
}
