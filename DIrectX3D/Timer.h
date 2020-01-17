#pragma once
#include <chrono>
class Timer
{
private:
    typedef std::chrono::time_point<std::chrono::steady_clock> TimePoint;
    TimePoint mPrevCalled;

public:
    Timer() noexcept : mPrevCalled(std::chrono::steady_clock::now()) {}
    /*
    Get the different between current time and last call to Update()
    Assign counter to the current time
    */
    float Update() noexcept;
    // get the different between counter and current time
    float Peek() const noexcept;
};

