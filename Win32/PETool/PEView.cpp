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
	if(GetOpenFileName(&stopenfile)){

		if(!ReadPEFile(szFileName,&pFileBuffer)){
			MessageBox(g_hwndDlg,"������Ч��PE�ļ�",0,MB_OK);
			return;
		}

		//��PE�Ի���
		DialogBox(hAppInstance,MAKEINTRESOURCE(IDD_DIALOG_HEADER),g_hwndDlg,PEDialogProc);
	}
	
	
	return;


}

//��ȡPEͷ��Ϣ
void ReadPEHead(){
	//���ڴ洢�ַ���������
	TCHAR szBuffer[256];
	
	
	PIMAGE_FILE_HEADER pPEHeader = NULL;
	PIMAGE_OPTIONAL_HEADER32 pOptionHeader = NULL;
	

	
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

//չʾPESections��Ϣ
void ShowPESections(){

	
	//��PESection�Ի���
	DialogBox(hAppInstance,MAKEINTRESOURCE(IDD_DIALOG_SECTION),g_PEDlg,SectionDialogProc);
	return;


}


//��ʼ��Section�б�
VOID InitSectionListView(HWND hDlg){
	LV_COLUMN lv;//�洢��								
	HWND hListProcess;//���ListView���							
									
	//��ʼ��								
	memset(&lv,0,sizeof(LV_COLUMN));								
	//��ȡIDC_LIST_SECTIONVIEW���								
	hListProcess = GetDlgItem(hDlg,IDC_LIST_SECTIONVIEW);								
	//��������ѡ��								
	SendMessage(hListProcess,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_FULLROWSELECT,LVS_EX_FULLROWSELECT);								
									
	//��һ��								
	lv.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;								
	lv.pszText = TEXT("����");				//�б���				
	lv.cx = 150;							//�п�
	lv.iSubItem = 0;								
	//ListView_InsertColumn(hListProcess, 0, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,0,(DWORD)&lv);								
	//�ڶ���								
	lv.pszText = TEXT("�ļ�ƫ��");								
	lv.cx = 100;								
	lv.iSubItem = 1;								
	//ListView_InsertColumn(hListProcess, 1, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,1,(DWORD)&lv);								
	//������								
	lv.pszText = TEXT("�ļ���С");								
	lv.cx = 100;								
	lv.iSubItem = 2;								
	ListView_InsertColumn(hListProcess, 2, &lv);								
	//������								
	lv.pszText = TEXT("�ڴ�ƫ��");								
	lv.cx = 100;								
	lv.iSubItem = 3;								
	ListView_InsertColumn(hListProcess, 3, &lv);
	//������								
	lv.pszText = TEXT("�ڴ��С");								
	lv.cx = 100;								
	lv.iSubItem = 4;								
	ListView_InsertColumn(hListProcess, 4, &lv);

	//������								
	lv.pszText = TEXT("��������");								
	lv.cx = 100;								
	lv.iSubItem = 5;								
	ListView_InsertColumn(hListProcess, 5, &lv);

	EnumPESections(hListProcess);
}

//����Section
VOID EnumPESections(HWND hListProcess){
	//���ڴ洢�ַ����Ļ�����
	TCHAR szBuffer[0x50];

	LV_ITEM vitem;						

	//��ȡ�ڱ���Ϣ
	PIMAGE_SECTION_HEADER pSectionHeader = NULL;
	
	pSectionHeader=getSectionHeader(pFileBuffer);
	
	WORD sectionNum=getSectionNum(pFileBuffer);

	WORD i=0;
	for(i=0;i<sectionNum;i++){
		BYTE names[9]={0};
		BYTE* p_name=names;
		p_name=pSectionHeader->Name;

		//��ʼ��
		memset(&vitem,0,sizeof(LV_ITEM));
		vitem.mask = LVIF_TEXT;

		//����
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%s",p_name);
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;//�ڼ���						
		vitem.iSubItem = 0;	//�ڼ���				
		//����һ���꣬��SendMessage����������һ���ģ���һ��ʱҪ��ListView_InsertItem�����������ListView_SetItem
		//ListView_InsertItem(hListProcess, &vitem);
		SendMessage(hListProcess, LVM_INSERTITEM,0,(DWORD)&vitem);


		//�ļ�ƫ����
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pSectionHeader->PointerToRawData);						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 1;						
		ListView_SetItem(hListProcess, &vitem);	

		//�ļ������ĳߴ�
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pSectionHeader->SizeOfRawData);						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 2;						
		ListView_SetItem(hListProcess, &vitem);	

		//�ڴ�ƫ����
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",FileOffsetToRva(pFileBuffer,pSectionHeader->PointerToRawData));						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 3;						
		ListView_SetItem(hListProcess, &vitem);	

		//�ڴ�����ĳߴ�
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pSectionHeader->Misc.VirtualSize);						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 4;						
		ListView_SetItem(hListProcess, &vitem);	

		//������
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pSectionHeader->Characteristics);						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 5;						
		ListView_SetItem(hListProcess, &vitem);	

		//�����һ���ڱ���Ϣ
		pSectionHeader=(PIMAGE_SECTION_HEADER)((char*)pSectionHeader+40);
		
		
	}
	
   						

}


