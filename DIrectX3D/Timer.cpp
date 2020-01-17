#include "pch.h"
#include "Timer.h"

float Timer::Update() noexcept
{
    TimePoint last = mCounter;
    mCounter = std::chrono::steady_clock::now();

    std::chrono::duration<float> offset = std::chrono::duration<float>(mCounter - last);
    return offset.count();
}

float Timer::Elapsed() const noexcept
{
    std::chrono::duration<float> offset = std::chrono::steady_clock::now() - mCounter;
    return offset.count();
}
