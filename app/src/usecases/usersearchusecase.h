#pragma once
#include <memory>
#include <QtCore/QObject>
#include <entities/corecontext.h>


SearchFutureUnq searchByText(QString reference);


class UserSearchUsecase
    : public QObject
{
    Q_OBJECT
public:
    void search(QString pattern);

private:
};


using UserSearchUsecasePtr = std::shared_ptr<UserSearchUsecase>;


Q_DECLARE_METATYPE(UserSearchUsecasePtr)
