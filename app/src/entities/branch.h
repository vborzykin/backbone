#pragma once
#include <QtCore/QObject>
#include <QtCore/QString>


class Branch
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id CONSTANT FINAL)
    Q_PROPERTY(QString color READ color NOTIFY dataChanged FINAL)

public:
    Branch(QObject * parent = nullptr);

    int id() const { return id_; }
    QString color() const { return color_; }

signals:
    void dataChanged();

private:
    int id_;
    QString color_;
};
