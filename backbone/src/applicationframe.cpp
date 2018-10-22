#include <backbone/applicationframe.h>
#include <QtQuickTemplates2/private/qquickstackview_p.h>
#include <QtCore/QtDebug>


namespace Backbone {

ApplicationFrame::ApplicationFrame()
{
}


void ApplicationFrame::start()
{
    qDebug() << "application start";

    if (!navigationView_) {
        qDebug() << "there is not navigation view";
        return;
    }

    QQuickStackView * stackView = qobject_cast<QQuickStackView*>(navigationView_);
    if (!stackView) {
        qDebug() << "navigationView has unexpected type";
        return;
    }

    qDebug() << "appFrame initialized successfully";
}


} // namespace Backbone
