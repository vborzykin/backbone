#include <backbone/block.h>


namespace Backbone {


bool Block::autoload() const
{
    return autoload_;
}


void Block::setAutoload(bool autoload)
{
    if (autoload_ != autoload)
    {
        autoload_ = autoload;
        emit autoloadChanged();
    }
}



} // namespace Backbone
