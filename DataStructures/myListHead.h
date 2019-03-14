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
	DWORD Insert(IN DWORD dwIndex,IN T_ELELIST& Element);	//������������Ԫ��				
	DWORD Delete(IN DWORD dwIndex);						//��������ɾ��Ԫ��				
	DWORD GetSize();//��ȡ������Ԫ�ص�����				
	
private:
	typedef struct _NODE
	{
		T_ELELIST* pData;
		_NODE* pPrev;//ǰһ����ַ
		_NODE* pNext;//��һ����ַ

	}NODE,*PNODE;
	PNODE GetIndexCurrentNode(DWORD dwIndex);//��ȡ����ΪdwIndex��ָ��


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
		m_pRightPoint->pNext=pNewNode;
		pNewNode->pNext=NULL;
		
	}
	m_pRightPoint=pNewNode;
	m_dwLength++;
	return SUCCESS;
}

//������������Ԫ��
template<class T_ELELIST>
DWORD LinkedList<T_ELELIST>::Insert(IN DWORD dwIndex, IN T_ELELIST& Element)
{
	//�ж������Ƿ�Ϸ�
	if(dwIndex<0 || dwIndex>=m_dwLength){
		return INDEX_ERROR;
	}

	T_ELELIST* pNewElement=new T_ELELIST();
	*pNewElement=Element;
	PNODE pNewNode=new NODE();
	pNewNode->pData=pNewElement;

	//����Ϊ0�����
	if(dwIndex==0)
	{
		
		pNewNode->pPrev=NULL;
		pNewNode->pNext=m_pLeftPoint;
		m_pLeftPoint->pPrev=pNewNode;
		m_pLeftPoint=pNewNode;
		
		
	//�������м�����
	}else if(dwIndex<m_dwLength-1)
	{
		PNODE pOldNode = GetIndexCurrentNode(dwIndex);
		pNewNode->pPrev=pOldNode->pPrev;
		pNewNode->pNext=pOldNode;
		pOldNode->pPrev->pNext=pNewNode;
		pOldNode->pPrev=pNewNode;
		

	//����Ϊ���һ�������		
	}else if(dwIndex==m_dwLength-1)
	{
		
		pNewNode->pPrev=m_pRightPoint;
		pNewNode->pNext=NULL;
		m_pRightPoint->pNext=pNewNode;
		m_pRightPoint=pNewNode;

	}

	m_dwLength++;
	return SUCCESS;
}

//��ȡ����ΪdwIndex��ָ��
template<class T_ELELIST>
LinkedList<T_ELELIST>::PNODE LinkedList<T_ELELIST>::GetIndexCurrentNode(DWORD dwIndex)
{
	PNODE pSelectNode=NULL;
	if(dwIndex<0 || (dwIndex>=m_dwLength)){
		return pSelectNode;
	}

	pSelectNode=m_pLeftPoint;
	PNODE pSelectNextNode=NULL;
	int i=0;

	for(i=0;i<dwIndex;i++)
	{
		pSelectNextNode=pSelectNode->pNext;
		pSelectNode=pSelectNextNode;

	}
	
	return pSelectNode;

}

//���˫������
template<class T_ELELIST>
void LinkedList<T_ELELIST>::Clear()
{

	if(!IsEmpty())
	{
		//ѭ��ɾ�������еĽڵ�
		PNODE pDeleteNode=m_pLeftPoint;
		PNODE pDeleteNextNode=Null;
		while(pDeleteNode)
		{
			pDeleteNextNode=pDeleteNode->pNext;
			delete pDeleteNode->pData;
			delete pDeleteNode;
			pDeleteNode=pDeleteNextNode;	
		}

		m_dwLength=0;
	}
}

//����������ȡԪ��
template<class T_ELELIST>
DWORD LinkedList<T_ELELIST>::GetElement(IN DWORD dwIndex,OUT T_ELELIST& Element){
		//�ж������Ƿ�Ϸ�
	if(dwIndex<0 || dwIndex>=m_dwLength){
		return INDEX_ERROR;
	}
	PNODE CurrentNode=GetIndexCurrentNode(dwIndex);

	if(!CurrentNode){
		return ERRORS;
	}
	
	Element=*(CurrentNode->pData);

	return SUCCESS;
}

//����Ԫ�ػ�ȡ�����е�����
//û�ҵ�����-1
//�ҵ��򷵻ص�һ���ҵ���ֵ
template<class T_ELELIST>
DWORD LinkedList<T_ELELIST>::GetElementIndex(IN T_ELELIST& Element){

	if(m_dwLength==0){
		return -1;
	}
	
	PNODE CurrentNode=NULL;

	int i=0;
	for(i=0;i<m_dwLength;i++){
		CurrentNode=GetIndexCurrentNode(i);
		if(*(CurrentNode->pData)==Element){
			return i;
		}
	}

	return -1;
}

//��������ɾ��Ԫ��
template<class T_ELELIST>
DWORD LinkedList<T_ELELIST>::Delete(IN DWORD dwIndex)
{
	//�ж������Ƿ�Ϸ�
	if(dwIndex<0 || dwIndex>=m_dwLength){
		return INDEX_ERROR;
	}

	PNODE CurrentNode=GetIndexCurrentNode(dwIndex);

	if(!CurrentNode){
		return ERRORS;
	}
	
	//��ָ��
	if(m_dwLength==1 && dwIndex==0){
		m_pLeftPoint=NULL;
		m_pRightPoint=NULL;
	}else if(dwIndex==0 && m_dwLength>1){
		CurrentNode->pNext->pPrev=NULL;
		m_pLeftPoint=CurrentNode->pNext;
	}else if(dwIndex>0 && dwIndex<(m_dwLength-1)){
		CurrentNode->pPrev->pNext=CurrentNode->pNext;
		CurrentNode->pNext->pPrev=CurrentNode->pPrev;

	}else if(dwIndex>0 && dwIndex==(m_dwLength-1)){
		CurrentNode->pPrev->pNext=NULL;
		m_pRightPoint=CurrentNode->pPrev;
	}

	//ɾ��
	delete CurrentNode->pData;
	delete CurrentNode;
	m_dwLength--;
	return SUCCESS;
}

//��ȡ������Ԫ�ص�����
template<class T_ELELIST>
DWORD LinkedList<T_ELELIST>::GetSize(){
	return m_dwLength;
}
#endif