//չʾPEDic��Ϣ
void ShowPEDic(){
	
	//��PEDic�Ի���
	DialogBox(hAppInstance,MAKEINTRESOURCE(IDD_DIALOG_DIC),g_PEDlg,DicDialogProc);
	return;


}

//��ʼ��Dic�б�
VOID InitPEDicView(HWND hDlg){

	PIMAGE_OPTIONAL_HEADER32 pOptionHeader = NULL;
	pOptionHeader=getOptionHeader(pFileBuffer);
	
	PIMAGE_DATA_DIRECTORY pImageDataDirectory=pOptionHeader->DataDirectory;

	//�������������Դ���쳣��Ϣ����ȫ֤����ض�λ��������Ϣ����Ȩ���б�ȫ��ָ���
    //TLS���������ñ��󶨵����IAT���ӳٵ����COM��Ϣ�� ���һ������δʹ�á�
	
	PIMAGE_DATA_DIRECTORY pDataDirectory=NULL;

	//���������ı����ַ���
	TCHAR szBuffer[0x50];
	
	
	DWORD i=0;
	int DicNum=1010;
	for(i=0;i<16;i++){
		DicNum=1010+i*2;
		pDataDirectory=pImageDataDirectory+i;
		
		//���EDIT�ؼ�����ָ��
		HWND pEditRVA = GetDlgItem(hDlg,DicNum);
		HWND pEditSIZE = GetDlgItem(hDlg,DicNum+1);
		
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pDataDirectory->VirtualAddress);	
		SetWindowText(pEditRVA,szBuffer);	
	
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pDataDirectory->Size);	
		SetWindowText(pEditSIZE,szBuffer);
		
	}
}


//����Ŀ¼������.....��ť����ʾĿ¼����Ի���
void AlertDicDetail(){
		//���PEĿ¼��ϸ����Ϣ
		//������PEĿ¼��ϸ����Ϣ���߳�
		HANDLE	hPEDicDetailThread = ::CreateThread(NULL, 0, PEDicDetailThread, NULL, 0, NULL);
		::CloseHandle(hPEDicDetailThread);

		return;
		
}

//��Ŀ¼����Ի���
void ShowDicDetail(){
	if(checkDicTableExist()){
		DialogBox(hAppInstance,MAKEINTRESOURCE(IDD_DIALOG_DICDETAIL),g_DICDlg,DicDetailDialogProc);

	}else{
		MessageBox(g_DICDlg,TEXT("û�����Ŀ¼����"),0,MB_OK);
	}
	
	return;
}

//��ʼ��PE��Ŀ¼����
void InitPEDicDetailView(HWND hDlg){
	hDicDetailEdit = GetDlgItem(hDlg,IDC_RICHEDIT1);
	SendMessage(hDicDetailEdit,EM_SETEVENTMASK,0,ENM_SELCHANGE|ENM_MOUSEEVENTS|ENM_CHANGE|ENM_KEYEVENTS|ENM_SCROLL|ENM_DROPFILES);
    SendMessage(hDicDetailEdit,EM_EXLIMITTEXT,0,-1);
	
	switch(IDC_BUTTON_DIC_Index)
		{
			case IDC_BUTTON_DIC_IMPORT:
				{
					//��ӡ�����
					PrintImportTable(hDicDetailEdit);
						
					break;
				}
						
			case IDC_BUTTON_DIC_EXPORT:
				{	
					//��ӡ������
					PrintExportTable(hDicDetailEdit);
					
					break;
				}
			case IDC_BUTTON_DIC_RESOURSE:
				{	
					//��ӡ��Դ��
					PrintResourceTable(hDicDetailEdit);
					
					break;
				}
			case IDC_BUTTON_DIC_RELOCATION:
				{	
					//��ӡ�ض�λ��
					PrintRelocationTable(hDicDetailEdit);
					break;
				}
			case IDC_BUTTON_DIC_BOUND:
				{	
					PrintBoundImportTable(hDicDetailEdit);		
					break;
				}
			case IDC_BUTTON_DIC_IAT:
				{	
								
					PrintIatTable(hDicDetailEdit);				
					break;
				}
		}

}

