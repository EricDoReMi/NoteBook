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

#endif