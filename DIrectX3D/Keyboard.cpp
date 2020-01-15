#include "pch.h"
#include "Keyboard.h"

int Keyboard::ReadKeys() noexcept
{
    if (mEventBuffer.empty()) return 0;

    // reset keys' state
    this->Reset();

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

void Keyboard::Reset() const noexcept
{
    for (size_t i = 0; i < mKeys.size(); i++)
    {
        mKeys.at(i) == KeyEventTypes::None;
    }
}

void Keyboard::OnKeyEvent(KeyEventArgs args)
{
    mEventBuffer.push(args);
}

const KeyEventTypes& Keyboard::GetKeyState(unsigned char key) const
{
    assert(key < 256, "key must be in range of [0, 255]");
    return mKeys.at(key);
}
