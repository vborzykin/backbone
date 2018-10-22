#include "corecontext.h"
#include <QtCore/QDebug>


namespace {

int counter = 0;

}


CoreContext::CoreContext()
    : number(counter++)
{
    qDebug() << "++ CoreContext " << number;
}


CoreContext::~CoreContext()
{
    qDebug() << "-- CoreContext " << number;
}
