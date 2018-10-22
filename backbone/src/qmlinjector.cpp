#include <backbone/qmlinjector.h>


namespace Backbone {


QObject * QmlInjector::create(std::string name) const
{
    auto it = creators_.find(name);
    if (it != creators_.end())
    {
        if (auto ptr = it->second())
        {
            ptr->setObjectName(QString::fromStdString(name));
            return ptr;
        }
    }
    return nullptr;
}


} // namespace Backbone
