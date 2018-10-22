#include <backbone/incubator.h>
#include <QtCore/QMetaObject>
#include <QtCore/QTimer>


namespace Backbone {


Incubator::Incubator(QQmlComponent * component, QQmlContext * ctx, InjectorCallback callback)
    : QObject()
    , component_(component)
    , context_(ctx)
    , callback_(std::move(callback))
{
    if (!onComponentStatusChanged(component_->status()))
    {
        connect(component_, &QQmlComponent::statusChanged, this, &Incubator::onComponentStatusChanged);
    }
}


Incubator::Incubator(QQmlEngine * engine, QQmlContext * ctx, const QUrl & url, InjectorCallback callback)
    : Incubator(new QQmlComponent(engine, url), ctx, std::move(callback))
{
    // TODO: memory management is sucks in this class
    component_->setParent(this);
}


bool Incubator::onComponentStatusChanged(QQmlComponent::Status status)
{
    if (status == QQmlComponent::Ready)
    {
        auto instance = component_->beginCreate(context_);
        if (callback_)
        {
            callback_(instance);
        }
        component_->completeCreate();

        QTimer::singleShot(0, this, [this, instance] {
            emit this->ready(instance, QString());
        });
    }
    else if (status == QQmlComponent::Error)
    {
        QTimer::singleShot(0, this, [this, error = component_->errorString()] {
            emit this->ready(nullptr, error);
        });
    }
    else
    {
        return false;
    }
    return true;
}


} // namespace Backbone
