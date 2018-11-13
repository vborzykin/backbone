#pragma once
#include <QtCore/QObject>
#include <QtQuick/QQuickItem>


namespace Backbone {


class Presenter;


class Container
    : public QQuickItem
{
    Q_OBJECT

    // TODO: set delegate property
    // TODO: set default property

public:
    // TODO: contaner creates presenter and injects properties

    // TODO: remove setArgs
    void setArgs(QVariantMap args);

protected:
    QVariantMap args_;

private:
    Presenter * presenter_ = nullptr;
};


} // namespace Backbone
