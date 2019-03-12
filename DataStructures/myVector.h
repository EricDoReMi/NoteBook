#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "myVector.h"
					
#define SUCCESS           	 1 // �ɹ�		
#define ERROR            	-1 // ʧ��		
#define MALLOC_ERROR		-2 // �����ڴ�ʧ��		
#define INDEX_ERROR		 	-3 // �����������

template <class T_ELE>
class Vector{
public:
	Vector();
	Vector(DWORD dwSize);
	~Vector();
public:
	DWORD	at(DWORD dwIndex,OUT T_ELE* pEle);				//���ݸ����������õ�Ԫ��				
    DWORD   push_back(T_ELE Element);						//��Ԫ�ش洢���������һ��λ��				
	VOID	pop_back();					                   //ɾ�����һ��Ԫ��				
	DWORD	insert(DWORD dwIndex, T_ELE Element);					//��ָ��λ������һ��Ԫ��				
	DWORD	capacity();					//�����ڲ����ݵ�����£����ܴ洢����Ԫ��				
	VOID	clear();					//�������Ԫ��				
	BOOL	empty();					//�ж�Vector�Ƿ�Ϊ�� ����trueʱΪ��				
	VOID	erase(DWORD dwIndex);					//ɾ��ָ��Ԫ��				
	DWORD	size();					//����VectorԪ�������Ĵ�С				

private:
	BOOL expand();
private:
	DWORD m_dwIndex;//��һ����������
	DWORD m_dwIncrement;//ÿ�����ݵĴ�С
	DWORD m_dwLen;//��ǰ�����Ĵ�С
	DWORD m_dwInitSize;//Ĭ�ϳ�ʼ����С
	T_ELE* *m_pVector;//������ָ��
};


#endif
