#include <Windows.h>

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL) //Macro to get instance

WCHAR		WindowClass[MAX_NAME_STRING];
WCHAR		WindowTitle[MAX_NAME_STRING];

INT			WindowWidth;
INT			WindowHeight;;

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {

	//*** Initialize Global Variables ***//

	wcscpy_s(WindowClass, TEXT("DX12_Engine"));
	wcscpy_s(WindowTitle, TEXT("Window"));
	WindowWidth = 1366;
	WindowHeight = 768;

	//*** Create Window Class ***//

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); //Init windows var
	wcex.style = CS_HREDRAW | CS_VREDRAW;  //Window size
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); //Cursor asset
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH); //Background Color

	wcex.hIcon = LoadIcon(0, IDI_APPLICATION); //Up Left Icon
	wcex.hIconSm = LoadIcon(0, IDI_APPLICATION); //TaskBar Icon

	wcex.lpszClassName = WindowClass; //Assing aplication name

	wcex.lpszMenuName = nullptr; //Menu not assigned, look for documentation online

	wcex.hInstance = HInstance(); //Assing window instance

	wcex.lpfnWndProc = DefWindowProc; //How window is gonna response on user actions

	RegisterClassEx(&wcex);

	//*** Create and display Window ***//

	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr); //Window Handler: Representation of the entire window
	if (!hWnd) {
		MessageBox(0, L"Failed to create Window!", 0, 0);
		return 0;
	}

	ShowWindow(hWnd, SW_SHOW); //Display Window

	//*** Listen for Message events ***//

	MSG msg = { 0 };
	while (msg.message != WM_QUIT) {

		//If there are Window messages then process them.
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}
