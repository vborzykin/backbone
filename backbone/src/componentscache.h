#pragma once
#include <QtCore/QHash>
#include <QtCore/QObject>
#include <QtCore/QUrl>
#include <QtQml/QQmlComponent>


namespace Backbone {


class ComponentsCache
    : public QObject
{
public:
    // TODO: pc::future?

signals:
    void componentReady(QUrl url, QQmlComponent * component);

private:
    QHash<QUrl, QQmlComponent*> cache_;
};


} // namespace Backbone
