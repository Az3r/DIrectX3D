#include "pch.h"
#include "Keyboard.h"

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

void Keyboard::OnKeyDown(unsigned char key)
{
    this->GetState(key) = std::bitset<3>("100");
}

void Keyboard::OnKeyPressed(unsigned char key)
{
    this->GetState(key) = std::bitset<3>("110");
}

void Keyboard::OnKeyReleased(unsigned char key)
{
    this->GetState(key) = std::bitset<3>("001");
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
