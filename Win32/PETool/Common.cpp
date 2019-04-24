//通用的函数
#include "StdAfx.h"

//从路径获取文件名
//filePath 文件名完整的路径
char* getFileNameFromPath(char* filePath){
	char splitChar='\\';
	char* pFileName=strrchr(filePath,splitChar)+1;
	return pFileName;
}

//richEdit的常用处理


//检查目录表是否存在
bool checkDicTableExist(){

	//获取文本框内容

	TCHAR szBuffer[0x50];
	memset(szBuffer,0,0x50);
	HWND hEdit1=NULL;

	switch(IDC_BUTTON_DIC_Index)
	{
		case IDC_BUTTON_DIC_IMPORT:
			{
				hEdit1 = GetDlgItem(g_DICDlg,IDC_EDIT_DIC_3);
				GetWindowText(hEdit1,szBuffer,0x50);	
				break;
			}
					
		case IDC_BUTTON_DIC_EXPORT:
			{	
				hEdit1 = GetDlgItem(g_DICDlg,IDC_EDIT_DIC_1);
				GetWindowText(hEdit1,szBuffer,0x50);
				break;
			}
		case IDC_BUTTON_DIC_RESOURSE:
			{	
				hEdit1 = GetDlgItem(g_DICDlg,IDC_EDIT_DIC_5);
				GetWindowText(hEdit1,szBuffer,0x50);
				break;
			}
		case IDC_BUTTON_DIC_RELOCATION:
			{	
				hEdit1 = GetDlgItem(g_DICDlg,IDC_EDIT_DIC_11);
				GetWindowText(hEdit1,szBuffer,0x50);
				break;
			}
		case IDC_BUTTON_DIC_BOUND:
			{			
				hEdit1 = GetDlgItem(g_DICDlg,IDC_EDIT_DIC_23);
				GetWindowText(hEdit1,szBuffer,0x50);
				break;
			}
		case IDC_BUTTON_DIC_IAT:
			{	
				hEdit1 = GetDlgItem(g_DICDlg,IDC_EDIT_DIC_25);
				GetWindowText(hEdit1,szBuffer,0x50);
				break;
			}
	}


		//转成整数
		DWORD dwAddr;
		sscanf(szBuffer,"%d", &dwAddr);

		if(!dwAddr){
			return false;
		}

		return true;
		

}

//向richEdit增加写入内容
void appendRichEdit(HWND hRichEdit,TCHAR* szBuffer,DWORD sizeOfSzBuffer){
	//下一组输入区
	SendMessage(hRichEdit, EM_SETSEL, -1, -1);
	SendMessage(hRichEdit, EM_REPLACESEL, 0, (LPARAM)szBuffer);
	memset(szBuffer,0,sizeOfSzBuffer);
	
}
