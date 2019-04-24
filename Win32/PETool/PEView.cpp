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
	
	DialogBox(hAppInstance,MAKEINTRESOURCE(IDD_DIALOG_DICDETAIL),g_DICDlg,DicDetailDialogProc);
	return;
}

//��ʼ��PE��Ŀ¼����
void InitPEDicDetailView(HWND hDlg){
	hDicDetailEdit = GetDlgItem(hDlg,IDC_RICHEDIT1);
	SendMessage(hDicDetailEdit,EM_SETEVENTMASK,0,ENM_SELCHANGE|ENM_MOUSEEVENTS|ENM_CHANGE|ENM_KEYEVENTS|ENM_SCROLL|ENM_DROPFILES);
    SendMessage(hDicDetailEdit,EM_EXLIMITTEXT,0,-1);


	//��ӡ������
	//PrintExportTable(hDicDetailEdit);
}


//=================��ӡĿ¼������===================
//��ӡ������
VOID PrintExportTable(HWND hRichEdit){

	//���������ı����ַ���
	TCHAR szBuffer[0x1000];
	TCHAR szTmp[0x100];

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,1);
	//��õ�������FileBuffer�е�Addressλ��
	DWORD exportDirectoryFileAddress =(DWORD)pFileBuffer+RvaToFileOffset(pFileBuffer,pDataDirectory->VirtualAddress);

	//�ҵ�������
	PIMAGE_EXPORT_DIRECTORY pExportDirectory=(PIMAGE_EXPORT_DIRECTORY)exportDirectoryFileAddress;
	

	
	memset(szBuffer,0,0x1000);
	sprintf(szBuffer,"%s\n","=============��������Ϣ=================");						
	
	memset(szTmp,0,0x100);
	sprintf(szTmp,"Name:%s\n",(DWORD)pFileBuffer+RvaToFileOffset(pFileBuffer,pExportDirectory->Name));						
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
	sprintf(szTmp,"******��������******\n");						
	strcat(szBuffer,szTmp);
	

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
			memset(szTmp,0,0x100);
			sprintf(szTmp,"\n");						
			strcat(szBuffer,szTmp);
		}

		
	}

	CHARRANGE stcf; //����ṹ��EM_EXSETSEL��Ϣ��Ҫ����Ϣ��
	memset(&stcf,0,sizeof(stcf));//���ҽ���Ա��������Ϊ -1 �ǽ�������ı�β��
	stcf.cpMax = -1;
	stcf.cpMin = -1;
	SetWindowText(hRichEdit,szBuffer);

}


