#include "pch.h"
#include "Graphics.h"

Graphics::~Graphics()
{
    if (m_pContext) delete m_pContext;
    if (m_pDevice) delete m_pDevice;
    if (m_pSwapChain) delete m_pSwapChain;

}

HRESULT Graphics::Initialize()
{
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(DXGI_SWAP_CHAIN_DESC));

}
