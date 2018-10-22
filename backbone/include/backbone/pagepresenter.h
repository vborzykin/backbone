#pragma once
#include <QtCore/QObject>
#include "router.h"
#include "presenter.h"

QT_FORWARD_DECLARE_CLASS(QQuickItem)

namespace Backbone {


class PagePresenter
    : public Presenter
{
    Q_OBJECT
public:
    explicit PagePresenter(QObject * parent = nullptr);

    // presenter entry point
    virtual void onCreate(QQuickItem * view, const QVariantMap & args);

    virtual void activating();
    virtual void activated();
    virtual void deactivating();
    virtual void deactivated();

    void keyPressEvent(QKeyEvent * event) override;

    void setRouter(Router * router);

protected:
    Router * router = nullptr;

private:
};


} // namespace Backbone


Q_DECLARE_METATYPE(Backbone::PagePresenter*)
