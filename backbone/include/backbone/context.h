#pragma once
#include <memory>


class Context
{
public:
    Context();
};


using ContextShared = std::shared_ptr<Context>;
using ContextWeak = std::weak_ptr<Context>;
