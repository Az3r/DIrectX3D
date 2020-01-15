#include "pch.h"
#include "Keyboard.h"

int Keyboard::ReadKeys() noexcept
{
    if (mEventBuffer.empty()) return 0;
    mKeys.clear();
    int nEvents = 0;
    while (!mEventBuffer.empty())
    {
        const KeyEventArgs& args = mEventBuffer.front();
        mKeys.at(args.GetKeyCode()) = args.GetType();
        mEventBuffer.pop();
        ++nEvents;
    }
    return nEvents;
}

inline void Keyboard::ClearBuffer() noexcept
{
    while (!mEventBuffer.empty()) mEventBuffer.pop();
}
