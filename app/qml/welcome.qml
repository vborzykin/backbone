import QtQuick 2.0
import Backbone 1.0 as Backbone
import App.Presenters 1.0


Backbone.Page {
    Rectangle {
        property WelcomePagePresenter presenter;

        Column {

            Backbone.Block {
                id: photosBlock

                property PhotosBlockPresenter presenter

                PhotosView {
                }

                onReady: scheduleBlock.load()
            }

            Backbone.Block {
                id: scheduleBlock
                enabled: false

                property ScheduleBlockPresenter presenter

                ScheduleView {
                }
            }

        } // Column

    } // Pave view

} // Page
