#include "pch.h"
#include "Graphics.h"

HRESULT Graphics::Initialize() noexcept
{
    DXGI_SWAP_CHAIN_DESC sd = {};

    sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
    sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    sd.SampleDesc.Count = 1;
    sd.BufferCount = 1;
    sd.BufferUsage = DXGI_USAGE_BACK_BUFFER;
    sd.OutputWindow = mHWND;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    sd.Windowed = TRUE;

    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        NULL,
        D3D_DRIVER_TYPE_HARDWARE,
        NULL,
        NULL,
        NULL,
        0,
        D3D11_SDK_VERSION,
        &sd,
        &m_pSwapChain,
        &m_pDevice,
        NULL,
        &m_pContext
    );

    return hr;
}
