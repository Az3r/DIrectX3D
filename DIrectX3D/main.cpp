#include "pch.h"
#include "WinApp.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    WinApp theApp(hInstance, nCmdShow);
    theApp.InitInstance();
    theApp.Run();
    theApp.ExitInstance();
    return 0;
}