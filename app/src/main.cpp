#include <backbone/appcontroller.h>
#include <backbone/global.h>
#include <backbone/qmlglobalscope.h>
#include <backbone/qmlinjectorbuilder.h>
#include <backbone/qmlcomponentscache.h>
#include <di/di.hpp>
#include <QtCore/QDebug>
#include <QtCore/QMetaObject>
#include <QtCore/QObject>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>
#include <QtQml/qqml.h>
#include <QtQuickControls2/QQuickStyle>
#include <string_view>
#include <unordered_map>

#include "presenters/detailpagepresenter.h"
#include "presenters/indexpagepresenter.h"
#include "presenters/searchpagepresenter.h"
#include "types.h"


namespace {


} // namespace


Backbone::QmlInjectorUnq registerTypes()
{
    // @uri App.Presenters
    qmlRegisterUncreatableType<IndexPagePresenter>("App.Presenters", 1, 0, "IndexPagePresenter", "should be created in C++");
    qmlRegisterUncreatableType<DetailPagePresenter>("App.Presenters", 1, 0, "DetailPagePresenter", "should be created in C++");
    qmlRegisterUncreatableType<SearchPagePresenter>("App.Presenters", 1, 0, "SearchPagePresenter", "should be created in C++");

    Backbone::import();

    Backbone::QmlInjectorBuilder builder(QLatin1String("App.Presenters"));
    builder
        .add<IndexPagePresenter>("IndexPagePresenter", [] {
            return new IndexPagePresenter();
        })
        .add<DetailPagePresenter>("DetailPagePresenter", [] {
            return new DetailPagePresenter();
        })
        .add<SearchPagePresenter>("SearchPagePresenter", [] {
            // TODO: сделать модуль с аргументом фабрика
            return new SearchPagePresenter();
        });

    return builder.build();
}


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    auto injector = registerTypes();

    QQuickStyle::setStyle(QStringLiteral("Material"));
    QQmlApplicationEngine engine;

    auto controller = new Backbone::AppController(std::move(injector), &engine);
    auto windowUrl = QUrl(QStringLiteral("qrc:/qml/main.qml"));

    auto cache = new Backbone::QmlComponentsCache(&engine);
    auto router = new Backbone::Router(&engine, cache, std::move(windowUrl));
    auto scope = new Backbone::QmlGlobalScope(controller, router, &engine);

    QQmlContext * rootContext = engine.rootContext();
    rootContext->setContextObject(scope);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    qDebug() << "run event loop";
    return app.exec();
}
