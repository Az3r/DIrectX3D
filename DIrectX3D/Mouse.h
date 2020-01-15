#pragma once
#include <bitset>
#include <vector>
#include <queue>
#include <Windows.h>

class Mouse
{
private:
    // control the state of each mouse button: left, right, middle, X1, X2
    std::vector<bool> mButtons;

    // whether the mouse is over window's client or not
    bool mOverWindow;

    // whether the mouse is being captured or not
    bool mCaptured;

    POINTS mPosition;

public:
    Mouse() noexcept : mButtons(256), mPosition({ 0,0 }), mCaptured(false), mOverWindow(false) {}

    void OnWheelUp() noexcept;
    void OnWheelDown() noexcept;

    void OnCapture() noexcept;
    void OnReleaseCapture() noexcept;

    void OnMouseEnter(int x, int y) noexcept;
    void OnMouseLeave(int x, int y) noexcept;

    void OnMouseDown(unsigned char button, int x, int y);
    void OnMouseReleased(unsigned char button, int x, int y);

    void OnMouseMove(int x, int y) noexcept;

    bool GetMouseState(unsigned char button) const;
    bool& GetMouseState(unsigned char button);

    inline bool IsLeftMouseDown() const noexcept { return GetMouseState(VK_LBUTTON); }
    inline bool IsLeftMouseReleased() const noexcept { return !GetMouseState(VK_LBUTTON); }

    inline bool IsRightMouseDown() const noexcept { return GetMouseState(VK_RBUTTON); }
    inline bool IsRightMouseReleased() const noexcept { return !GetMouseState(VK_RBUTTON); }

    inline bool IsMiddleMouseDown() const noexcept { return GetMouseState(VK_MBUTTON); }
    inline bool IsMiddleMouseReleased() const noexcept { return !GetMouseState(VK_MBUTTON); }

    inline bool IsX1MouseDown() const noexcept { return GetMouseState(VK_XBUTTON1); }
    inline bool IsX1MouseReleased() const noexcept { return !GetMouseState(VK_XBUTTON1); }

    inline bool IsX2MouseDown() const noexcept { return GetMouseState(VK_XBUTTON2); }
    inline bool IsX2MouseReleased() const noexcept { return !GetMouseState(VK_XBUTTON2); }

    inline bool IsOverClient() const noexcept { return mOverWindow; }
    inline bool IsCaptured() const noexcept { return mCaptured; }
    inline const POINTS& GetPosition() const noexcept { return mPosition; }
};

