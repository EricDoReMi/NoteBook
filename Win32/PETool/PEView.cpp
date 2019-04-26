//用于展示PE文件
#include "StdAfx.h"

//展示PE头信息
void ShowPEHead(){
	//读取导入的PE文件的路径
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
			MessageBox(g_hwndDlg,"不是有效的PE文件",0,MB_OK);
			return;
		}

		//打开PE对话框
		DialogBox(hAppInstance,MAKEINTRESOURCE(IDD_DIALOG_HEADER),g_hwndDlg,PEDialogProc);
	}
	
	
	return;


}

//读取PE头信息
void ReadPEHead(){
	//用于存储字符串的数组
	TCHAR szBuffer[256];
	
	
	PIMAGE_FILE_HEADER pPEHeader = NULL;
	PIMAGE_OPTIONAL_HEADER32 pOptionHeader = NULL;
	

	
	pPEHeader=getPEHeader(pFileBuffer);
	pOptionHeader=getOptionHeader(pFileBuffer);

	//入口点
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->AddressOfEntryPoint);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_AddressOfEntryPoint,WM_SETTEXT,0,(DWORD)szBuffer);
	
	//镜像基地址
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->ImageBase);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_ImageBase,WM_SETTEXT,0,(DWORD)szBuffer);
	
	//镜像大小
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->SizeOfImage);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_SizeOfImage,WM_SETTEXT,0,(DWORD)szBuffer);

	//代码基址
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->BaseOfCode);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_BaseOfCode,WM_SETTEXT,0,(DWORD)szBuffer);

	//数据基址
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->BaseOfData);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_BaseOfData,WM_SETTEXT,0,(DWORD)szBuffer);

	//内存对齐
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->SectionAlignment);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_SectionAlignment,WM_SETTEXT,0,(DWORD)szBuffer);

	//文件对齐
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->FileAlignment);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_FileAlignment,WM_SETTEXT,0,(DWORD)szBuffer);
	
	//标志值
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->Magic);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_Magic,WM_SETTEXT,0,(DWORD)szBuffer);

	//子系统
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->Subsystem);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_Subsystem,WM_SETTEXT,0,(DWORD)szBuffer);

	//区段数目
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pPEHeader->NumberOfSections);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_NumberOfSections,WM_SETTEXT,0,(DWORD)szBuffer);

	//时间戳
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pPEHeader->TimeDateStamp);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_TimeDateStamp,WM_SETTEXT,0,(DWORD)szBuffer);

	//PE头大小
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->SizeOfHeaders);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_SizeOfHeaders,WM_SETTEXT,0,(DWORD)szBuffer);

	//特征值
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pPEHeader->Characteristics);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_Characteristics,WM_SETTEXT,0,(DWORD)szBuffer);

	//校验和
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->CheckSum);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_CheckSum,WM_SETTEXT,0,(DWORD)szBuffer);

	//可选PE头大小
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pPEHeader->SizeOfOptionalHeader);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_SizeOfOptionalHeader,WM_SETTEXT,0,(DWORD)szBuffer);

	//目录项数目
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->NumberOfRvaAndSizes);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_NumberOfRvaAndSizes,WM_SETTEXT,0,(DWORD)szBuffer);

}

//展示PESections信息
void ShowPESections(){

	
	//打开PESection对话框
	DialogBox(hAppInstance,MAKEINTRESOURCE(IDD_DIALOG_SECTION),g_PEDlg,SectionDialogProc);
	return;


}


