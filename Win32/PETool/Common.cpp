//ͨ�õĺ���
#include "StdAfx.h"

//��·����ȡ�ļ���
//filePath �ļ���������·��
char* getFileNameFromPath(char* filePath){
	char splitChar='\\';
	char* pFileName=strrchr(filePath,splitChar)+1;
	return pFileName;
}

//richEdit�ĳ��ô���


//���Ŀ¼���Ƿ����
bool checkDicTableExist(){

	//��ȡ�ı�������

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


		//ת������
		DWORD dwAddr;
		sscanf(szBuffer,"%d", &dwAddr);

		if(!dwAddr){
			return false;
		}

		return true;
		

}

//��richEdit����д������
void appendRichEdit(HWND hRichEdit,TCHAR* szBuffer,DWORD sizeOfSzBuffer){
	//��һ��������
	SendMessage(hRichEdit, EM_SETSEL, -1, -1);
	SendMessage(hRichEdit, EM_REPLACESEL, 0, (LPARAM)szBuffer);
	memset(szBuffer,0,sizeOfSzBuffer);
	
}