//=================��ӡĿ¼������===================
//��ӡ������
VOID PrintExportTable(HWND hRichEdit){

	//���������ı����ַ���
	TCHAR szBuffer[0x10000];
	TCHAR szTmp[0x100];

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,1);
	//��õ�������FileBuffer�е�Addressλ��
	DWORD exportDirectoryFileAddress =(DWORD)pFileBuffer+RvaToFileOffset(pFileBuffer,pDataDirectory->VirtualAddress);

	//�ҵ�������
	PIMAGE_EXPORT_DIRECTORY pExportDirectory=(PIMAGE_EXPORT_DIRECTORY)exportDirectoryFileAddress;
	

	
	memset(szBuffer,0,0x10000);
	sprintf(szBuffer,TEXT("%s"),TEXT("=============��������Ϣ=================\n"));						
	DWORD PEName=(DWORD)pFileBuffer+RvaToFileOffset(pFileBuffer,pExportDirectory->Name);
	memset(szTmp,0,0x100);
	sprintf (szTmp,TEXT("Name:%s\n"),PEName);						

	strcat(szBuffer,szTmp);
	
	memset(szTmp,0,0x100);
	sprintf(szTmp,"Base:%X\n",pExportDirectory->Base);						
	strcat(szBuffer,szTmp);

	memset(szTmp,0,0x100);
	sprintf(szTmp,"NumberOfFunctions:%X\n",pExportDirectory->NumberOfFunctions);						
	strcat(szBuffer,szTmp);

	memset(szTmp,0,0x100);
	sprintf(szTmp,"NumberOfNames:%X\n",pExportDirectory->NumberOfNames);						
	strcat(szBuffer,szTmp);

	memset(szTmp,0,0x100);
	sprintf(szTmp,"AddressOfFunctions:%X\n",pExportDirectory->AddressOfFunctions);						
	strcat(szBuffer,szTmp);

	memset(szTmp,0,0x100);
	sprintf(szTmp,"AddressOfNames:%X\n",pExportDirectory->AddressOfNames);						
	strcat(szBuffer,szTmp);

	memset(szTmp,0,0x100);
	sprintf(szTmp,"AddressOfNameOrdinals:%X\n",pExportDirectory->AddressOfNameOrdinals);						
	strcat(szBuffer,szTmp);

	memset(szTmp,0,0x100);
	sprintf(szTmp,TEXT("******��������******\n"));						
	strcat(szBuffer,szTmp);

	//��һ��������
	appendRichEdit(hRichEdit,szBuffer,0x10000);
	
	DWORD i=0;
	DWORD j=0;

	PDWORD pFileAddressOfFunctions=(PDWORD)((DWORD)pFileBuffer+RvaToFileOffset(pFileBuffer,pExportDirectory->AddressOfFunctions));
	PDWORD pFileAddressOfNames=(PDWORD)((DWORD)pFileBuffer+RvaToFileOffset(pFileBuffer,pExportDirectory->AddressOfNames));
	PWORD pFileAddressOfNameOrdinals=(PWORD)((DWORD)pFileBuffer+RvaToFileOffset(pFileBuffer,pExportDirectory->AddressOfNameOrdinals));
	
	//��ӡ������Ϣ
	for(i=0;i<pExportDirectory->NumberOfFunctions;i++){
		DWORD addressOfFunction=*(pFileAddressOfFunctions+i);
		
		if(addressOfFunction){
				memset(szTmp,0,0x100);
				sprintf(szTmp,"AddressOfFunction:%X\n",addressOfFunction);						
				strcat(szBuffer,szTmp);

				memset(szTmp,0,0x100);
				sprintf(szTmp,"Ordinal:%X\n",i+pExportDirectory->Base);						
				strcat(szBuffer,szTmp);

		
			
			for(j=0;j<pExportDirectory->NumberOfNames;j++){
				if(*(pFileAddressOfNameOrdinals+j)==i){
					memset(szTmp,0,0x100);
					sprintf(szTmp,"AddressOfName:%s\t",(DWORD)pFileBuffer+RvaToFileOffset(pFileBuffer,*(pFileAddressOfNames+j)));						
					strcat(szBuffer,szTmp);

					
				}
			}

		}
		//��һ��������
		appendRichEdit(hRichEdit,szBuffer,0x10000);
		
	}




}

