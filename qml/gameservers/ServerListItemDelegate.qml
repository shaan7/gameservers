import QtQuick 2.0
import QtQuick.Layouts 1.1

Item {
    ColumnLayout {
        anchors { fill: parent; margins: 5 }
        Text {
            Layout.fillWidth: true
            Layout.fillHeight: styleData.selected

            color: "white"
            elide: styleData.elideMode
            text: styleData.value ? styleData.value : ""
        }

        Text {
            Layout.fillWidth: true
            text: styleData.column === 0 ? "Here we can show details about the server" : ""
            color: styleData.textColor
            elide: styleData.elideMode
        }
    }
}
