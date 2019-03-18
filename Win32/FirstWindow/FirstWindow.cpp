// FirstWindow.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

LRESULT CALLBACK WindowProc(  									
							IN  HWND hwnd,  		//窗口的句柄
							IN  UINT uMsg,  		//消息的类型
							IN  WPARAM wParam,  		
							IN  LPARAM lParam  		
							);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	DbgPrintf("Hello World:%s\n",lpCmdLine);//打印命令行参数

 	//创建一个自己的窗口
	TCHAR className[]=TEXT("My First Window");

	WNDCLASS wndclass = {0};						//一定要先将所有值赋值
	wndclass.hbrBackground = (HBRUSH)COLOR_MENU;	//窗口的背景色
	wndclass.lpfnWndProc = WindowProc;				//窗口过程函数
	wndclass.lpszClassName = className;				//窗口类的名字
	wndclass.hInstance = hInstance;				    //定义窗口类的应用程序的实例句柄


	//注册窗口类
	RegisterClass(&wndclass);  
	
	// 创建窗口  							
	HWND hwnd = CreateWindow(  							
		className,							//类名		
		TEXT("我的第一个窗口"),				//窗口标题		
		WS_OVERLAPPEDWINDOW,				//窗口外观样式 		
		10,									//相对于父窗口的X坐标		
		10,									//相对于父窗口的Y坐标		
		600,								//窗口的宽度  		
		300,								//窗口的高度  		
		NULL,								//父窗口句柄，为NULL  		
		NULL,								//菜单句柄，为NULL  		
		hInstance,							//当前应用程序的句柄  		
		NULL);								//附加数据一般为NULL		
								
	if(hwnd == NULL)					//是否创建成功  		
		return 0;  	
	
	// 显示窗口  		
	ShowWindow(hwnd, SW_SHOW);  		

	//消息循环
	MSG msg;  			
	while(GetMessage(&msg, NULL, 0, 0))  			
	{  			
		TranslateMessage(&msg);  		
		DispatchMessage(&msg);  		
	}  			


	return 0;
}


LRESULT CALLBACK WindowProc(  									
							IN  HWND hwnd,  		//窗口的句柄
							IN  UINT uMsg,  		//消息的类型
							IN  WPARAM wParam,  		
							IN  LPARAM lParam  		
							)  		
{  									
	switch(uMsg)								
	{								
		//窗口消息							
	case WM_CREATE: 								
		{							
			DbgPrintf("WM_CREATE %d %d\n",wParam,lParam);						
			CREATESTRUCT* createst = (CREATESTRUCT*)lParam;						
			DbgPrintf("CREATESTRUCT %s\n",createst->lpszClass);						
			DbgPrintf("窗口名 %s\n",createst->lpszName);						
						
			return 0;						
		}							
	case WM_MOVE:								
		{							
			DbgPrintf("WM_MOVE %d %d\n",wParam,lParam);						
			POINTS points = MAKEPOINTS(lParam);						
			DbgPrintf("X Y %d %d\n",points.x,points.y);						
									
			return 0;						
		}							
	case WM_SIZE:								
		{							
			DbgPrintf("WM_SIZE %d %d\n",wParam,lParam);						
			int newWidth  = (int)(short) LOWORD(lParam);    						
			int newHeight  = (int)(short) HIWORD(lParam);   						
			DbgPrintf("WM_SIZE %d %d\n",newWidth,newHeight);						
									
			return 0;						
		}							
	case WM_DESTROY:								
		{							
			DbgPrintf("WM_DESTROY %d %d\n",wParam,lParam);						
			PostQuitMessage(0);						
									
			return 0;						
		}							
		//键盘消息							
	case WM_KEYUP:								
		{							
			DbgPrintf("WM_KEYUP %d %d\n",wParam,lParam);						
									
			return 0;						
		}							
	case WM_KEYDOWN:								
		{							
			DbgPrintf("WM_KEYDOWN %d %d\n",wParam,lParam);						
									
			return 0;						
		}							
		//鼠标消息							
	case WM_LBUTTONDOWN:								
		{							
			DbgPrintf("WM_LBUTTONDOWN %d %d\n",wParam,lParam);						
			POINTS points = MAKEPOINTS(lParam);						
			DbgPrintf("WM_LBUTTONDOWN %d %d\n",points.x,points.y);						
									
			return 0;						
		}							
	}								
	return DefWindowProc(hwnd,uMsg,wParam,lParam);								
}  									



