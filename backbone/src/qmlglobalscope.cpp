#include <backbone/qmlglobalscope.h>


namespace Backbone {


QmlGlobalScope::QmlGlobalScope(AppController * controller, Router * router, QObject * parent)
    : QObject(parent)
    , appController_(controller)
    , router_(router)
{
}


} // namespace Backbone