//��ӡ�����
VOID PrintImportTable(HWND hRichEdit)
{
	//���������ı����ַ���
	TCHAR szBuffer[0x10000];
	TCHAR szTmp[0x100];

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,2);
	//��õ������FileBuffer�е�Addressλ��
	DWORD importTableFileBufferAddress =RvaToFileBufferAddress(pFileBuffer,pDataDirectory->VirtualAddress);

	//�ҵ���һ�������
	PIMAGE_IMPORT_DESCRIPTOR pImportTables=(PIMAGE_IMPORT_DESCRIPTOR)importTableFileBufferAddress;


	memset(szBuffer,0,0x10000);
	memset(szTmp,0,0x100);
	sprintf(szTmp,TEXT("=============�������Ϣ=================\n"));						
	strcat(szBuffer,szTmp);
	//��һ��������
	appendRichEdit(hRichEdit,szBuffer,0x10000);
	
	while(pImportTables->Characteristics|pImportTables->FirstThunk|pImportTables->ForwarderChain|pImportTables->Name|pImportTables->OriginalFirstThunk|pImportTables->TimeDateStamp)
	{
		
		DWORD nameRVA=pImportTables->Name;
		char* pDllNames=(char*)RvaToFileBufferAddress(pFileBuffer,nameRVA);
		
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("***********%s*********\n"),pDllNames);						
		strcat(szBuffer,szTmp);

		DWORD timeDateStamp = pImportTables->TimeDateStamp;
		
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("***timeStamp:%X***\n"),timeDateStamp);						
		strcat(szBuffer,szTmp);

		DWORD originalFirstThunk=pImportTables->OriginalFirstThunk;
		DWORD firstThunk=pImportTables->FirstThunk;

		PDWORD pOriginalFirstThunk=(PDWORD)RvaToFileBufferAddress(pFileBuffer,originalFirstThunk);

		PDWORD pFirstThunk=(PDWORD)RvaToFileBufferAddress(pFileBuffer,firstThunk);

		//����OriginalFirstThunk
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("------------OriginalFirstThunk----------\n"));						
		strcat(szBuffer,szTmp);

		//��һ��������
		appendRichEdit(hRichEdit,szBuffer,0x10000);

		while(*pOriginalFirstThunk){
			DWORD imageData=(DWORD)*pOriginalFirstThunk;
			//���λ�ж����λ�Ƿ�Ϊ1 �����,��ô��ȥ���λ��ֵ���Ǻ����ĵ������				

			if(imageData & 0x80000000){
				DWORD indexOfExport=imageData & 0x7FFFFFFF;//������ĺ������

				memset(szTmp,0,0x100);
				sprintf(szTmp,TEXT("�����������:%d\n"),indexOfExport);						
				strcat(szBuffer,szTmp);

			}else{
				PIMAGE_IMPORT_BY_NAME pImportByName=(PIMAGE_IMPORT_BY_NAME)RvaToFileBufferAddress(pFileBuffer,imageData);//����������
				char* pImportFunNames=(char*)pImportByName->Name;
	

				memset(szTmp,0,0x100);
				sprintf(szTmp,TEXT("������������:%s\n"),pImportFunNames);						
				strcat(szBuffer,szTmp);
				
			}

			
			pOriginalFirstThunk++;
			
		}


		//����FirstThunk
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("------------FirstThunk----------\n"));						
		strcat(szBuffer,szTmp);


		while(*pFirstThunk){
			DWORD imageData=(DWORD)*pFirstThunk;
			//���λ�ж����λ�Ƿ�Ϊ1 �����,��ô��ȥ���λ��ֵ���Ǻ����ĵ������				

			if(imageData & 0x80000000){
				DWORD indexOfExport=imageData & 0x7FFFFFFF;//������ĺ������
				
				memset(szTmp,0,0x100);
				sprintf(szTmp,TEXT("���������:%d\n"),indexOfExport);						
				strcat(szBuffer,szTmp);

			}else{
				PIMAGE_IMPORT_BY_NAME pImportByName=(PIMAGE_IMPORT_BY_NAME)RvaToFileBufferAddress(pFileBuffer,imageData);//����������
				char* pImportFunNames=(char*)pImportByName->Name;

				memset(szTmp,0,0x100);
				sprintf(szTmp,TEXT("������������:%s\n"),pImportFunNames);						
				strcat(szBuffer,szTmp);
			}

			
			pFirstThunk++;
		}
	

		//��һ��������ַ
		pImportTables++;
		//��һ��������
		appendRichEdit(hRichEdit,szBuffer,0x10000);

		
	}


}