//初始化Section列表
VOID InitSectionListView(HWND hDlg){
	LV_COLUMN lv;//存储列								
	HWND hListProcess;//获得ListView句柄							
									
	//初始化								
	memset(&lv,0,sizeof(LV_COLUMN));								
	//获取IDC_LIST_SECTIONVIEW句柄								
	hListProcess = GetDlgItem(hDlg,IDC_LIST_SECTIONVIEW);								
	//设置整行选中								
	SendMessage(hListProcess,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_FULLROWSELECT,LVS_EX_FULLROWSELECT);								
									
	//第一列								
	lv.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;								
	lv.pszText = TEXT("节名");				//列标题				
	lv.cx = 150;							//列宽
	lv.iSubItem = 0;								
	//ListView_InsertColumn(hListProcess, 0, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,0,(DWORD)&lv);								
	//第二列								
	lv.pszText = TEXT("文件偏移");								
	lv.cx = 100;								
	lv.iSubItem = 1;								
	//ListView_InsertColumn(hListProcess, 1, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,1,(DWORD)&lv);								
	//第三列								
	lv.pszText = TEXT("文件大小");								
	lv.cx = 100;								
	lv.iSubItem = 2;								
	ListView_InsertColumn(hListProcess, 2, &lv);								
	//第四列								
	lv.pszText = TEXT("内存偏移");								
	lv.cx = 100;								
	lv.iSubItem = 3;								
	ListView_InsertColumn(hListProcess, 3, &lv);
	//第五列								
	lv.pszText = TEXT("内存大小");								
	lv.cx = 100;								
	lv.iSubItem = 4;								
	ListView_InsertColumn(hListProcess, 4, &lv);

	//第六列								
	lv.pszText = TEXT("节区属性");								
	lv.cx = 100;								
	lv.iSubItem = 5;								
	ListView_InsertColumn(hListProcess, 5, &lv);

	EnumPESections(hListProcess);
}

//遍历Section
VOID EnumPESections(HWND hListProcess){
	//用于存储字符串的缓存区
	TCHAR szBuffer[0x50];

	LV_ITEM vitem;						

	//获取节表信息
	PIMAGE_SECTION_HEADER pSectionHeader = NULL;
	
	pSectionHeader=getSectionHeader(pFileBuffer);
	
	WORD sectionNum=getSectionNum(pFileBuffer);

	WORD i=0;
	for(i=0;i<sectionNum;i++){
		BYTE names[9]={0};
		BYTE* p_name=names;
		p_name=pSectionHeader->Name;

		//初始化
		memset(&vitem,0,sizeof(LV_ITEM));
		vitem.mask = LVIF_TEXT;

		//节名
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%s",p_name);
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;//第几行						
		vitem.iSubItem = 0;	//第几列				
		//这是一个宏，和SendMessage做的事情是一样的，第一列时要用ListView_InsertItem，后面的列用ListView_SetItem
		//ListView_InsertItem(hListProcess, &vitem);
		SendMessage(hListProcess, LVM_INSERTITEM,0,(DWORD)&vitem);


		//文件偏移了
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pSectionHeader->PointerToRawData);						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 1;						
		ListView_SetItem(hListProcess, &vitem);	

		//文件对齐后的尺寸
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pSectionHeader->SizeOfRawData);						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 2;						
		ListView_SetItem(hListProcess, &vitem);	

		//内存偏移了
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",FileOffsetToRva(pFileBuffer,pSectionHeader->PointerToRawData));						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 3;						
		ListView_SetItem(hListProcess, &vitem);	

		//内存对齐后的尺寸
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pSectionHeader->Misc.VirtualSize);						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 4;						
		ListView_SetItem(hListProcess, &vitem);	

		//节属性
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pSectionHeader->Characteristics);						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 5;						
		ListView_SetItem(hListProcess, &vitem);	

		//获得下一个节表信息
		pSectionHeader=(PIMAGE_SECTION_HEADER)((char*)pSectionHeader+40);
		
		
	}
	
   						

}


//展示PEDic信息
void ShowPEDic(){
	
	//打开PEDic对话框
	DialogBox(hAppInstance,MAKEINTRESOURCE(IDD_DIALOG_DIC),g_PEDlg,DicDialogProc);
	return;


}

