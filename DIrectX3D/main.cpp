#include "WinApp.h"
#include "pch.h"
#include "Exception.h"
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Exception e(-1, __LINE__);
    MessageBoxA(NULL, e.what(), e.name().c_str(), MB_ICONEXCLAMATION);

    return 0;
}