//��ӡIAT
VOID PrintIatTable(HWND hRichEdit)
{
	//���������ı����ַ���
	TCHAR szBuffer[0x10000];
	TCHAR szTmp[0x100];

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,2);
	//��õ������FileBuffer�е�Addressλ��
	DWORD importTableFileBufferAddress =RvaToFileBufferAddress(pFileBuffer,pDataDirectory->VirtualAddress);

	//�ҵ���һ�������
	PIMAGE_IMPORT_DESCRIPTOR pImportTables=(PIMAGE_IMPORT_DESCRIPTOR)importTableFileBufferAddress;


	memset(szBuffer,0,0x10000);
	memset(szTmp,0,0x100);
	sprintf(szTmp,TEXT("=============IAT����Ϣ=================\n"));						
	strcat(szBuffer,szTmp);
	//��һ��������
	appendRichEdit(hRichEdit,szBuffer,0x10000);
	
	while(pImportTables->Characteristics|pImportTables->FirstThunk|pImportTables->ForwarderChain|pImportTables->Name|pImportTables->OriginalFirstThunk|pImportTables->TimeDateStamp)
	{
		
		DWORD nameRVA=pImportTables->Name;
		char* pDllNames=(char*)RvaToFileBufferAddress(pFileBuffer,nameRVA);
		
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("***********%s*********\n"),pDllNames);						
		strcat(szBuffer,szTmp);




		DWORD firstThunk=pImportTables->FirstThunk;



		PDWORD pFirstThunk=(PDWORD)RvaToFileBufferAddress(pFileBuffer,firstThunk);



		//����FirstThunk
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("------------FirstThunk----------\n"));						
		strcat(szBuffer,szTmp);


		while(*pFirstThunk){
			DWORD imageData=(DWORD)*pFirstThunk;
			//���λ�ж����λ�Ƿ�Ϊ1 �����,��ô��ȥ���λ��ֵ���Ǻ����ĵ������				

			if(imageData & 0x80000000){
				DWORD indexOfExport=imageData & 0x7FFFFFFF;//������ĺ������
				
				memset(szTmp,0,0x100);
				sprintf(szTmp,TEXT("���������:%d\n"),indexOfExport);						
				strcat(szBuffer,szTmp);

			}else{
				PIMAGE_IMPORT_BY_NAME pImportByName=(PIMAGE_IMPORT_BY_NAME)RvaToFileBufferAddress(pFileBuffer,imageData);//����������
				char* pImportFunNames=(char*)pImportByName->Name;

				memset(szTmp,0,0x100);
				sprintf(szTmp,TEXT("������������:%s\n"),pImportFunNames);						
				strcat(szBuffer,szTmp);
			}

			
			pFirstThunk++;
		}
	

		//��һ��������ַ
		pImportTables++;
		//��һ��������
		appendRichEdit(hRichEdit,szBuffer,0x10000);

		
	}


}