//��ӡ�ض�λ��
/*VOID PrintRelocationTable(LPVOID pFileBuffer)
{

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,6);
	//����ض�λ����FileBuffer�е�Addressλ��
	DWORD relocationFileBufferAddress =RvaToFileBufferAddress(pFileBuffer,pDataDirectory->VirtualAddress);

	//�ҵ�
	PIMAGE_BASE_RELOCATION pRelocationTables=(PIMAGE_BASE_RELOCATION)relocationFileBufferAddress;

	DWORD i=0;

	printf("=============�ض�λ����Ϣ=================\n");
	//pRelocationTables->SizeOfBlock || pRelocationTables->VirtualAddress ȫΪ0ʱ�����������
	while(pRelocationTables->VirtualAddress)
	{
		i++;
		DWORD sizeOfBlock=pRelocationTables->SizeOfBlock;
		DWORD virtualAddress=pRelocationTables->VirtualAddress;
		DWORD sectionIndex=RvaToSectionIndex(pFileBuffer,virtualAddress);
		
		//��ӡÿ���ض�λ��ľ�����Ϣ
		printf("***��:%d\tsizeOfBlock:%d\tvirtualAddress:%X\tsectionIndex:%d\n",i,sizeOfBlock,virtualAddress,sectionIndex);
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
			

			printf("%d\tChange:%s\trva:%X\tfileOffSet:%X\n",j+1,isChangeTxt,rvaChange,fileOffSet);
	
			pStartBlock++;

		}
		

		//��һ���ض�λ���ַ
		pRelocationTables=(PIMAGE_BASE_RELOCATION)((char*)pRelocationTables+sizeOfBlock);


	}


}

//��ӡ�����
VOID PrintImportTable(LPVOID pFileBuffer)
{

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,2);
	//��õ������FileBuffer�е�Addressλ��
	DWORD importTableFileBufferAddress =RvaToFileBufferAddress(pFileBuffer,pDataDirectory->VirtualAddress);

	//�ҵ���һ�������
	PIMAGE_IMPORT_DESCRIPTOR pImportTables=(PIMAGE_IMPORT_DESCRIPTOR)importTableFileBufferAddress;


	printf("=============�������Ϣ=================\n");
	
	while(pImportTables->Characteristics|pImportTables->FirstThunk|pImportTables->ForwarderChain|pImportTables->Name|pImportTables->OriginalFirstThunk|pImportTables->TimeDateStamp)
	{
		
		DWORD nameRVA=pImportTables->Name;
		char* pDllNames=(char*)RvaToFileBufferAddress(pFileBuffer,nameRVA);
		printf("***********%s*********\n",pDllNames);
		DWORD timeDateStamp = pImportTables->TimeDateStamp;
		printf("***timeStamp:%d***\n");
		DWORD originalFirstThunk=pImportTables->OriginalFirstThunk;
		DWORD firstThunk=pImportTables->FirstThunk;

		PDWORD pOriginalFirstThunk=(PDWORD)RvaToFileBufferAddress(pFileBuffer,originalFirstThunk);

		PDWORD pFirstThunk=(PDWORD)RvaToFileBufferAddress(pFileBuffer,firstThunk);

		//����OriginalFirstThunk
		printf("------------OriginalFirstThunk----------\n");
		while(*pOriginalFirstThunk){
			DWORD imageData=(DWORD)*pOriginalFirstThunk;
			//���λ�ж����λ�Ƿ�Ϊ1 �����,��ô��ȥ���λ��ֵ���Ǻ����ĵ������				

			if(imageData & 0x80000000){
				DWORD indexOfExport=imageData & 0x7FFFFFFF;//������ĺ������
				printf("�����������:%d\n",indexOfExport);

			}else{
				PIMAGE_IMPORT_BY_NAME pImportByName=(PIMAGE_IMPORT_BY_NAME)RvaToFileBufferAddress(pFileBuffer,imageData);//����������
				char* pImportFunNames=(char*)pImportByName->Name;
				printf("������������:%s\n",pImportFunNames);
			}
			pOriginalFirstThunk++;
		}

		//����FirstThunk
		printf("------------FirstThunk----------\n");
		while(*pFirstThunk){
			DWORD imageData=(DWORD)*pFirstThunk;
			//���λ�ж����λ�Ƿ�Ϊ1 �����,��ô��ȥ���λ��ֵ���Ǻ����ĵ������				

			if(imageData & 0x80000000){
				DWORD indexOfExport=imageData & 0x7FFFFFFF;//������ĺ������
				printf("���������:%d\n",indexOfExport);

			}else{
				PIMAGE_IMPORT_BY_NAME pImportByName=(PIMAGE_IMPORT_BY_NAME)RvaToFileBufferAddress(pFileBuffer,imageData);//����������
				char* pImportFunNames=(char*)pImportByName->Name;
				printf("������������:%s\n",pImportFunNames);
			}
			pFirstThunk++;
		}
	

		//��һ��������ַ
		pImportTables++;


	}


}

//��ӡ�󶨵����
VOID PrintBoundImportTable(LPVOID pFileBuffer)
{

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,12);

	//��õ������FileBuffer�е�Addressλ��
	DWORD importBoundTableFileBufferAddress =RvaToFileBufferAddress(pFileBuffer,pDataDirectory->VirtualAddress);

	//�ҵ���һ���󶨵����
	PIMAGE_BOUND_IMPORT_DESCRIPTOR pImportBoundTable=(PIMAGE_BOUND_IMPORT_DESCRIPTOR)importBoundTableFileBufferAddress;
	
	//�󶨵����ı�ͷ
	PIMAGE_BOUND_IMPORT_DESCRIPTOR pImportBoundTable1=pImportBoundTable;

	printf("=============�󶨵������Ϣ=================\n");
	DWORD i=0;

	while(pImportBoundTable->NumberOfModuleForwarderRefs|pImportBoundTable->OffsetModuleName|pImportBoundTable->TimeDateStamp)
	{
		DWORD timeDateStamp=pImportBoundTable->TimeDateStamp;
		WORD  numberOfModuleForwarderRefs=0;

		numberOfModuleForwarderRefs=pImportBoundTable->NumberOfModuleForwarderRefs;
		
		printf("---IMAGE_BOUND_IMPORT_DESCRIPTOR---\n");
		printf("numberOfModuleForwarderRefs:%d\n",numberOfModuleForwarderRefs);

		printf("timeDateStamp:%d\n",pImportBoundTable->TimeDateStamp);
		
		printf("OffsetModuleName:%s\n",(char*)pImportBoundTable1+pImportBoundTable->OffsetModuleName);

		DWORD j=0;
		
		PIMAGE_BOUND_FORWARDER_REF pBoundForwarderRef=(PIMAGE_BOUND_FORWARDER_REF)pImportBoundTable+1;

		
		printf("***********IMAGE_BOUND_FORWARDER_REF***************\n");

		for(j=0;j<numberOfModuleForwarderRefs;j++){
			
			printf("timeDateStamp:%d\n",pBoundForwarderRef->TimeDateStamp);
			printf("OffsetModuleName:%s\n",(char*)pImportBoundTable1+pBoundForwarderRef->OffsetModuleName);
			printf("Reserved:%d\n",pBoundForwarderRef->Reserved);

			pBoundForwarderRef++;
			
		}
		

		//��һ���󶨵�����ַ
		pImportBoundTable+=(numberOfModuleForwarderRefs+1);


	}


}

//��ӡ��Դ��
VOID PrintResourceTable(LPVOID pFileBuffer){
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
				WCHAR nodeString[256]={0};
				switch(id)
				{
					case 1: 
						wcscpy(nodeString,L"Cursor");
						printIndexTitle(index,nodeString); 
						break;
					case 2: 
						wcscpy(nodeString,L"Bitmap");
						printIndexTitle(index,nodeString); 
						break;
					case 3:
						wcscpy(nodeString,L"Icon");
						printIndexTitle(index,nodeString); 
						break;	
					case 4: 
						wcscpy(nodeString,L"Menu");
						printIndexTitle(index,nodeString); 
						break;
					case 5: 
						wcscpy(nodeString,L"Dialog");
						printIndexTitle(index,nodeString); 
						break;
					case 6: 
						wcscpy(nodeString,L"String");
						printIndexTitle(index,nodeString); 
						break;
					case 7:
						wcscpy(nodeString,L"FontDir");
						printIndexTitle(index,nodeString); 
						break;
					case 8:
						wcscpy(nodeString,L"Font");
						printIndexTitle(index,nodeString); 
						break;
					case 9: 
						wcscpy(nodeString,L"Accelerator");
						printIndexTitle(index,nodeString); 
						break;
					case 10: 
						wcscpy(nodeString,L"RCDATA");
						printIndexTitle(index,nodeString); 
						break;
					case 11:
						wcscpy(nodeString,L"MessageTable");
						printIndexTitle(index,nodeString); 
						break;
					case 12: 
						wcscpy(nodeString,L"GroupCursor");
						printIndexTitle(index,nodeString); 
						break;

					case 14: 
						wcscpy(nodeString,L"GroupIcon");
						printIndexTitle(index,nodeString); 
						break;

					case 16: 
						wcscpy(nodeString,L"Version");
						printIndexTitle(index,nodeString); 
						break;

					case 17: 
						wcscpy(nodeString,L"DlgInclude");
						printIndexTitle(index,nodeString); 
						break;

					case 19: 
						wcscpy(nodeString,L"PlugPlay");
						printIndexTitle(index,nodeString); 
						break;

					case 20: 
						wcscpy(nodeString,L"VXD");
						printIndexTitle(index,nodeString); 
						break;

					case 21: 
						wcscpy(nodeString,L"ANICursor");
						printIndexTitle(index,nodeString); 
						break;

					case 22: 
						wcscpy(nodeString,L"ANIIcon");
						printIndexTitle(index,nodeString); 
						break;

					case 23: 
						wcscpy(nodeString,L"HTML");
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
VOID printIndexTitle(int index,CHAR* names){
	int i=0;
	
	for(i=0;i<index;i++){
		if(i<index-1){
			printf("    ");
		}else{
			printf("|---");
		}
		
	}
	printf("%s\n",names);
}

//��ӡID
//index ����
//id
VOID printIndexID(int index,DWORD id){
	int i=0;
	
	for(i=0;i<index;i++){
		if(i<index-1){
			printf("    ");
		}else{
			printf("|---");
		}
	}
	if(index==3){
		printf("CodePage:%d\n",id);
	}else{
		printf("ID:%d\n",id);
	}

}*/




