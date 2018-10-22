#pragma once
#include <backbone/pagepresenter.h>
#include <QtCore/QObject>
#include <QtCore/QList>
#include <entities/branch.h>


using DataCollection = QList<Branch*>;


class SearchPagePresenter
    : public Backbone::PagePresenter
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> model READ model CONSTANT FINAL)

public:
    SearchPagePresenter();

    QList<QObject*> model() const;

public slots:
    void selectItem(int index);

private:
    QList<QObject*> collection_;
};