//��ӡ�ض�λ��
VOID PrintRelocationTable(HWND hRichEdit)
{
	//���������ı����ַ���
	TCHAR szBuffer[0x10000];
	TCHAR szTmp[0x100];

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,6);
	//����ض�λ����FileBuffer�е�Addressλ��
	DWORD relocationFileBufferAddress =RvaToFileBufferAddress(pFileBuffer,pDataDirectory->VirtualAddress);

	//�ҵ�
	PIMAGE_BASE_RELOCATION pRelocationTables=(PIMAGE_BASE_RELOCATION)relocationFileBufferAddress;

	DWORD i=0;

	memset(szBuffer,0,0x10000);
	sprintf(szBuffer,TEXT("%s"),TEXT("=============�ض�λ����Ϣ=================\n"));
	//��һ��������
	appendRichEdit(hRichEdit,szBuffer,0x10000);

	//pRelocationTables->SizeOfBlock || pRelocationTables->VirtualAddress ȫΪ0ʱ�����������
	while(pRelocationTables->VirtualAddress || pRelocationTables->SizeOfBlock)
	{
		i++;
		DWORD sizeOfBlock=pRelocationTables->SizeOfBlock;
		DWORD virtualAddress=pRelocationTables->VirtualAddress;
		DWORD sectionIndex=RvaToSectionIndex(pFileBuffer,virtualAddress);
		
		//��ӡÿ���ض�λ��ľ�����Ϣ
		
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("***��:%d\tsizeOfBlock:%d\tvirtualAddress:%X\tsectionIndex:%d\n"),i,sizeOfBlock,virtualAddress,sectionIndex);						
		strcat(szBuffer,szTmp);

		

		//����BLOCK������
		DWORD numBlock=0;
		numBlock=(sizeOfBlock-8)/2;
		
		DWORD j=0;
		PWORD pStartBlock=(PWORD)pRelocationTables+4;
		for(j=0;j<numBlock;j++)
		{
			//Ӳ����ط��ĵ�ַ
			DWORD rvaChange=(DWORD)((*(PWORD)pStartBlock)&0x0FFF)+virtualAddress;
			DWORD isChange=(*(PWORD)pStartBlock)&0xF000;
			DWORD fileOffSet=RvaToFileOffset(pFileBuffer,rvaChange);
			char* isChangeTxt=NULL;
			isChangeTxt="��";
			if((isChange^0x3000)==0){
				isChangeTxt="��";
			}
			
			
			memset(szTmp,0,0x100);
			sprintf(szTmp,TEXT("%d\tChange:%s\trva:%X\tfileOffSet:%X\n"),j+1,isChangeTxt,rvaChange,fileOffSet);						
			strcat(szBuffer,szTmp);

			pStartBlock++;

			

		}
		

		//��һ���ض�λ���ַ
		pRelocationTables=(PIMAGE_BASE_RELOCATION)((char*)pRelocationTables+sizeOfBlock);
		appendRichEdit(hRichEdit,szBuffer,0x10000);
		

	}




}



//��ӡ�󶨵����
VOID PrintBoundImportTable(HWND hRichEdit)
{

	//���������ı����ַ���
	TCHAR szBuffer[0x10000];
	TCHAR szTmp[0x100];


	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,12);

	//��õ������FileBuffer�е�Addressλ��
	DWORD importBoundTableFileBufferAddress =RvaToFileBufferAddress(pFileBuffer,pDataDirectory->VirtualAddress);

	//�ҵ���һ���󶨵����
	PIMAGE_BOUND_IMPORT_DESCRIPTOR pImportBoundTable=(PIMAGE_BOUND_IMPORT_DESCRIPTOR)importBoundTableFileBufferAddress;
	
	//�󶨵����ı�ͷ
	PIMAGE_BOUND_IMPORT_DESCRIPTOR pImportBoundTable1=pImportBoundTable;
	
	memset(szBuffer,0,0x10000);


	sprintf(szBuffer,TEXT("%s"),TEXT("=============�󶨵������Ϣ=================\n"));
	//��һ��������
	appendRichEdit(hRichEdit,szBuffer,0x10000);

	DWORD i=0;

	while(pImportBoundTable->NumberOfModuleForwarderRefs|pImportBoundTable->OffsetModuleName|pImportBoundTable->TimeDateStamp)
	{
		DWORD timeDateStamp=pImportBoundTable->TimeDateStamp;
		WORD  numberOfModuleForwarderRefs=0;

		numberOfModuleForwarderRefs=pImportBoundTable->NumberOfModuleForwarderRefs;
		

		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("---IMAGE_BOUND_IMPORT_DESCRIPTOR---\n"));						
		strcat(szBuffer,szTmp);
		

		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("numberOfModuleForwarderRefs:%d\n"),numberOfModuleForwarderRefs);						
		strcat(szBuffer,szTmp);


		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("timeDateStamp:%X\n"),pImportBoundTable->TimeDateStamp);						
		strcat(szBuffer,szTmp);
		
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("OffsetModuleName:%s\n"),(char*)pImportBoundTable1+pImportBoundTable->OffsetModuleName);						
		strcat(szBuffer,szTmp);

		DWORD j=0;
		
		PIMAGE_BOUND_FORWARDER_REF pBoundForwarderRef=(PIMAGE_BOUND_FORWARDER_REF)pImportBoundTable+1;


		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("***********IMAGE_BOUND_FORWARDER_REF***************\n"));						
		strcat(szBuffer,szTmp);
		

		//��һ��������
		appendRichEdit(hRichEdit,szBuffer,0x10000);

		for(j=0;j<numberOfModuleForwarderRefs;j++){

			memset(szTmp,0,0x100);
			sprintf(szTmp,TEXT("timeDateStamp:%X\n"),pBoundForwarderRef->TimeDateStamp);						
			strcat(szBuffer,szTmp);

			memset(szTmp,0,0x100);
			sprintf(szTmp,TEXT("OffsetModuleName:%s\n"),(char*)pImportBoundTable1+pBoundForwarderRef->OffsetModuleName);						
			strcat(szBuffer,szTmp);

			memset(szTmp,0,0x100);
			sprintf(szTmp,TEXT("Reserved:%d\n"),pBoundForwarderRef->Reserved);						
			strcat(szBuffer,szTmp);

			pBoundForwarderRef++;
			
		}
		
		
		//��һ��������
		appendRichEdit(hRichEdit,szBuffer,0x10000);

		//��һ���󶨵�����ַ
		pImportBoundTable+=(numberOfModuleForwarderRefs+1);


	}


}

