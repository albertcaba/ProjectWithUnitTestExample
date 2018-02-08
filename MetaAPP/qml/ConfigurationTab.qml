import QtQuick 2.7
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
//import QtQuick.Controls 1.4

//import ConfigTab 1.0

GridLayout
{
    rows: 6
    columns: 3
    anchors.fill: parent;
    objectName: "ConfigurationTab"
    signal submitConfiguration(string Hostname, string User, string Password, int Port)

    Label {
        id: text_hostname
        text: qsTr("Hostname:")
        Layout.row: 0
        Layout.column: 0
        //Layout.columnSpan: 2
        font.pixelSize: 12
    }

    TextField {
            objectName: "textInput_hostname"
            id: textInput_hostname

            text: qsTr("HOSTNAME")
            selectionColor: "#000000"
            width: parent.width
            //inputMethodHints: Qt.ImhDigitsOnly
            Layout.row: 0
            Layout.column: 1
            Layout.columnSpan: 1
            font.pixelSize: 12

            // Store the previous text for restoring it if we cancel
            property string oldText

            // Lets us know that the user is cancelling the save
            property bool cancelling

            Keys.onEscapePressed: {
                // Cancel the save, and deselect the text input
                cancelling = true
                focus = false
            }

            onEditingFinished: {
                if (cancelling) {
                    // When cancelling, restore the old text, and clear state.
                    text = oldText
                    oldText = ""
                    cancelling = false
                } else {
                    // TO DO: Handle new text
                    console.log("Handle new text!");
                }
            }

            onActiveFocusChanged: {
                // When we first gain focus, save the old text and select everything for clearing.
                if (activeFocus) {
                    oldText = text
                    selectAll()
                }
            }
    }


    Label {
        id: text_user
        text: qsTr("User:")
        Layout.row: 1
        Layout.column: 0
        font.pixelSize: 12
    }

    TextField {
        objectName: "textInput_user"
        id: textInput_user

        text: qsTr("Text Input")
        Layout.row: 1
        Layout.column: 1
        Layout.columnSpan: 1
        font.pixelSize: 12
    }
    Label {
        id: text_password
        text: qsTr("Password")
        Layout.row: 2
        Layout.column: 0
        font.pixelSize: 12
    }

    TextField {
        objectName: "textInput_password"
        id: textInput_password
        text: qsTr("Text Input")
        echoMode: TextInput.Password
        cursorVisible: true
        Layout.row: 2
        Layout.column: 1
        Layout.columnSpan: 1
        font.pixelSize: 12
    }
    Label {
        id: text_port
        text: qsTr("Port")
        Layout.row: 3
        Layout.column: 0
        font.pixelSize: 12
    }

    TextField {
        objectName: "textInput_port"
        id: textInput_port
        text: qsTr("1883")
        Layout.row: 3
        Layout.column: 1
        Layout.columnSpan: 1
        font.pixelSize: 12
        validator: RegExpValidator { regExp: /[0-9]+/ }
    }

    Button {
        id: button_save
        Layout.row: 4
        Layout.column: 1
        text: qsTr("Save Configuration")

        onClicked:
        {
            // emit the submitTextField signal
            console.log("emit the submitTextField signal!");
            submitConfiguration(textInput_hostname.text, textInput_user.text, textInput_password.text, textInput_port.text)
        }
    }
}

/*
ScrollView {
    width: 100
    height: 100
    clip: true

    Label {
        text: "ABC"
        font.pixelSize: 600
    }
}
*/
