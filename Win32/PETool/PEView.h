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

//��ʼ��Dic�б�
VOID InitPEDIcView(HWND hDlg);

//չʾPEDic��Ϣ
void ShowPEDic();

//��ʼ��Dic�б�
VOID InitPEDicView(HWND hDlg);

#endif