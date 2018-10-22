#pragma once
#include <functional>
#include <QtCore/QObject>
#include <QtQml/QQmlComponent>

QT_FORWARD_DECLARE_CLASS(QQmlContext)
QT_FORWARD_DECLARE_CLASS(QQmlEngine)


namespace Backbone {


using InjectorCallback = std::function<void(QObject*)>;


class Incubator
    : public QObject
{
    Q_OBJECT

public:
    Incubator(QQmlEngine*, QQmlContext *, const QUrl & url, InjectorCallback callback);
    Incubator(QQmlComponent *, QQmlContext *, InjectorCallback callback);

    QQmlComponent * component() const { return component_; }

signals:
    void ready(QObject *, QString errorString);

private slots:
    bool onComponentStatusChanged(QQmlComponent::Status);

private:
    QQmlComponent * const component_ = nullptr;
    QQmlContext * const context_ = nullptr;
    const InjectorCallback callback_;
};


} // namespace Backbone
