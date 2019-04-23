#include <windows.h>

LRESULT CALLBACK WndProc(
	HWND hwndDlg,  // handle to dialog box			
	UINT uMsg,     // message			
	WPARAM wParam, // first message parameter			
	LPARAM lParam  // second message parameter			
);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {
		static TCHAR szAppName[] = TEXT("MyWindows");
		WNDCLASS wndClass;
	    HWND hwnd;
	    MSG Msg;
	
	     //Step 1: Registering the Window Class
		 wndClass.style = CS_HREDRAW | CS_VREDRAW;
		 wndClass.lpfnWndProc = WndProc;
		 wndClass.cbClsExtra = 0;
		 wndClass.cbWndExtra = 0;
		 wndClass.hInstance = hInstance;
		 wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		 wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		 wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		 wndClass.lpszMenuName = NULL;
		 wndClass.lpszClassName = szAppName;
		 
	
	     if (!RegisterClass(&wndClass))
		     {
		         MessageBox(NULL, TEXT("Window Registration Failed!"),TEXT( "Error!"),
	             MB_ICONEXCLAMATION | MB_OK);
		         return 0;
		     }

		hwnd = CreateWindow(szAppName,
			          TEXT("The title of my window"),
			          WS_OVERLAPPEDWINDOW,
			          CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
			          NULL, NULL, hInstance, NULL);
		 
		if (hwnd == NULL){
			  MessageBox(NULL, TEXT("Window Creation Failed!"), TEXT("Error!"),MB_ICONEXCLAMATION | MB_OK);
			  return 0;
		}
		 
		ShowWindow(hwnd, nCmdShow);
		UpdateWindow(hwnd);
		 
		// Step 3: The Message Loop
		while (GetMessage(&Msg, NULL, 0, 0) > 0){
			          TranslateMessage(&Msg);
			          DispatchMessage(&Msg);
			}
		return Msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	switch (uMsg)
	   {
			 case WM_PAINT:
				 hdc = BeginPaint(hwndDlg,&ps);
				 GetClientRect(hwndDlg,&rect);
				 DrawText(hdc,TEXT("大家好，这是我的第一个程序！"),-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
				 EndPaint(hwndDlg, &ps);
				 return 0;
	         case WM_CLOSE:
	             DestroyWindow(hwndDlg);
		         break;
	         case WM_DESTROY:
	             PostQuitMessage(0);
		         break;
	         default:
	            return DefWindowProc(hwndDlg, uMsg, wParam, lParam);
		    }

	return 0;
}
