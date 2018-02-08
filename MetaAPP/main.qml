import "qml"
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    objectName: "textInput_CACA"

    TabWidget
    {
        id: tabs
        width: 640; height: 480
        objectName: "MainTab"
        //anchors.fill: parent

        ModuleList
        {
            objectName: "textInput_CACA2"
            property string title: "All Modules"
            anchors.fill: parent
            anchors.centerIn: parent
        }


        Rectangle {
            property string title: "Alarms"
            anchors.fill: parent
            color: "#e3e3e3"

            Rectangle {
                anchors.fill: parent; anchors.margins: 20
                color: "#7fff7f"
                Text {
                    width: parent.width - 20
                    anchors.centerIn: parent; horizontalAlignment: Qt.AlignHCenter
                    text: "Flower stems are green"
                    font.pixelSize: 20
                    wrapMode: Text.WordWrap

                }
            }
        }

        ConfigurationTab
        {
            property string title: "Configuration"
            anchors.fill: parent;
            anchors.centerIn: parent
        }
        /*
        Rectangle
        {
            property string title: "Configuration"
            anchors.fill: parent; color: "#e3e3e3"

            Rectangle {
                anchors.fill: parent; anchors.margins: 20
                color: "#7f7fff"
                Text {
                    width: parent.width - 20
                    anchors.centerIn: parent; horizontalAlignment: Qt.AlignHCenter
                    text: "Violets are blue"
                    font.pixelSize: 20
                    wrapMode: Text.WordWrap
                }
            }
        }*/

    }
}
