#pragma once
#include <QtCore/QObject>
#include <QtCore/QSharedPointer>
#include <QtCore/QVariantMap>


namespace Backbone {


struct Args
{
    Args() = default;
    Args(QVariantMap m) : members(std::move(m)) {}

    QVariantMap members;
};


using ArgsPtr = QSharedPointer<Args>;
using ArgsWeakPtr = QWeakPointer<Args>;


class ArgsWeakWrapper
{
    Q_GADGET

public:
    ArgsWeakPtr args;
};


} // namespace Backbone


Q_DECLARE_METATYPE(Backbone::ArgsWeakWrapper)
