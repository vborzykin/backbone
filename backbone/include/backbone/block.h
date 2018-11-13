#pragma once
#include "container.h"


namespace Backbone {


class Block
    : public Container
{
    Q_OBJECT
    Q_PROPERTY(bool autoload READ autoload WRITE setAutoload NOTIFY autoloadChanged FINAL)

public:
    bool autoload() const;
    void setAutoload(bool autoload);

    void classBegin() override;
    void componentComplete() override;

signals:
    void autoloadChanged();

private:
    bool autoload_ = true;
};


} // namespace Backbone
