#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class Input;
class Graphics;

class System
{
public:
	System();
	~System();

	bool Initialise();
	void Run() const;

	LRESULT CALLBACK MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam) const;

private:
	bool Frame() const;
	void InitialiseWindows(int& screenWidth, int& screenHeight);
	void ShutdownWindows();

	const wchar_t* _applicationName;
	HINSTANCE _pHinstance;
	HWND _pHwnd;
	Input* _pInput;
	Graphics* _pGraphics;
};

static LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam);

static System* ApplicationHandle = nullptr;
