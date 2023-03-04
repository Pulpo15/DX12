#include "pch.h"

/* ---------------------------------------- */
/* Global Variables						    */
/* ---------------------------------------- */
#pragma region Global Variables

WCHAR		WindowClass[MAX_NAME_STRING];
WCHAR		WindowTitle[MAX_NAME_STRING];

INT			WindowWidth;
INT			WindowHeight;;

HICON		hIcon;

#pragma endregion
/* ---------------------------------------- */

/* ---------------------------------------- */
/* Pre-Declarations						    */
/* ---------------------------------------- */
#pragma region Pre-Declarations

VOID InitializeVariables();
VOID CreateWindowClass();
VOID InitializeWindow();
VOID MessageLoop();

#pragma endregion
/* ---------------------------------------- */

/* ---------------------------------------- */
/* Operations								*/
/* ---------------------------------------- */
#pragma region Operations

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {

	InitializeVariables();

	CreateWindowClass();

	InitializeWindow();

	MessageLoop();

	return 0;
}

LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam) {
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0); //Stop service when closing window
		break;
	}

	return DefWindowProc(hWnd, message, wparam, lparam);
}

#pragma endregion
/* ---------------------------------------- */

/* ---------------------------------------- */
/* Functions								*/
/* ---------------------------------------- */
#pragma region Functions

VOID InitializeVariables() {
	LoadString(HInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);

	WindowWidth = 1366;
	WindowHeight = 768;
	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON)); //Init icon
}

VOID CreateWindowClass() {
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); //Init windows var
	wcex.style = CS_HREDRAW | CS_VREDRAW;  //Window size
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); //Cursor asset
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH); //Background Color

	wcex.hIcon = hIcon; //Up Left Icon
	wcex.hIconSm = hIcon; //TaskBar Icon

	wcex.lpszClassName = WindowClass; //Assing aplication name

	wcex.lpszMenuName = nullptr; //Menu not assigned, look for documentation online

	wcex.hInstance = HInstance(); //Assing window instance

	wcex.lpfnWndProc = WindowProcess; //How window is gonna response on user actions

	RegisterClassEx(&wcex);
}

VOID InitializeWindow() {
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr); //Window Handler: Representation of the entire window
	if (!hWnd) {
		MessageBox(0, L"Failed to create Window!", 0, 0);
		PostQuitMessage(0);
	}

	ShowWindow(hWnd, SW_SHOW); //Display Window
}

VOID MessageLoop() {
	MSG msg = { 0 };
	while (msg.message != WM_QUIT) {

		//If there are Window messages then process them.
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
#pragma endregion
/* ---------------------------------------- */