//初始化Dic列表
VOID InitPEDicView(HWND hDlg){

	PIMAGE_OPTIONAL_HEADER32 pOptionHeader = NULL;
	pOptionHeader=getOptionHeader(pFileBuffer);
	
	PIMAGE_DATA_DIRECTORY pImageDataDirectory=pOptionHeader->DataDirectory;

	//导出表、导入表、资源表、异常信息表、安全证书表、重定位表、调试信息表、版权所有表、全局指针表
    //TLS表、加载配置表、绑定导入表、IAT表、延迟导入表、COM信息表 最后一个保留未使用。
	
	PIMAGE_DATA_DIRECTORY pDataDirectory=NULL;

	//用于设置文本的字符串
	TCHAR szBuffer[0x50];
	
	
	DWORD i=0;
	int DicNum=1010;
	for(i=0;i<16;i++){
		DicNum=1010+i*2;
		pDataDirectory=pImageDataDirectory+i;
		
		//获得EDIT控件窗口指针
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


//按照目录表点击的.....按钮来显示目录详情对话框
void AlertDicDetail(){
		//获得PE目录详细的信息
		//创建来PE目录详细的信息的线程
		HANDLE	hPEDicDetailThread = ::CreateThread(NULL, 0, PEDicDetailThread, NULL, 0, NULL);
		::CloseHandle(hPEDicDetailThread);

		return;
		
}

//打开目录详情对话框
void ShowDicDetail(){
	if(checkDicTableExist()){
		DialogBox(hAppInstance,MAKEINTRESOURCE(IDD_DIALOG_DICDETAIL),g_DICDlg,DicDetailDialogProc);

	}else{
		MessageBox(g_DICDlg,TEXT("没有相关目录详情"),0,MB_OK);
	}
	
	return;
}

//初始化PE的目录详情
void InitPEDicDetailView(HWND hDlg){
	hDicDetailEdit = GetDlgItem(hDlg,IDC_RICHEDIT1);
	SendMessage(hDicDetailEdit,EM_SETEVENTMASK,0,ENM_SELCHANGE|ENM_MOUSEEVENTS|ENM_CHANGE|ENM_KEYEVENTS|ENM_SCROLL|ENM_DROPFILES);
    SendMessage(hDicDetailEdit,EM_EXLIMITTEXT,0,-1);
	
	switch(IDC_BUTTON_DIC_Index)
		{
			case IDC_BUTTON_DIC_IMPORT:
				{
					//打印导入表
					PrintImportTable(hDicDetailEdit);
						
					break;
				}
						
			case IDC_BUTTON_DIC_EXPORT:
				{	
					//打印导出表
					PrintExportTable(hDicDetailEdit);
					
					break;
				}
			case IDC_BUTTON_DIC_RESOURSE:
				{	
					//打印资源表
					PrintResourceTable(hDicDetailEdit);
					
					break;
				}
			case IDC_BUTTON_DIC_RELOCATION:
				{	
					//打印重定位表
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

//=================打印目录表详情===================
//打印导出表
VOID PrintExportTable(HWND hRichEdit){

	//用于设置文本的字符串
	TCHAR szBuffer[0x10000];
	TCHAR szTmp[0x100];

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,1);
	//获得导出表在FileBuffer中的Address位置
	DWORD exportDirectoryFileAddress =(DWORD)pFileBuffer+RvaToFileOffset(pFileBuffer,pDataDirectory->VirtualAddress);

	//找到导出表
	PIMAGE_EXPORT_DIRECTORY pExportDirectory=(PIMAGE_EXPORT_DIRECTORY)exportDirectoryFileAddress;
	

	
	memset(szBuffer,0,0x10000);
	sprintf(szBuffer,TEXT("%s"),TEXT("=============导出表信息=================\n"));						
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
	sprintf(szTmp,TEXT("******导出表函数******\n"));						
	strcat(szBuffer,szTmp);

	//下一组输入区
	appendRichEdit(hRichEdit,szBuffer,0x10000);
	
	DWORD i=0;
	DWORD j=0;

	PDWORD pFileAddressOfFunctions=(PDWORD)((DWORD)pFileBuffer+RvaToFileOffset(pFileBuffer,pExportDirectory->AddressOfFunctions));
	PDWORD pFileAddressOfNames=(PDWORD)((DWORD)pFileBuffer+RvaToFileOffset(pFileBuffer,pExportDirectory->AddressOfNames));
	PWORD pFileAddressOfNameOrdinals=(PWORD)((DWORD)pFileBuffer+RvaToFileOffset(pFileBuffer,pExportDirectory->AddressOfNameOrdinals));
	
	//打印函数信息
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
		//下一组输入区
		appendRichEdit(hRichEdit,szBuffer,0x10000);
		
	}




}

//打印导入表
VOID PrintImportTable(HWND hRichEdit)
{
	//用于设置文本的字符串
	TCHAR szBuffer[0x10000];
	TCHAR szTmp[0x100];

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,2);
	//获得导入表在FileBuffer中的Address位置
	DWORD importTableFileBufferAddress =RvaToFileBufferAddress(pFileBuffer,pDataDirectory->VirtualAddress);

	//找到第一个导入表
	PIMAGE_IMPORT_DESCRIPTOR pImportTables=(PIMAGE_IMPORT_DESCRIPTOR)importTableFileBufferAddress;


	memset(szBuffer,0,0x10000);
	memset(szTmp,0,0x100);
	sprintf(szTmp,TEXT("=============导入表信息=================\n"));						
	strcat(szBuffer,szTmp);
	//下一组输入区
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

		//遍历OriginalFirstThunk
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("------------OriginalFirstThunk----------\n"));						
		strcat(szBuffer,szTmp);

		//下一组输入区
		appendRichEdit(hRichEdit,szBuffer,0x10000);

		while(*pOriginalFirstThunk){
			DWORD imageData=(DWORD)*pOriginalFirstThunk;
			//最高位判断最高位是否为1 如果是,那么除去最高位的值就是函数的导出序号				

			if(imageData & 0x80000000){
				DWORD indexOfExport=imageData & 0x7FFFFFFF;//导出表的函数序号

				memset(szTmp,0,0x100);
				sprintf(szTmp,TEXT("导出表函数序号:%d\n"),indexOfExport);						
				strcat(szBuffer,szTmp);

			}else{
				PIMAGE_IMPORT_BY_NAME pImportByName=(PIMAGE_IMPORT_BY_NAME)RvaToFileBufferAddress(pFileBuffer,imageData);//导出表函数名
				char* pImportFunNames=(char*)pImportByName->Name;
	

				memset(szTmp,0,0x100);
				sprintf(szTmp,TEXT("导出表函数名称:%s\n"),pImportFunNames);						
				strcat(szBuffer,szTmp);
				
			}

			
			pOriginalFirstThunk++;
			
		}


		//遍历FirstThunk
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("------------FirstThunk----------\n"));						
		strcat(szBuffer,szTmp);


		while(*pFirstThunk){
			DWORD imageData=(DWORD)*pFirstThunk;
			//最高位判断最高位是否为1 如果是,那么除去最高位的值就是函数的导出序号				

			if(imageData & 0x80000000){
				DWORD indexOfExport=imageData & 0x7FFFFFFF;//导出表的函数序号
				
				memset(szTmp,0,0x100);
				sprintf(szTmp,TEXT("导出表序号:%d\n"),indexOfExport);						
				strcat(szBuffer,szTmp);

			}else{
				PIMAGE_IMPORT_BY_NAME pImportByName=(PIMAGE_IMPORT_BY_NAME)RvaToFileBufferAddress(pFileBuffer,imageData);//导出表函数名
				char* pImportFunNames=(char*)pImportByName->Name;

				memset(szTmp,0,0x100);
				sprintf(szTmp,TEXT("导出表函数名称:%s\n"),pImportFunNames);						
				strcat(szBuffer,szTmp);
			}

			
			pFirstThunk++;
		}
	

		//下一个导入表地址
		pImportTables++;
		//下一组输入区
		appendRichEdit(hRichEdit,szBuffer,0x10000);

		
	}


}

