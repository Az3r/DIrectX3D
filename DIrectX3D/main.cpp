#include "pch.h"
#include "Game.h"

HINSTANCE g_hInstance;
int g_nCmdShow;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    g_hInstance = hInstance;
    g_nCmdShow = nCmdShow;

    WinApp theApp;
    theApp.InitInstance();
    theApp.Run();
    theApp.ExitInstance();
    return 0;
}