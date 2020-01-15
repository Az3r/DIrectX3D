#include "pch.h"
#include "WinApp.h"
#include <windowsx.h>

std::wstring WinApp::sClassName = L"WndClass";

LRESULT WinApp::SetupWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	WinApp* lpWinApp = nullptr;
	if (msg == WM_NCCREATE)
	{
		LPCREATESTRUCT lpcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
		lpWinApp = static_cast<WinApp*> (lpcs->lpCreateParams);
		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(lpWinApp));
	}
	else lpWinApp = reinterpret_cast<WinApp*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	if (lpWinApp) return lpWinApp->WndProc(hwnd, msg, wParam, lParam);
	else return DefWindowProc(hwnd, msg, wParam, lParam);
}
ATOM WinApp::RegisterWndClassEx()
{
	ZeroMemory(&mWC, sizeof(mWC));

	mWC.cbSize = sizeof(WNDCLASSEX);
	mWC.hInstance = g_hInstance;
	mWC.lpfnWndProc = WinApp::SetupWndProc;
	mWC.lpszClassName = sClassName.c_str();

	return RegisterClassEx(&mWC);
}

void WinApp::Move(int width, int height, int x, int y)
{
	BOOL result = MoveWindow(mHWND, x, y, width, height, TRUE);
	assert(result, Exception::TranslateErrorCode(GetLastError()));

	mWidth = width;
	mHeight = height;
	mLeft = x;
	mTop = y;
}

int WinApp::Start()
{
	try
	{
		InitInstance();
		Run();
		ExitInstance();
	}
	catch (const Exception & e)
	{
		MessageBoxA(NULL, e.what(), e.name().c_str(), MB_ICONEXCLAMATION);
	}
	catch (const std::exception& ex)
	{
		MessageBoxA(NULL, ex.what(),"Standard Exception", MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBoxA(NULL, "Unknown Exception", "Unknown Exception", MB_ICONEXCLAMATION);
	}

	return 0;
}

void WinApp::SetTitle(std::wstring title) noexcept
{
	mTitle = title;
	SetWindowText(mHWND, mTitle.c_str());
}

int WinApp::InitInstance()
{
	Exception::throw_if_false((BOOL)RegisterWndClassEx(), Exception::TranslateErrorCode(GetLastError()), __LINE__, __FILE__, "Window Registeration Failure");

	mHWND = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		sClassName.c_str(),
		mTitle.c_str(),
		WS_OVERLAPPEDWINDOW,
		mLeft, mTop, mWidth, mHeight,
		NULL,
		NULL,
		g_hInstance,
		this
	);


	Exception::throw_if_false((BOOL)mHWND, Exception::TranslateErrorCode(GetLastError()), __LINE__, __FILE__, "Window Creation Failure");

	ShowWindow(mHWND, g_nCmdShow);
	UpdateWindow(mHWND);

	return 0;
}

int WinApp::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	BOOL result;

	while (result = GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);

		//if (mKeyboard.IsKeyDown(VK_MENU)) this->SetTitle(this->GetTitle() + L'a');
		if (mMouse.IsLeftMouseDown()) this->SetTitle(this->GetTitle() + L'a');
	}

	if (result < 0) return -1;
	else return msg.wParam;
}

int WinApp::ExitInstance()
{
	BOOL result = UnregisterClass(sClassName.c_str(), g_hInstance);
	Exception::throw_if_false(result, Exception::TranslateErrorCode(GetLastError()), __LINE__, __FILE__, "Unregisteration Failure");
	return 0;
}

