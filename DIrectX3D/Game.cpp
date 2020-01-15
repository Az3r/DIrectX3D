#include "pch.h"
#include "Game.h"

int Game::Update() noexcept
{
	//if (mKeyboard.IsKeyDown(VK_MENU)) this->SetTitle(this->GetTitle() + L'a');
	if (mMouse.IsLeftMouseDown()) this->SetTitle(this->GetTitle() + L'a');
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

			Update();
		}
	}


	return 0;
}
