#pragma once
#include <memory>
#include <QtCore/QObject>
#include <QtCore/QFutureWatcher>
#include "corecontext.h"


using ContextFuture = QFutureWatcher<ContextPtr>;
using ContextFutureUnq = std::unique_ptr<ContextFuture>;


class Entity
    : public QObject
{
    Q_OBJECT
public:
    Entity(ContextPtr context);
    Entity(ContextFutureUnq future);

private slots:
    void setCoreContext(ContextPtr context);

private:
    ContextPtr context_;
};
