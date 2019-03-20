// FirstWindow.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

HINSTANCE hAppInstance;//将当前程序的ImageBase定义为全局变量，方便各个窗口取用
LRESULT CALLBACK WindowProc(  									
							IN  HWND hwnd,  		//窗口的句柄
							IN  UINT uMsg,  		//消息的类型
							IN  WPARAM wParam,  		
							IN  LPARAM lParam  		
							);

void CreateButton(HWND hwnd)								
{								
	HWND hwndPushButton;							
	HWND hwndCheckBox;							
	HWND hwndRadio;							
								
	hwndPushButton = CreateWindow ( 							
		TEXT("button"),//直接写button是因为windows已经帮我们定义好了按钮的样式 						
		TEXT("普通按钮"),//按钮的显示名字					
		//WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_DEFPUSHBUTTON,						
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_DEFPUSHBUTTON,//按钮的属性					
		10, 10,						
		80, 20,						
		hwnd, 						
		(HMENU)1001,		//子窗口ID，创建母窗口的时候这里是一个句柄，但创建子窗口的时候，这里应该写子窗口编号，用于唯一标识子窗口
		hAppInstance, 						
		NULL);	

	//获取button的WNDCLASS 用于观察系统是如何帮我们创建button类的
	TCHAR szBuffer[0x20];					
	GetClassName(hwndPushButton,szBuffer,0x20);					
						
	WNDCLASS wc;					
	GetClassInfo(hAppInstance,szBuffer,&wc);					
	OutputDebugStringF("-->%s\n",wc.lpszClassName);					
	OutputDebugStringF("-->%x\n",wc.lpfnWndProc);					


	hwndCheckBox = CreateWindow ( 					
	TEXT("button"), 				
	TEXT("复选框"),				
	//WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX,				
	WS_CHILD | WS_VISIBLE | BS_CHECKBOX |BS_AUTOCHECKBOX ,				
	10, 40,				
	80, 20,				
	hwnd, 				
	(HMENU)1002,		//子窗口ID		
	hAppInstance, 				
	NULL);				
					
	hwndRadio = CreateWindow ( 					
		TEXT("button"), 				
		TEXT("单选按钮"),				
		//WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON | BS_AUTORADIOBUTTON,				
		WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON  ,				
		10, 70,				
		80, 20,				
		hwnd, 				
		(HMENU)1003,		//子窗口ID		
		hAppInstance, 				
		NULL);				
					

								
						
} 								


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	hAppInstance=hInstance;
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
	CreateButton(hwnd);
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
	case WM_COMMAND:								
		{								
			switch(LOWORD(wParam))							
			{							
				case 1001://子窗口编号						
					MessageBox(hwnd,"Hello Button 1","Demo",MB_OK);					
					return 0;					
				case 1002:						
					MessageBox(hwnd,"Hello Button 2","Demo",MB_OK);					
					return 0;					
				case 1003:						
					MessageBox(hwnd,"Hello Button 3","Demo",MB_OK);					
					return 0;					
			}							
			return DefWindowProc(hwnd,uMsg,wParam,lParam);							
		}									

	}
	
	return DefWindowProc(hwnd,uMsg,wParam,lParam);								
}  	


								
								



