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
    mCaptured = true;
    // TODO: optional implementation here
}

void Mouse::OnReleaseCapture() noexcept
{
    mCaptured = false;
    // TODO: optional implementation here
}

void Mouse::OnMouseEnter(int x, int y) noexcept
{
    mOverClient = true;
    // TODO: optional implementation here
}

void Mouse::OnMouseLeave(int x, int y) noexcept
{
    mOverClient = false;
    // TODO: optional implementation here
}

void Mouse::OnMouseDown(unsigned char button, int x, int y) 
{
    SetMouseState(button, true);
    // TODO: optional implementation here
}

void Mouse::OnMouseReleased(unsigned char button, int x, int y)
{
    SetMouseState(button, false);
    // TODO: optional implementation here
}

void Mouse::OnMouseMove(int x, int y) noexcept
{
    mPosition = { (SHORT)x,(SHORT)y };
}

bool Mouse::GetMouseState(unsigned char button) const
{
    ASSERT(button < 256, "button must be in range of [0,255]");
    return mButtons.at(button);
}

void Mouse::SetMouseState(unsigned char button, bool isDown)
{
    ASSERT(button < 256, "button must be in range of [0,255]");
    mButtons.at(button) = isDown;
}

