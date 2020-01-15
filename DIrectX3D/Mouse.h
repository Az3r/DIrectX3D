#pragma once
#include <bitset>
#include <vector>



class MouseState
{
private:
    static constexpr unsigned short BIT_LB_PRESSED = 0;
    static constexpr unsigned short BIT_LB_DOWN = 1;
    static constexpr unsigned short BIT_LB_RELEASED = 2;

    static constexpr unsigned short BIT_RB_PRESSED = 3;
    static constexpr unsigned short BIT_RB_DOWN = 4;
    static constexpr unsigned short BIT_RB_RELEASED = 5;

    static constexpr unsigned short BIT_MB_PRESSED = 6;
    static constexpr unsigned short BIT_MB_DOWN = 7;
    static constexpr unsigned short BIT_MB_RELEASED = 8;

    static constexpr unsigned short BIT_MOUSE_WHEEL = 9;
    static constexpr unsigned short BIT_MOUSE_ENTER = 10;
    static constexpr unsigned short BIT_MOUSE_LEAVE = 10;
    static constexpr unsigned short BIT_MOUSE_CAPTURE = 10;

private:
    std::bitset<10> mStates;

public:
    MouseState() noexcept : mStates() {}


    



};








class MouseEventArg
{








};









class Mouse
{

};