//��ӡ��Դ��
VOID PrintResourceTable(HWND hRichEdit){
	//���������ı����ַ���
	TCHAR szBuffer[0x10000];
	
	memset(szBuffer,0,0x10000);

	sprintf(szBuffer,TEXT("%s"),TEXT("=============��Դ����Ϣ=================\n"));
	//��һ��������
	appendRichEdit(hRichEdit,szBuffer,0x10000);

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,3);

	//�����Դ����FileBuffer�е�Addressλ��
	DWORD resourceTableFileBufferAddress =RvaToFileBufferAddress(pFileBuffer,pDataDirectory->VirtualAddress);
	
	printResource(pFileBuffer,(DWORD)resourceTableFileBufferAddress,(PIMAGE_RESOURCE_DIRECTORY)resourceTableFileBufferAddress,1);
}

//�ݹ��ӡ��Դ��ĺ���
//TableAddr:��Դ���ͷ��λ��
//pResourceDir
//index:����
VOID printResource(LPVOID pFileBuffer,DWORD TableAddr,PIMAGE_RESOURCE_DIRECTORY pResourceDir,int index){

	


	WORD countOfDirectory=0;
	countOfDirectory=pResourceDir->NumberOfIdEntries+pResourceDir->NumberOfNamedEntries;
	PIMAGE_RESOURCE_DIRECTORY_ENTRY pResourceDirEntry=(PIMAGE_RESOURCE_DIRECTORY_ENTRY)(pResourceDir+1);

	WORD i=0;
	


	for(i=0;i<countOfDirectory;i++){

		if(pResourceDirEntry->NameIsString){
			PIMAGE_RESOURCE_DIR_STRING_U pString = (PIMAGE_RESOURCE_DIR_STRING_U)((DWORD)pResourceDir + pResourceDirEntry->NameOffset);
			WCHAR nodeString[256]={0};
			wcsncpy(nodeString,pString->NameString,pString->Length);
				
			printIndexTitle(index,nodeString);

				
		}else{
			DWORD id=pResourceDirEntry->NameOffset;
			if(index==1){
				TCHAR nodeString[256]={0};
				switch(id)
				{
					case 1: 
						strcpy(nodeString,"Cursor");
						printIndexTitle(index,nodeString); 
						break;
					case 2: 
						strcpy(nodeString,"Bitmap");
						printIndexTitle(index,nodeString); 
						break;
					case 3:
						strcpy(nodeString,"Icon");
						printIndexTitle(index,nodeString); 
						break;	
					case 4: 
						strcpy(nodeString,"Menu");
						printIndexTitle(index,nodeString); 
						break;
					case 5: 
						strcpy(nodeString,"Dialog");
						printIndexTitle(index,nodeString); 
						break;
					case 6: 
						strcpy(nodeString,"String");
						printIndexTitle(index,nodeString); 
						break;
					case 7:
						strcpy(nodeString,"FontDir");
						printIndexTitle(index,nodeString); 
						break;
					case 8:
						strcpy(nodeString,"Font");
						printIndexTitle(index,nodeString); 
						break;
					case 9: 
						strcpy(nodeString,"Accelerator");
						printIndexTitle(index,nodeString); 
						break;
					case 10: 
						strcpy(nodeString,"RCDATA");
						printIndexTitle(index,nodeString); 
						break;
					case 11:
						strcpy(nodeString,"MessageTable");
						printIndexTitle(index,nodeString); 
						break;
					case 12: 
						strcpy(nodeString,"GroupCursor");
						printIndexTitle(index,nodeString); 
						break;

					case 14: 
						strcpy(nodeString,"GroupIcon");
						printIndexTitle(index,nodeString); 
						break;

					case 16: 
						strcpy(nodeString,"Version");
						printIndexTitle(index,nodeString); 
						break;

					case 17: 
						strcpy(nodeString,"DlgInclude");
						printIndexTitle(index,nodeString); 
						break;

					case 19: 
						strcpy(nodeString,"PlugPlay");
						printIndexTitle(index,nodeString); 
						break;

					case 20: 
						strcpy(nodeString,"VXD");
						printIndexTitle(index,nodeString); 
						break;

					case 21: 
						strcpy(nodeString,"ANICursor");
						printIndexTitle(index,nodeString); 
						break;

					case 22: 
						strcpy(nodeString,"ANIIcon");
						printIndexTitle(index,nodeString); 
						break;

					case 23: 
						strcpy(nodeString,"HTML");
						printIndexTitle(index,nodeString); 
						break;


					default: 
						printIndexID(index,id); 
						break;
				}
				
			}else{
				printIndexID(index,id);
			}
			
		}

		if(pResourceDirEntry->DataIsDirectory==0){
			
			PIMAGE_DATA_DIRECTORY  pData = (PIMAGE_DATA_DIRECTORY)((DWORD)TableAddr + (DWORD)pResourceDirEntry->OffsetToData);
			
			CHAR infoString[500]={0};
		
			DWORD fileOffset=RvaToFileOffset(pFileBuffer,pData->VirtualAddress);
			sprintf(infoString,"fileOffset:%x,RVA:%x,size:%x",fileOffset,pData->VirtualAddress,pData->Size);
			printIndexTitle(index+1,infoString);
			
			return;
		
		}

			printResource(pFileBuffer,TableAddr,(PIMAGE_RESOURCE_DIRECTORY)((DWORD)TableAddr+(DWORD)pResourceDirEntry->OffsetToDirectory),index+1);
			
			pResourceDirEntry++;
		
	}

}

