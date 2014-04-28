import QtQuick 2.0
import QtQuick.Layouts 1.1

Item {
    ColumnLayout {
        anchors { fill: parent; margins: 5 }
        Text {
            Layout.fillWidth: true
            Layout.fillHeight: styleData.selected

            color: styleData.column === 2 ? calculateColor(text) : "white"
            elide: styleData.elideMode
            text: styleData.value ? styleData.value : ""
            font.pointSize: styleData.selected ? 13 : 10
        }

        Text {
            Layout.fillWidth: true
            text: styleData.column === 0 ? "Here we can show details about the server" : ""
            color: styleData.textColor
            elide: styleData.elideMode
        }
    }

    function calculateColor(value) {
        if (value < 100)    return "green";
        if (value > 100 && value < 200)    return "yellow";
        return "red";
    }
}