//打印IAT
VOID PrintIatTable(HWND hRichEdit)
{
	//用于设置文本的字符串
	TCHAR szBuffer[0x10000];
	TCHAR szTmp[0x100];

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,2);
	//获得导入表在FileBuffer中的Address位置
	DWORD importTableFileBufferAddress =RvaToFileBufferAddress(pFileBuffer,pDataDirectory->VirtualAddress);

	//找到第一个导入表
	PIMAGE_IMPORT_DESCRIPTOR pImportTables=(PIMAGE_IMPORT_DESCRIPTOR)importTableFileBufferAddress;


	memset(szBuffer,0,0x10000);
	memset(szTmp,0,0x100);
	sprintf(szTmp,TEXT("=============IAT表信息=================\n"));						
	strcat(szBuffer,szTmp);
	//下一组输入区
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



		//遍历FirstThunk
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("------------FirstThunk----------\n"));						
		strcat(szBuffer,szTmp);


		while(*pFirstThunk){
			DWORD imageData=(DWORD)*pFirstThunk;
			//最高位判断最高位是否为1 如果是,那么除去最高位的值就是函数的导出序号				

			if(imageData & 0x80000000){
				DWORD indexOfExport=imageData & 0x7FFFFFFF;//导出表的函数序号
				
				memset(szTmp,0,0x100);
				sprintf(szTmp,TEXT("导出表序号:%d\n"),indexOfExport);						
				strcat(szBuffer,szTmp);

			}else{
				PIMAGE_IMPORT_BY_NAME pImportByName=(PIMAGE_IMPORT_BY_NAME)RvaToFileBufferAddress(pFileBuffer,imageData);//导出表函数名
				char* pImportFunNames=(char*)pImportByName->Name;

				memset(szTmp,0,0x100);
				sprintf(szTmp,TEXT("导出表函数名称:%s\n"),pImportFunNames);						
				strcat(szBuffer,szTmp);
			}

			
			pFirstThunk++;
		}
	

		//下一个导入表地址
		pImportTables++;
		//下一组输入区
		appendRichEdit(hRichEdit,szBuffer,0x10000);

		
	}


}

