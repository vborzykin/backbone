import QtQuick 2.8
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import Backbone 1.0 as Backbone
import App.Presenters 1.0


Backbone.Page { // container
    Rectangle { // view
        property IndexPagePresenter presenter;

        anchors.fill: parent
        color: "#f5f5f5"

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 30
            spacing: 30

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: 48

                Row {
                    Button {
                        text: "collect"
                        onClicked: presenter.collect()
                    }
                }
            }

            TextField {
                Layout.fillWidth: true
                Layout.minimumHeight: 64
                Layout.preferredHeight: 64
                Layout.maximumHeight: 96
                onAccepted: presenter.searchByText(text)
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }
    }
}
