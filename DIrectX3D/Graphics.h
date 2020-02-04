#pragma once

#include <d3d11.h>
#include <wrl.h>
class Graphics
{
private:
    typedef Microsoft::WRL::ComPtr<ID3D11Device> PDevice;
    typedef Microsoft::WRL::ComPtr<IDXGISwapChain> PSwapChain;
    typedef Microsoft::WRL::ComPtr<ID3D11DeviceContext> PDeviceContext;

    PDevice m_pDevice;
    PSwapChain m_pSwapChain;
    PDeviceContext m_pContext;
    HWND mHWND = nullptr;

public:
    Graphics(HWND hwnd) noexcept : mHWND(hwnd)  {}
    Graphics(const Graphics&) = delete;
    Graphics& operator=(const Graphics&) = delete;
    ~Graphics() {}

    inline const HWND& GetHWND() const noexcept { return mHWND; }
     

    void Draw() { m_pSwapChain->Present(1u, 0u); }

    // must be called before any other functions
    HRESULT Initialize() noexcept;
};

