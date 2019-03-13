#ifndef __MYLIST_H__
#define __MYLIST_H__
#include <windows.h>
#include "myListHead.h"
#include "myErrorHead.h"

//˫������
template<class T_ELELIST>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
public:
	BOOL  IsEmpty();						//�ж������Ƿ�Ϊ�� �շ���1 �ǿշ���0				
	void  Clear();						//�������				
	DWORD GetElement(IN DWORD dwIndex,OUT T_ELELIST& Element);						//����������ȡԪ��				
	DWORD GetElementIndex(IN T_ELELIST& Element);			//����Ԫ�ػ�ȡ�����е�����				
	DWORD Insert(IN T_ELELIST& Element);						//����Ԫ��				
	DWORD Insert(IN DWORD dwIndex, IN T_ELELIST& Element);	//������������Ԫ��				
	DWORD Delete(IN DWORD dwIndex);						//��������ɾ��Ԫ��				
	DWORD GetSize();						//��ȡ������Ԫ�ص�����				
private:
	typedef struct _NODE
	{
		T_ELELIST* pData;
		_NODE* pPrev;//ǰһ����ַ
		_NODE* pNext;//��һ����ַ

	}NODE,*PNODE;
	PNODE GetIndexCurrentNode(DWORD dwIndex);//��ȡ����ΪdwIndex��ָ��
	PNODE GetIndexPreviousNode(DWORD dwIndex);//��ȡ����ΪdwIndex��ǰһ���ڵ�ָ��
	PNODE GetIndexNextNode(DWORD dwIndex);//��ȡ����ΪdwIndex�ĺ�һ���ڵ�ָ��
private:
	PNODE m_pLeftPoint; //����ͷָ�룬ָ���һ���ڵ�
	PNODE m_pRightPoint;//����βָ�룬ָ�����һ���ڵ�
	DWORD m_dwLength;//Ԫ�ص�����
	
};

template<class T_ELELIST>
LinkedList<T_ELELIST>::LinkedList()
:m_pLeftPoint(NULL),m_pRightPoint(0),m_dwLength(0)
{

}

template<class T_ELELIST>
LinkedList<T_ELELIST>::~LinkedList()
{
	Clear();
}

//�ж������Ƿ�Ϊ�� �շ���1 �ǿշ���0
template<class T_ELELIST>
BOOL LinkedList<T_ELELIST>::IsEmpty(){
	if((DWORD)m_pLeftPoint | (DWORD)m_pRightPoint | m_dwLength){
		return false;
	}
	return true;
}

//��ĩβ����Ԫ��
template<class T_ELELIST>
DWORD LinkedList<T_ELELIST>::Insert(IN T_ELELIST& Element)
{
	T_ELELIST* pNewElement=new T_ELELIST();
	*pNewElement=Element;
	PNODE pNewNode=new NODE();
	pNewNode->pData=pNewElement;

	if(IsEmpty()){
		m_pLeftPoint=pNewNode;
		pNewNode->pPrev=NULL;
		pNewNode->pNext=NULL;
	}else{
		pNewNode->pPrev=m_pRightPoint;
		pNewNode->pNext=NULL;
		
	}
	m_pRightPoint=pNewNode;
	m_dwLength++;
	return SUCCESS;
}

//���˫������
template<class T_ELELIST>
void LinkedList<T_ELELIST>::Clear(){
	if(!IsEmpty()){
		//ѭ��ɾ�������еĽڵ�
		PNODE pDeleteNode=m_pLeftPoint;
		PNODE pDeleteNextNode=Null;
		while(pDeleteNode){
			pDeleteNextNode=pDeleteNode->pNext;
			delete pDeleteNode->pData;
			delete pDeleteNode;
			pDeleteNode=pDeleteNextNode;	
		}
	}
}	

#endif
