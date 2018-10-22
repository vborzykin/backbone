#include "indexpagepresenter.h"
#include <QtCore/QDebug>
#include <QtCore/QTimer>
#include <QtCore/QVariant>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickItem>


IndexPagePresenter::IndexPagePresenter(QObject * parent)
    : Backbone::PagePresenter(parent)
{
    setObjectName(QStringLiteral("IndexPagePresenter object"));
}


void IndexPagePresenter::onCreate(QQuickItem * view, const QVariantMap & args)
{
    PagePresenter::onCreate(view, args);

    engine_ = QtQml::qmlEngine(view);
}


void IndexPagePresenter::onDataReady()
{
    // data ready push next page

    QVariantMap args;
    args["objectContext"] = QString("context sharedPtr");

    if (!router)
    {
        qDebug() << "no router!";
        return;
    }

    router->push("qrc:///qml/search.qml", std::move(args));
}


void IndexPagePresenter::searchByText(QString pattern)
{
    Q_UNUSED(pattern);

    if (!router)
        return;

    QVariantMap args;
    args.insert(QStringLiteral("pattern"), pattern);

    router->push("qrc:///qml/search.qml", std::move(args));
}


void IndexPagePresenter::collect()
{
    if (engine_)
    {
        qDebug() << "collect garbage";
        engine_->collectGarbage();
    }
}

