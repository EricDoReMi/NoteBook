// FirstWindow.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

LRESULT CALLBACK WindowProc(  									
							IN  HWND hwnd,  		//���ڵľ��
							IN  UINT uMsg,  		//��Ϣ������
							IN  WPARAM wParam,  		
							IN  LPARAM lParam  		
							);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	DbgPrintf("Hello World:%s\n",lpCmdLine);//��ӡ�����в���

 	//����һ���Լ��Ĵ���
	TCHAR className[]=TEXT("My First Window");

	WNDCLASS wndclass = {0};						//һ��Ҫ�Ƚ�����ֵ��ֵ
	wndclass.hbrBackground = (HBRUSH)COLOR_MENU;	//���ڵı���ɫ
	wndclass.lpfnWndProc = WindowProc;				//���ڹ��̺���
	wndclass.lpszClassName = className;				//�����������
	wndclass.hInstance = hInstance;				    //���崰�����Ӧ�ó����ʵ�����


	//ע�ᴰ����
	RegisterClass(&wndclass);  
	
	// ��������  							
	HWND hwnd = CreateWindow(  							
		className,							//����		
		TEXT("�ҵĵ�һ������"),				//���ڱ���		
		WS_OVERLAPPEDWINDOW,				//���������ʽ 		
		10,									//����ڸ����ڵ�X����		
		10,									//����ڸ����ڵ�Y����		
		600,								//���ڵĿ��  		
		300,								//���ڵĸ߶�  		
		NULL,								//�����ھ����ΪNULL  		
		NULL,								//�˵������ΪNULL  		
		hInstance,							//��ǰӦ�ó���ľ��  		
		NULL);								//��������һ��ΪNULL		
								
	if(hwnd == NULL)					//�Ƿ񴴽��ɹ�  		
		return 0;  	
	
	// ��ʾ����  		
	ShowWindow(hwnd, SW_SHOW);  		

	//��Ϣѭ��
	MSG msg;  			
	while(GetMessage(&msg, NULL, 0, 0))  			
	{  			
		TranslateMessage(&msg);  		
		DispatchMessage(&msg);  		
	}  			


	return 0;
}


LRESULT CALLBACK WindowProc(  									
							IN  HWND hwnd,  		//���ڵľ��
							IN  UINT uMsg,  		//��Ϣ������
							IN  WPARAM wParam,  		
							IN  LPARAM lParam  		
							)  		
{  									
	switch(uMsg)								
	{								
		//������Ϣ							
	case WM_CREATE: 								
		{							
			DbgPrintf("WM_CREATE %d %d\n",wParam,lParam);						
			CREATESTRUCT* createst = (CREATESTRUCT*)lParam;						
			DbgPrintf("CREATESTRUCT %s\n",createst->lpszClass);						
			DbgPrintf("������ %s\n",createst->lpszName);						
						
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
		//������Ϣ							
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
		//�����Ϣ							
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



