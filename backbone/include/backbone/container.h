#pragma once
#include <QtCore/QObject>
#include <QtQuick/QQuickItem>


namespace Backbone {


class Presenter;


class Container
    : public QQuickItem
{
    Q_OBJECT
public:
    // TODO: contaner creates presenter and injects properties

    void setArgs(QVariantMap args);

protected:
    QVariantMap args_;

private:
    Presenter * presenter_ = nullptr;
};


} // namespace Backbone