//打印重定位表
VOID PrintRelocationTable(HWND hRichEdit)
{
	//用于设置文本的字符串
	TCHAR szBuffer[0x10000];
	TCHAR szTmp[0x100];

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,6);
	//获得重定位表在FileBuffer中的Address位置
	DWORD relocationFileBufferAddress =RvaToFileBufferAddress(pFileBuffer,pDataDirectory->VirtualAddress);

	//找到
	PIMAGE_BASE_RELOCATION pRelocationTables=(PIMAGE_BASE_RELOCATION)relocationFileBufferAddress;

	DWORD i=0;

	memset(szBuffer,0,0x10000);
	sprintf(szBuffer,TEXT("%s"),TEXT("=============重定位表信息=================\n"));
	//下一组输入区
	appendRichEdit(hRichEdit,szBuffer,0x10000);

	//pRelocationTables->SizeOfBlock || pRelocationTables->VirtualAddress 全为0时，则遍历结束
	while(pRelocationTables->VirtualAddress || pRelocationTables->SizeOfBlock)
	{
		i++;
		DWORD sizeOfBlock=pRelocationTables->SizeOfBlock;
		DWORD virtualAddress=pRelocationTables->VirtualAddress;
		DWORD sectionIndex=RvaToSectionIndex(pFileBuffer,virtualAddress);
		
		//打印每个重定位表的具体信息
		
		memset(szTmp,0,0x100);
		sprintf(szTmp,TEXT("***表:%d\tsizeOfBlock:%d\tvirtualAddress:%X\tsectionIndex:%d\n"),i,sizeOfBlock,virtualAddress,sectionIndex);						
		strcat(szBuffer,szTmp);

		

		//计算BLOCK的数量
		DWORD numBlock=0;
		numBlock=(sizeOfBlock-8)/2;
		
		DWORD j=0;
		PWORD pStartBlock=(PWORD)pRelocationTables+4;
		for(j=0;j<numBlock;j++)
		{
			//硬编码地方的地址
			DWORD rvaChange=(DWORD)((*(PWORD)pStartBlock)&0x0FFF)+virtualAddress;
			DWORD isChange=(*(PWORD)pStartBlock)&0xF000;
			DWORD fileOffSet=RvaToFileOffset(pFileBuffer,rvaChange);
			char* isChangeTxt=NULL;
			isChangeTxt="否";
			if((isChange^0x3000)==0){
				isChangeTxt="是";
			}
			
			
			memset(szTmp,0,0x100);
			sprintf(szTmp,TEXT("%d\tChange:%s\trva:%X\tfileOffSet:%X\n"),j+1,isChangeTxt,rvaChange,fileOffSet);						
			strcat(szBuffer,szTmp);

			pStartBlock++;

			

		}
		

		//下一个重定位表地址
		pRelocationTables=(PIMAGE_BASE_RELOCATION)((char*)pRelocationTables+sizeOfBlock);
		appendRichEdit(hRichEdit,szBuffer,0x10000);
		

	}




}



