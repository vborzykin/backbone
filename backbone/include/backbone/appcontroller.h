#pragma once
#include <QtCore/QObject>
#include <backbone/pagepresenter.h>
#include <backbone/qmlinjector.h>
#include "global.h"


namespace Backbone {


class AppController
    : public QObject
{
    Q_OBJECT
public:
    AppController(QmlInjectorUnq injector, QObject * parent = nullptr);

    Backbone::PagePresenter * resolvePresenter(const QString & name);

private:
    const QmlInjectorUnq injector_;
};


} // namespace Backbone
