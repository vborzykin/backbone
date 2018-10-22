#include <backbone/qmlinjectorbuilder.h>


namespace Backbone {


QmlInjectorBuilder::QmlInjectorBuilder(QLatin1String ns)
    : qmlNamespace_(std::move(ns))
{
}


QmlInjectorUnq QmlInjectorBuilder::build()
{
    return std::make_unique<QmlInjector>(std::move(items_));
}


} // namespace Backbone
