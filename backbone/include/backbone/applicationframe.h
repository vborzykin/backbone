#pragma once
#include <QtQuick/QQuickItem>


namespace Backbone {

// TODO: make it window
class ApplicationFrame
    : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QQuickItem * navigationView MEMBER navigationView_ NOTIFY navigationViewChanged FINAL)
public:
    ApplicationFrame();

signals:
    void navigationViewChanged();

public slots:
    void start();

private:
    QQuickItem * navigationView_ = nullptr;
};


} // namespace Backbone
