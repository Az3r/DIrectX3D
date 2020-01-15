#include "pch.h"
#include "Keyboard.h"


void Keyboard::Read() noexcept
{
    if (mEventBuffer.empty()) return;

    unsigned char key = mEventBuffer.front().GetKeyCode();
    const KeyState& state = mEventBuffer.front().GetState();
    this->GetState(key) = state;
    mEventBuffer.pop();
}

inline void Keyboard::ClearBuffer() noexcept
{
    mEventBuffer = std::queue<KeyEventArgs>();
}

void Keyboard::Reset() noexcept
{
    for (size_t i = 0; i < mKeys.size(); i++)
    {
        mKeys.at(i) = KeyState();
    }
}

void Keyboard::OnKeyEvent(KeyEventArgs args)
{
    mEventBuffer.push(args);
}

const KeyState& Keyboard::GetState(unsigned char key) const
{
    assert(key < 256, "key must be in range of [0, 255]");
    return mKeys.at(key);
}

KeyState& Keyboard::GetState(unsigned char key)
{
    assert(key < 256, "key must be in range of [0, 255]");
    return mKeys.at(key);
}
