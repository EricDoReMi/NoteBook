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
	GetOpenFileName(&stopenfile);
	
	//打开PE对话框
	DialogBox(hAppInstance,MAKEINTRESOURCE(IDD_DIALOG_HEADER),g_hwndDlg,PEDialogProc);
	return;


}

//读取PE头信息
void ReadPEHead(){
	//用于存储字符串的数组
	TCHAR szBuffer[256];
	
	
	PIMAGE_FILE_HEADER pPEHeader = NULL;
	PIMAGE_OPTIONAL_HEADER32 pOptionHeader = NULL;
	
	
	if(!ReadPEFile(szFileName,&pFileBuffer)){
		return;
	}

	
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
