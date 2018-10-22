import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
// import QtQuick.Controls 1.4 as OldControls
import Backbone 1.0 as Backbone


Window {
    readonly property alias stackView: stack

    visible: true
    width: 640
    height: 480
    title: qsTr("DI Application")

    // Old controls. Legacy

    /*
    OldControls.StackView {
        id: stackView
        anchors.fill: parent
        initialItem: Qt.resolvedUrl("index.qml")
    }

    Connections {
        target: router
        onPushPage: {
            var params = {
                "item": Qt.resolvedUrl(page),
                "properties": { "args": args }
            };
            stackView.push(params);
        }

        onPop: stackView.pop()
    }
    */

    // -------------------------------------------------------------------------

    // Controls 2 prefered impl
    StackView {
        id: stack
        anchors.fill: parent
        initialItem: Qt.resolvedUrl("index.qml")
    }

    Connections {
        target: router

        onPushPage: stack.push(page);
        onPopPage: stack.pop();
        onReplace: stack.replace(Qt.resolvedUrl(page), { "args": args });
    }
}
