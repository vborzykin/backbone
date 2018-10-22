#include "detailpagepresenter.h"
#include <QtCore/QVariantMap>
#include <QtCore/QDebug>
#include "consts.h"


DetailPagePresenter::DetailPagePresenter()
{
}


void DetailPagePresenter::onCreate(QQuickItem * view, const QVariantMap & args)
{
    PagePresenter::onCreate(view, args);

    auto it = args.find(QStringLiteral("selectedItem"));
    if (it != args.end())
    {
        model_ = it.value().value<QObject*>();
        emit modelChanged();
    }

    it = args.find(Consts::CORE_CONTEXT);
    if (it != args.end())
    {
        context_ = it.value().value<ContextPtr>();
    }

    if (context_)
    {
        qDebug() << "context: " << context_->id;
    }
    else
    {
        qDebug() << "no context available";
    }
}

