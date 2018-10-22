#include <backbone/pagepresenter.h>
#include <QtQuick/QQuickItem>


namespace Backbone {


PagePresenter::PagePresenter(QObject * parent)
    : Presenter(parent)
{
}


void PagePresenter::onCreate(QQuickItem *, const QVariantMap &)
{
    qDebug() << "pagePreseter::onCreate " << objectName();
}


void PagePresenter::activating()
{
//    qDebug() << objectName() << " activating";
}

void PagePresenter::activated()
{
//    qDebug() << objectName() << " activated";
}

void PagePresenter::deactivating()
{
//    qDebug() << objectName() << " deactivating";
}

void PagePresenter::deactivated()
{
//    qDebug() << objectName() << " deactivated";
}


void PagePresenter::keyPressEvent(QKeyEvent * event)
{
    if (!router)
        return;

    switch (event->key())
    {
    case Qt::Key_Escape:
    case Qt::Key_Back:
        if (router->depth() == 1)
        {
            qApp->quit();
        }
        else
        {
            router->pop();
        }
        return;
    }
}


void PagePresenter::setRouter(Router * router)
{
    this->router = router;
}


} // namespace Backbone
