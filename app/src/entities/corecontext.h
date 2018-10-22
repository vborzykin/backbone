#pragma once
#include <memory>
#include <QtCore/QObject>
#include <QtCore/QString>


class CoreContext
{
public:
    const int number;
    QString id;

public:
    CoreContext();
    ~CoreContext();

private:
};

using ContextPtr = std::shared_ptr<CoreContext>;

Q_DECLARE_METATYPE(ContextPtr)
