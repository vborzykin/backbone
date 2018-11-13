#include "usersearchusecase.h"
#include <QtConcurrent/QtConcurrentRun>
#include <QtCore/QThread>


SearchFutureUnq searchByText(QString pattern)
{
    Q_UNUSED(pattern);

    auto future = QtConcurrent::run([]() -> SearchResultPtr {
        QThread::sleep(2);

        auto searchResultPtr = std::make_shared<SearchResult>();
        return searchResultPtr;
    });

    auto watcher = std::make_unique<SearchFuture>();
    watcher->setFuture(std::move(future));

    return watcher;
}


void UserSearchUsecase::search(QString pattern)
{
    auto future = ::searchByText(pattern).release();

    // TODO: create usecase
    // hold it as shared_ptr and move as page parameters
    connect(future, &SearchFuture::finished, future, &SearchFuture::deleteLater);
    connect(future, &SearchFuture::finished, [] {
        qDebug() << "search future finished ";
    });
}
