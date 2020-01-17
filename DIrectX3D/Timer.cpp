#include "pch.h"
#include "Timer.h"

float Timer::Update() noexcept
{
    TimePoint last = mStopWatch;
    mStopWatch = std::chrono::steady_clock::now();

    std::chrono::duration<float> offset = std::chrono::duration<float>(mStopWatch - last);
    return offset.count();
}

float Timer::Peek() const noexcept
{
    std::chrono::duration<float> offset = std::chrono::steady_clock::now() - mStopWatch;
    return offset.count();
}
