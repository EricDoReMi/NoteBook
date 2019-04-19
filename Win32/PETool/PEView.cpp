//����չʾPE�ļ�
#include "StdAfx.h"

//չʾPEͷ��Ϣ
void ShowPEHead(){
	//��ȡ�����PE�ļ���·��
	OPENFILENAME stopenfile;

	TCHAR szPeFileExt[100]="*.exe;*.dll;*.scr;*.drv;*.sys";
	
	memset(szFileName,0,256);
	memset(&stopenfile,0,sizeof(OPENFILENAME));
	stopenfile.lStructSize=sizeof(OPENFILENAME);
	stopenfile.Flags=OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST;
	stopenfile.hwndOwner=g_hwndDlg;
	stopenfile.lpstrFilter=szPeFileExt;
	stopenfile.lpstrFile=szFileName;
	stopenfile.nMaxFile=MAX_PATH;
	GetOpenFileName(&stopenfile);
	
	//��PE�Ի���
	DialogBox(hAppInstance,MAKEINTRESOURCE(IDD_DIALOG_HEADER),g_hwndDlg,PEDialogProc);
	return;


}

//��ȡPEͷ��Ϣ
void ReadPEHead(){
	//���ڴ洢�ַ���������
	TCHAR szBuffer[256];
	
	LPVOID pFileBuffer=NULL;
	PIMAGE_FILE_HEADER pPEHeader = NULL;
	PIMAGE_OPTIONAL_HEADER32 pOptionHeader = NULL;
	
	
	if(!ReadPEFile(szFileName,&pFileBuffer)){
		return;
	}

	
	pPEHeader=getPEHeader(pFileBuffer);
	pOptionHeader=getOptionHeader(pFileBuffer);

	//��ڵ�
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->AddressOfEntryPoint);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_AddressOfEntryPoint,WM_SETTEXT,0,(DWORD)szBuffer);
	
	//�������ַ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->ImageBase);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_ImageBase,WM_SETTEXT,0,(DWORD)szBuffer);
	
	//�����С
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->SizeOfImage);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_SizeOfImage,WM_SETTEXT,0,(DWORD)szBuffer);

	//�����ַ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->BaseOfCode);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_BaseOfCode,WM_SETTEXT,0,(DWORD)szBuffer);

	//���ݻ�ַ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->BaseOfData);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_BaseOfData,WM_SETTEXT,0,(DWORD)szBuffer);

	//�ڴ����
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->SectionAlignment);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_SectionAlignment,WM_SETTEXT,0,(DWORD)szBuffer);

	//�ļ�����
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->FileAlignment);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_FileAlignment,WM_SETTEXT,0,(DWORD)szBuffer);
	
	//��־ֵ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->Magic);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_Magic,WM_SETTEXT,0,(DWORD)szBuffer);

	//��ϵͳ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->Subsystem);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_Subsystem,WM_SETTEXT,0,(DWORD)szBuffer);

	//������Ŀ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pPEHeader->NumberOfSections);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_NumberOfSections,WM_SETTEXT,0,(DWORD)szBuffer);

	//ʱ���
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pPEHeader->TimeDateStamp);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_TimeDateStamp,WM_SETTEXT,0,(DWORD)szBuffer);

	//PEͷ��С
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->SizeOfHeaders);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_SizeOfHeaders,WM_SETTEXT,0,(DWORD)szBuffer);

	//����ֵ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pPEHeader->Characteristics);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_Characteristics,WM_SETTEXT,0,(DWORD)szBuffer);

	//У���
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->CheckSum);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_CheckSum,WM_SETTEXT,0,(DWORD)szBuffer);

	//��ѡPEͷ��С
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pPEHeader->SizeOfOptionalHeader);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_SizeOfOptionalHeader,WM_SETTEXT,0,(DWORD)szBuffer);

	//Ŀ¼����Ŀ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->NumberOfRvaAndSizes);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_NumberOfRvaAndSizes,WM_SETTEXT,0,(DWORD)szBuffer);

}