//��ӡnames
//index ����
//names
VOID printIndexTitle(int index,WCHAR* names){
	int i=0;

	for(i=0;i<index;i++){
		if(i<index-1){
			printf("    ");
		}else{
			printf("|---");
		}
		
	}
	wprintf(L"%s\n",names);
}

//��ӡnames
//index ����
//names
VOID printIndexTitle(int index,TCHAR* names){

	//���������ı����ַ���
	TCHAR szBuffer[0x10000];
	TCHAR szTmp[0x100];
	memset(szBuffer,0,0x10000);

	int i=0;
	
	for(i=0;i<index;i++){
		if(i<index-1){
			memset(szTmp,0,0x100);
			sprintf(szTmp,TEXT("    "));						
			strcat(szBuffer,szTmp);
		}else{
			memset(szTmp,0,0x100);
			sprintf(szTmp,TEXT("|---"));						
			strcat(szBuffer,szTmp);
		}
		
	}

		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("%s\n"),names);						
		strcat(szBuffer,szTmp);
		//��һ��������
		appendRichEdit(hDicDetailEdit,szBuffer,0x10000);

}

//��ӡID
//index ����
//id
VOID printIndexID(int index,DWORD id){
	int i=0;

	//���������ı����ַ���
	TCHAR szBuffer[0x10000];
	TCHAR szTmp[0x100];
	memset(szBuffer,0,0x10000);
	
	for(i=0;i<index;i++){
		if(i<index-1){
			memset(szTmp,0,0x100);
			sprintf(szTmp,TEXT("    "));						
			strcat(szBuffer,szTmp);
		}else{
			memset(szTmp,0,0x100);
			sprintf(szTmp,TEXT("|---"));						
			strcat(szBuffer,szTmp);
		}
	}

	if(index==3){
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("CodePage:%d\n"),id);						
		strcat(szBuffer,szTmp);
	}else{
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("ID:%d\n"),id);						
		strcat(szBuffer,szTmp);
	}

	//��һ��������
	appendRichEdit(hDicDetailEdit,szBuffer,0x10000);

}




