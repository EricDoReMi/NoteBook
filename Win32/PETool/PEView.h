#ifndef __PEVIEW_H__
#define __PEVIEW_H__

#include "PEView.h"

//չʾPEͷ��Ϣ
void ShowPEHead();

//��ȡPEͷ��Ϣ
void ReadPEHead();

//չʾPESections��Ϣ
void ShowPESections();

//��ʼ��Section�б�
VOID InitSectionListView(HWND hDlg);

//����Section
VOID EnumPESections(HWND hListProcess);

//չʾPEDic��Ϣ
void ShowPEDic();

//��ʼ��Dic�б�
VOID InitPEDicView(HWND hDlg);

//����Ŀ¼������.....��ť����ʾĿ¼����Ի���
void AlertDicDetail();

//��Ŀ¼����Ի���
void ShowDicDetail();

//��ʼ��PE��Ŀ¼����
void InitPEDicDetailView(HWND hDlg);


//=================��ӡĿ¼������===================
//��ӡ������
VOID PrintExportTable(HWND hRichEdit);


//��ӡ�����
VOID PrintImportTable(HWND hRichEdit);

//��ӡ�ض�λ��
VOID PrintRelocationTable(HWND hRichEdit);

//��ӡ�󶨵����
/*VOID PrintBoundImportTable(LPVOID pFileBuffer);

//��ӡ��Դ��
VOID PrintResourceTable(LPVOID pFileBuffer);

//�ݹ��ӡ��Դ��ĺ���
//TableAddr:��Դ���ͷ��λ��
//pResourceDir
//index:����
VOID printResource(LPVOID pFileBuffer,DWORD TableAddr,PIMAGE_RESOURCE_DIRECTORY pResourceDir,int index);

//��ӡnames
//index ����
//names
VOID printIndexTitle(int index,WCHAR* names);

//��ӡnames
//index ����
//names
VOID printIndexTitle(int index,CHAR* names);

//��ӡID
//index ����
//id
VOID printIndexID(int index,DWORD id);*/

#endif