// FirstWindow.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

HINSTANCE hAppInstance;//����ǰ�����ImageBase����Ϊȫ�ֱ����������������ȡ��
LRESULT CALLBACK WindowProc(  									
							IN  HWND hwnd,  		//���ڵľ��
							IN  UINT uMsg,  		//��Ϣ������
							IN  WPARAM wParam,  		
							IN  LPARAM lParam  		
							);

void CreateButton(HWND hwnd)								
{								
	HWND hwndPushButton;							
	HWND hwndCheckBox;							
	HWND hwndRadio;							
								
	hwndPushButton = CreateWindow ( 							
		TEXT("button"),//ֱ��дbutton����Ϊwindows�Ѿ������Ƕ�����˰�ť����ʽ 						
		TEXT("��ͨ��ť"),//��ť����ʾ����					
		//WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_DEFPUSHBUTTON,						
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_DEFPUSHBUTTON,//��ť������					
		10, 10,						
		80, 20,						
		hwnd, 						
		(HMENU)1001,		//�Ӵ���ID������ĸ���ڵ�ʱ��������һ��������������Ӵ��ڵ�ʱ������Ӧ��д�Ӵ��ڱ�ţ�����Ψһ��ʶ�Ӵ���
		hAppInstance, 						
		NULL);	

	//��ȡbutton��WNDCLASS ���ڹ۲�ϵͳ����ΰ����Ǵ���button���
	TCHAR szBuffer[0x20];					
	GetClassName(hwndPushButton,szBuffer,0x20);					
						
	WNDCLASS wc;					
	GetClassInfo(hAppInstance,szBuffer,&wc);					
	OutputDebugStringF("-->%s\n",wc.lpszClassName);					
	OutputDebugStringF("-->%x\n",wc.lpfnWndProc);					


	hwndCheckBox = CreateWindow ( 					
	TEXT("button"), 				
	TEXT("��ѡ��"),				
	//WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX,				
	WS_CHILD | WS_VISIBLE | BS_CHECKBOX |BS_AUTOCHECKBOX ,				
	10, 40,				
	80, 20,				
	hwnd, 				
	(HMENU)1002,		//�Ӵ���ID		
	hAppInstance, 				
	NULL);				
					
	hwndRadio = CreateWindow ( 					
		TEXT("button"), 				
		TEXT("��ѡ��ť"),				
		//WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON | BS_AUTORADIOBUTTON,				
		WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON  ,				
		10, 70,				
		80, 20,				
		hwnd, 				
		(HMENU)1003,		//�Ӵ���ID		
		hAppInstance, 				
		NULL);				
					

								
						
} 								


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	hAppInstance=hInstance;
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
	CreateButton(hwnd);
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
	case WM_COMMAND:								
		{								
			switch(LOWORD(wParam))							
			{							
				case 1001://�Ӵ��ڱ��						
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


								
								



