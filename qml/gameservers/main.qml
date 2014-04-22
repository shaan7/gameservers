import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.1

import com.thoughtworks.gameservers 1.0 as TW

ApplicationWindow {
    title: qsTr("Game Servers")
    width: 640
    height: 480

    ColumnLayout {
        anchors.fill: parent

        Label {
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            font.pointSize: 16
            text: "Counter-Strike Game Servers"

            Bubbles { anchors.fill: parent }
        }

        TableView {
            id: table
            Layout.fillWidth: true
            Layout.fillHeight: true

            model: TW.ServersModel {}

            TableViewColumn { role: "host"; title: "Server"; width: table.width*0.6 }
            TableViewColumn { role: "port"; title: "Port"; width: table.width*0.2 }
            TableViewColumn { role: "ping"; title: "Ping"; width: table.width*0.2 }

            rowDelegate: Rectangle {
                height: styleData.selected ? 48 : 24
                color: styleData.selected ? "#184880" : "#302F2F"

                Behavior on height { NumberAnimation { duration: 100 } }
            }

            itemDelegate: ServerListItemDelegate {}
        }
    }
}
