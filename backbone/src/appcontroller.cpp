#include <backbone/appcontroller.h>
#include <QtCore/QDebug>


namespace Backbone {


AppController::AppController(QmlInjectorUnq injector, QObject * parent)
    : QObject(parent)
    , injector_(std::move(injector))
{
}


PagePresenter * AppController::resolvePresenter(const QString & def)
{
    const auto name = def.toStdString();
    return static_cast<PagePresenter*>(injector_->create(name));
}


} // namespace Backbone
