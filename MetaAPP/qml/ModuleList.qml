import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import ModuleModelNameToImportToQML 1.0

ColumnLayout {
    Frame
    {
        Layout.fillWidth: true

        ListView
        {
            implicitWidth: 250
            implicitHeight: 250
            anchors.fill: parent
            clip: true
            spacing: 10

            model: ModuleListModel
            {
                list: moduleList
            }

            delegate: GridLayout
            {
                width: parent.width
                columns: 1
                rows: 3
                Text
                {
                    id:  moduleName
                    //text: qsTr("Module Name")
                    text: model.moduleName
                    Layout.row: 0
                    Layout.column:0
                    font.bold: true
                }
                Text
                {
                    id: moduleDescription
                    //text: qsTr("Module Description")
                    text: model.moduleApp
                    Layout.row:1
                    Layout.column:0
                }
                Text
                {
                    id: moduleTime
                    //text: qsTr("Module Time")
                    text: model.moduleLastConnection
                    Layout.row:2
                    Layout.column:0
                }
                Rectangle
                {
                    id: rectangle
                    Layout.row:3
                    Layout.column:0
                    //Layout.columnSpan: 2
                    height: 1
                    color: "#ef2929"

                    Layout.fillHeight: false
                    Layout.fillWidth: true
                }
            }
        }
    }

    RowLayout
    {
        Button
        {
            text: qsTr("Add new item")
            //onClicked: moduleList.appendItem()
            Layout.fillWidth: true
        }
        Button {
            text: qsTr("Remove completed")
            onClicked: moduleList.removeCompletedItems()
            Layout.fillWidth: true
        }
    }
}
