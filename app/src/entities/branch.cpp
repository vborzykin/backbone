#include "branch.h"
#include <QtCore/QRandomGenerator>

namespace {

QLatin1String COLORS[19] = {
    QLatin1String("#f44336"),
    QLatin1String("#EC407A"),
    QLatin1String("#AB47BC"),
    QLatin1String("#7E57C2"),
    QLatin1String("#5C6BC0"),
    QLatin1String("#42A5F5"),
    QLatin1String("#29B6F6"),
    QLatin1String("#26C6DA"),
    QLatin1String("#26A69A"),
    QLatin1String("#66BB6A"),
    QLatin1String("#9CCC65"),
    QLatin1String("#D4E157"),
    QLatin1String("#FFEE58"),
    QLatin1String("#FFCA28"),
    QLatin1String("#FFA726"),
    QLatin1String("#FF7043"),
    QLatin1String("#8D6E63"),
    QLatin1String("#BDBDBD"),
    QLatin1String("#78909C")
};


} // namespace


Branch::Branch(QObject * parent)
    : QObject(parent)
{
    const auto rg = QRandomGenerator::global();
    const auto idx = rg->generate() % (sizeof(COLORS) / sizeof(COLORS[0]));

    id_ = static_cast<int>(rg->generate());
    color_ = *(COLORS + idx);
}
