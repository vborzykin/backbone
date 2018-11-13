#pragma once
#include <QtCore/QList>
#include <QtCore/QObject>

#include <backbone/pagepresenter.h>
#include <entities/branch.h>
#include <usecases/usersearchusecase.h>


using DataCollection = QList<Branch*>;


class SearchPagePresenter
    : public Backbone::PagePresenter
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> model READ model CONSTANT FINAL)

public:
    SearchPagePresenter();

    void onCreate(QQuickItem * view, const QVariantMap & args) override;

    QList<QObject*> model() const;

public slots:
    void selectItem(int index);

private:
    QList<QObject*> collection_;
    UserSearchUsecasePtr searchUsecase_;
};