//打印绑定导入表
VOID PrintBoundImportTable(HWND hRichEdit)
{

	//用于设置文本的字符串
	TCHAR szBuffer[0x10000];
	TCHAR szTmp[0x100];


	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,12);

	//获得导入表在FileBuffer中的Address位置
	DWORD importBoundTableFileBufferAddress =RvaToFileBufferAddress(pFileBuffer,pDataDirectory->VirtualAddress);

	//找到第一个绑定导入表
	PIMAGE_BOUND_IMPORT_DESCRIPTOR pImportBoundTable=(PIMAGE_BOUND_IMPORT_DESCRIPTOR)importBoundTableFileBufferAddress;
	
	//绑定导入表的表头
	PIMAGE_BOUND_IMPORT_DESCRIPTOR pImportBoundTable1=pImportBoundTable;
	
	memset(szBuffer,0,0x10000);


	sprintf(szBuffer,TEXT("%s"),TEXT("=============绑定导入表信息=================\n"));
	//下一组输入区
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
		

		//下一组输入区
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
		
		
		//下一组输入区
		appendRichEdit(hRichEdit,szBuffer,0x10000);

		//下一个绑定导入表地址
		pImportBoundTable+=(numberOfModuleForwarderRefs+1);


	}


}

//打印资源表
VOID PrintResourceTable(HWND hRichEdit){
	//用于设置文本的字符串
	TCHAR szBuffer[0x10000];
	
	memset(szBuffer,0,0x10000);

	sprintf(szBuffer,TEXT("%s"),TEXT("=============资源表信息=================\n"));
	//下一组输入区
	appendRichEdit(hRichEdit,szBuffer,0x10000);

	PIMAGE_DATA_DIRECTORY pDataDirectory=getDataDirectory(pFileBuffer,3);

	//获得资源表在FileBuffer中的Address位置
	DWORD resourceTableFileBufferAddress =RvaToFileBufferAddress(pFileBuffer,pDataDirectory->VirtualAddress);
	
	printResource(pFileBuffer,(DWORD)resourceTableFileBufferAddress,(PIMAGE_RESOURCE_DIRECTORY)resourceTableFileBufferAddress,1);
}

//递归打印资源表的函数
//TableAddr:资源表表头的位置
//pResourceDir
//index:层数
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

//打印names
//index 层数
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

//打印names
//index 层数
//names
VOID printIndexTitle(int index,TCHAR* names){

	//用于设置文本的字符串
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
		//下一组输入区
		appendRichEdit(hDicDetailEdit,szBuffer,0x10000);

}

//打印ID
//index 层数
//id
VOID printIndexID(int index,DWORD id){
	int i=0;

	//用于设置文本的字符串
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

	//下一组输入区
	appendRichEdit(hDicDetailEdit,szBuffer,0x10000);

}




