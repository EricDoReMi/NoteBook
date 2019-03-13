#ifndef __MYLIST_H__
#define __MYLIST_H__
#include <windows.h>
#include "myListHead.h"
#include "myErrorHead.h"

//双向链表
template<class T_ELELIST>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
public:
	BOOL  IsEmpty();						//判断链表是否为空 空返回1 非空返回0				
	void  Clear();						//清空链表				
	DWORD GetElement(IN DWORD dwIndex,OUT T_ELELIST& Element);						//根据索引获取元素				
	DWORD GetElementIndex(IN T_ELELIST& Element);			//根据元素获取链表中的索引				
	DWORD Insert(IN T_ELELIST& Element);						//新增元素				
	DWORD Insert(IN DWORD dwIndex, IN T_ELELIST& Element);	//根据索引新增元素				
	DWORD Delete(IN DWORD dwIndex);						//根据索引删除元素				
	DWORD GetSize();						//获取链表中元素的数量				
private:
	typedef struct _NODE
	{
		T_ELELIST* pData;
		_NODE* pPrev;//前一个地址
		_NODE* pNext;//后一个地址

	}NODE,*PNODE;
	PNODE GetIndexCurrentNode(DWORD dwIndex);//获取索引为dwIndex的指针
	PNODE GetIndexPreviousNode(DWORD dwIndex);//获取索引为dwIndex的前一个节点指针
	PNODE GetIndexNextNode(DWORD dwIndex);//获取索引为dwIndex的后一个节点指针
private:
	PNODE m_pLeftPoint; //链表头指针，指向第一个节点
	PNODE m_pRightPoint;//链表尾指针，指向最后一个节点
	DWORD m_dwLength;//元素的数量
	
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

//判断链表是否为空 空返回1 非空返回0
template<class T_ELELIST>
BOOL LinkedList<T_ELELIST>::IsEmpty(){
	if((DWORD)m_pLeftPoint | (DWORD)m_pRightPoint | m_dwLength){
		return false;
	}
	return true;
}

//在末尾新增元素
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

//清空双向链表
template<class T_ELELIST>
void LinkedList<T_ELELIST>::Clear(){
	if(!IsEmpty()){
		//循环删除链表中的节点
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
