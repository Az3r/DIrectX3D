#pragma once
#include "Exception.h"

class DirectXException : public Exception
{
public:
    DirectXException(std::string msg, int line, const char* file, std::string name = "DirectX Exception") noexcept : Exception(msg, line, file, name) {}
    DirectXException(HRESULT hr, int line, const char* file, std::string name = "DirectX Exception") noexcept : Exception (static_cast<DWORD>(hr), line, file, name) {}
};

#define DIRECTX_THROW(msg) throw DirectXException(msg, __LINE__, __FILE__)
#define DIRECTX_THROW_IF_FAILED(hr) if(FAILED(hr)) throw DirectXException(hr, __LINE__, __FILE__)

