#pragma once

namespace view
{
    class ITimer
    {
    public:
        virtual void Start() = 0;

        virtual void Stop() = 0;
    };
}