#include "pch.h"
#include "Mouse.h"

void Mouse::OnWheelUp() noexcept
{
    // TODO: optional implementation here
}

void Mouse::OnWheelDown() noexcept
{
    // TODO: optional implementation here
}

void Mouse::OnCapture() noexcept
{
    mCapture = true;
    // TODO: optional implementation here
}

void Mouse::OnReleaseCapture() noexcept
{
    mCapture = false;
    // TODO: optional implementation here
}

void Mouse::OnMouseEnter(int x, int y) noexcept
{
    mOverWindow = true;
    // TODO: optional implementation here
}

void Mouse::OnMouseLeave(int x, int y) noexcept
{
    mOverWindow = false;
    // TODO: optional implementation here
}

void Mouse::OnMouseDown(unsigned char button, int x, int y) 
{
    GetMouseState(button) = true;
    // TODO: optional implementation here
}

void Mouse::OnMouseReleased(unsigned char button, int x, int y)
{
    GetMouseState(button) = false;
    // TODO: optional implementation here
}

void Mouse::OnMouseMove(int x, int y) noexcept
{
    mPosition = { x,y };
}

bool Mouse::GetMouseState(unsigned char button) const
{
    assert(button < 256, "button must be in range of [0,255]");
    return mButtons.at(button);
}

bool& Mouse::GetMouseState(unsigned char button)
{
    assert(button < 256, "button must be in range of [0,255]");
    return mButtons.at(button);
}
