#include "pch.h"
#include "Game.h"

int Game::Update() noexcept
{
	//if (mKeyboard.IsKeyDown(VK_MENU)) this->SetTitle(this->GetTitle() + L'a');
	mGfx->Draw();
	return 0;
}

int Game::InitInstance()
{
	WinApp::InitInstance();
	mGfx = std::make_unique<Graphics>(this->GetHWND());
	try_throw(mGfx->Initialize());
    return 0;
}

int Game::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (true)
	{
		while (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) return msg.wParam;

			TranslateMessage(&msg);
			DispatchMessageW(&msg);

		}
		Update();
	}


	return 0;
}
