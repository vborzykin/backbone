#include <backbone/qmlcomponentscache.h>
#include <QtCore/QUrl>
#include <QtCore/QDebug>
#include <QtQml/QQmlComponent>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>


namespace Backbone {


QmlComponentsCache::QmlComponentsCache(QQmlEngine * engine)
    : QObject(engine)
    , engine_(engine)
{
    if (!engine_)
    {
        qFatal("could not create components without QQmlEngine");
    }
}


Incubator * QmlComponentsCache::create(const QUrl & url, InjectorCallback injector)
{
    Q_ASSERT(engine_);
    QQmlContext * ctx = engine_->rootContext();
    Incubator * incubator = nullptr;

    auto it = cache_.find(url);
    if (it != cache_.end())
    {
        incubator = new Incubator(it.value(), ctx, std::move(injector));
    }
    else
    {
        incubator = new Incubator(engine_, ctx, url, std::move(injector));
        auto component = incubator->component();
        component->setParent(this);
        cache_.insert(url, component);
    }
    return incubator;
}


Incubator * QmlComponentsCache::create(const QUrl & url)
{
    return create(url, InjectorCallback());
}


} // namespace Backbone
