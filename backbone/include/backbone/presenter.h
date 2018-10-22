#pragma once
#include <QtCore/QObject>
#include <QtGui/QKeyEvent>


class Presenter
    : public QObject
{
    Q_OBJECT

public:
    Presenter(QObject * parent = nullptr);

    virtual void keyPressEvent(QKeyEvent * )
    {}

private:
};
