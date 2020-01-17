#pragma once

#include <d3d11.h>

class Graphics
{
private:
    ID3D11Device* m_pDevice = nullptr;
    IDXGISwapChain* m_pSwapChain = nullptr;
    ID3D11DeviceContext* m_pContext = nullptr;

    // this must be set before calling to Initialize()
    HWND mHWND = NULL;
public:
    Graphics() = default;
    Graphics(const Graphics&) = delete;
    Graphics& operator=(const Graphics&) = delete;
    ~Graphics();

    inline void SetHWND(HWND hwnd) noexcept { mHWND = hwnd; }
    inline const HWND& GetHWND() const noexcept { return mHWND; }
     
    // call Initialize() before using any below functions
    HRESULT Initialize();

};

