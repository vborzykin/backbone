#pragma once
#include <memory>
#include <vector>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QFutureWatcher>


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

using SearchResult = std::vector<ContextPtr>;
using SearchResultPtr = std::shared_ptr<SearchResult>;

using SearchFuture = QFutureWatcher<SearchResultPtr>;
using SearchFutureUnq = std::unique_ptr<SearchFuture>;


Q_DECLARE_METATYPE(ContextPtr)
