#pragma once

#include <d3d11.h>
#include <wrl.h>
class Graphics
{
private:
    typedef Microsoft::WRL::ComPtr<ID3D11Device> PDevice;
    typedef Microsoft::WRL::ComPtr<IDXGISwapChain> PSwapChain;
    typedef Microsoft::WRL::ComPtr<ID3D11DeviceContext> PDeviceContext;

    PDevice m_pDevice = nullptr;
    PSwapChain m_pSwapChain = nullptr;
    PDeviceContext m_pContext = nullptr;

    HWND mHWND = nullptr;
public:
    Graphics(HWND hwnd) noexcept : mHWND(hwnd) {}
    Graphics(const Graphics&) = delete;
    Graphics& operator=(const Graphics&) = delete;
    ~Graphics() {}

    inline const HWND& GetHWND() const noexcept { return mHWND; }
     
    // must be called before any other functions
    HRESULT Initialize();
};

