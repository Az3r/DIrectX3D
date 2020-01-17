#pragma once
#include <chrono>
class Timer
{
private:
    typedef std::chrono::time_point<std::chrono::steady_clock> TimePoint;
    TimePoint mCounter;

public:
    Timer() noexcept : mCounter(std::chrono::steady_clock::now()) {}
    // returns the different between counter and current time, counter is updated to current time
    float Update() noexcept;
    // returns the different between counter and current time, counter is not updated
    float Elapsed() const noexcept;
};