LRESULT WinApp::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
	{
		PAINTSTRUCT painter;
		HDC hdc = BeginPaint(hwnd, &painter);

		RECT rect;
		GetClientRect(hwnd, &rect);

		FillRect(hdc, &rect, CreateSolidBrush(RGB(0x69, 0x69, 0x69)));

		EndPaint(hwnd, &painter);
		return 0;
	}
	case WM_KEYDOWN:
	{
		unsigned char key = static_cast<unsigned char>(wParam);

		// check whether this key is previously down or up
		bool prevDown = lParam & 0x40000000;
		if (prevDown) mKeyboard.OnKeyDown(key);
		else mKeyboard.OnKeyPressed(key);

		return 0;
	}
	case WM_SYSKEYDOWN:
	{
		unsigned char key = static_cast<unsigned char>(wParam);

		// check whether this key is previously down or up
		bool prevDown = lParam & 0x40000000;
		if (prevDown) mKeyboard.OnKeyDown(key);
		else mKeyboard.OnKeyPressed(key);

		return 0;
	}
	case WM_KEYUP:
		mKeyboard.OnKeyReleased(static_cast<unsigned char>(wParam));
		return 0;
	case WM_SYSKEYUP:
		mKeyboard.OnKeyReleased(static_cast<unsigned char>(wParam));
		return 0;
	case WM_KILLFOCUS:
		mKeyboard.Reset();
		return 0;
	case WM_LBUTTONUP:
	{
		POINTS pos = MAKEPOINTS(lParam);
		mMouse.OnMouseReleased(VK_LBUTTON, pos.x, pos.y);
		return 0;
	}
	case WM_RBUTTONUP:
	{
		POINTS pos = MAKEPOINTS(lParam);
		mMouse.OnMouseReleased(VK_RBUTTON, pos.x, pos.y);
		return 0;
	}
	case WM_MBUTTONUP:
	{
		POINTS pos = MAKEPOINTS(lParam);
		mMouse.OnMouseReleased(VK_MBUTTON, pos.x, pos.y);
		return 0;
	}
	case WM_XBUTTONUP:
	{
		POINTS pos = MAKEPOINTS(lParam);
		WORD button = GET_XBUTTON_WPARAM(wParam);
		if (button == XBUTTON1) mMouse.OnMouseReleased(VK_XBUTTON1, pos.x, pos.y);
		else mMouse.OnMouseReleased(VK_XBUTTON2, pos.x, pos.y);
		return TRUE;
	}
	case WM_LBUTTONDOWN:
	{
		POINTS pos = MAKEPOINTS(lParam);
		mMouse.OnMouseDown(VK_LBUTTON, pos.x, pos.y);
		return 0;
	}
	case WM_RBUTTONDOWN:
	{
		POINTS pos = MAKEPOINTS(lParam);
		mMouse.OnMouseDown(VK_RBUTTON, pos.x, pos.y);
		return 0;
	}
	case WM_MBUTTONDOWN:
	{
		POINTS pos = MAKEPOINTS(lParam);
		mMouse.OnMouseDown(VK_MBUTTON, pos.x, pos.y);
		return 0;
	}
	case WM_XBUTTONDOWN:
	{
		POINTS pos = MAKEPOINTS(lParam);
		WORD button = GET_XBUTTON_WPARAM(wParam);
		if (button == XBUTTON1) mMouse.OnMouseDown(VK_XBUTTON1, pos.x, pos.y);
		else mMouse.OnMouseDown(VK_XBUTTON2, pos.x, pos.y);
		return TRUE;
	}
	case WM_MOUSEHOVER:
	{
		POINTS pos = MAKEPOINTS(lParam);
		mMouse.OnMouseEnter(pos.x, pos.y);
		return 0;
	}
	case WM_MOUSELEAVE:
	{
		POINTS pos = MAKEPOINTS(lParam);
		mMouse.OnMouseEnter(pos.x, pos.y);
		return 0;
	}
	case WM_MOUSEMOVE:
	{
		POINTS pos = MAKEPOINTS(lParam);
		mMouse.OnMouseMove(pos.x, pos.y);
		return 0;
	}
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

WinApp::WinApp(std::wstring title) noexcept : WinApp()
{
	mTitle = title;
}

WinApp::WinApp(std::wstring title, int width, int height) noexcept : WinApp(title)
{
	mWidth = width;
	mHeight = height;
}

WinApp::WinApp(std::wstring title, int width, int height, int x, int y) noexcept : WinApp(title, width, height)
{
	mLeft = x;
	mTop = y;
}

WinApp::WinApp(int width, int height) noexcept : WinApp()
{
	mWidth = width;
	mHeight = height;
}

WinApp::WinApp(int width, int height, int x, int y) noexcept : WinApp(L"Desktop Application", width, height, x, y)
{
}
