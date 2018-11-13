#include "entity.h"


Entity::Entity(ContextPtr context)
    : QObject()
{
    setCoreContext(std::move(context));
}


Entity::Entity(ContextFutureUnq futurePtr)
    : QObject()
{
    if (!futurePtr)
    {
        qFatal("does not work like that");
    }

    auto future = futurePtr.release();

    connect(future, &ContextFuture::finished, future, &ContextFuture::deleteLater);
    connect(future, &ContextFuture::finished, this, [this, future] {
        this->setCoreContext(future->result());
    });
}


void Entity::setCoreContext(ContextPtr context)
{
    context_ = std::move(context);
}
