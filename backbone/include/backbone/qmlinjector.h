#pragma once
#include <functional>
#include <memory>
#include <string_view>
#include <unordered_map>

#include <QtCore/QObject>
#include <QtCore/QDebug>


namespace Backbone {


using Creator = std::function<QObject*()>;
using TypeName = std::string;
using FactoryCollection = std::unordered_map<TypeName, Creator>;


class QmlInjector
{
public:
    QmlInjector(FactoryCollection creators)
        : creators_(std::move(creators))
    {
        qDebug() << "created injector: " << creators_.size();
    }

    QObject * create(std::string name) const;

private:
    const FactoryCollection creators_;
};

using QmlInjectorUnq = std::unique_ptr<QmlInjector>;

} // namespace Backbone
