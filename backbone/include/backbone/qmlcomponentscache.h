#pragma once
#include <QtCore/QObject>
#include <QtCore/QUrl>
#include <QtCore/QHash>
#include "incubator.h"

QT_FORWARD_DECLARE_CLASS(QQmlEngine)
QT_FORWARD_DECLARE_CLASS(QQmlComponent)


namespace Backbone {


class QmlComponentsCache
    : public QObject
{
    Q_OBJECT
public:
    QmlComponentsCache(QQmlEngine * engine);
    ~QmlComponentsCache() = default;

    Incubator * create(const QUrl & url);

    Incubator * create(const QUrl & url, InjectorCallback injector);

    // TODO: trimMemory slot

private:
    QQmlEngine * const engine_ = nullptr;
    QHash<QUrl, QQmlComponent*> cache_;
};


} // namespace Backbone
