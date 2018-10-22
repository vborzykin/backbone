#include <backbone/container.h>


namespace Backbone {


void Container::setArgs(QVariantMap args)
{
    args_.swap(args);
}


} // namespace Backbone

