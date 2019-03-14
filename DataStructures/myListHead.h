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
	DWORD Insert(IN DWORD dwIndex,IN T_ELELIST& Element);	//根据索引新增元素				
	DWORD Delete(IN DWORD dwIndex);						//根据索引删除元素				
	DWORD GetSize();//获取链表中元素的数量				
	
private:
	typedef struct _NODE
	{
		T_ELELIST* pData;
		_NODE* pPrev;//前一个地址
		_NODE* pNext;//后一个地址

	}NODE,*PNODE;
	PNODE GetIndexCurrentNode(DWORD dwIndex);//获取索引为dwIndex的指针


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
		m_pRightPoint->pNext=pNewNode;
		pNewNode->pNext=NULL;
		
	}
	m_pRightPoint=pNewNode;
	m_dwLength++;
	return SUCCESS;
}

//根据索引新增元素
template<class T_ELELIST>
DWORD LinkedList<T_ELELIST>::Insert(IN DWORD dwIndex, IN T_ELELIST& Element)
{
	//判断索引是否合法
	if(dwIndex<0 || dwIndex>=m_dwLength){
		return INDEX_ERROR;
	}

	T_ELELIST* pNewElement=new T_ELELIST();
	*pNewElement=Element;
	PNODE pNewNode=new NODE();
	pNewNode->pData=pNewElement;

	//索引为0的情况
	if(dwIndex==0)
	{
		
		pNewNode->pPrev=NULL;
		pNewNode->pNext=m_pLeftPoint;
		m_pLeftPoint->pPrev=pNewNode;
		m_pLeftPoint=pNewNode;
		
		
	//索引在中间的情况
	}else if(dwIndex<m_dwLength-1)
	{
		PNODE pOldNode = GetIndexCurrentNode(dwIndex);
		pNewNode->pPrev=pOldNode->pPrev;
		pNewNode->pNext=pOldNode;
		pOldNode->pPrev->pNext=pNewNode;
		pOldNode->pPrev=pNewNode;
		

	//索引为最后一个的情况		
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

//获取索引为dwIndex的指针
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

//清空双向链表
template<class T_ELELIST>
void LinkedList<T_ELELIST>::Clear()
{

	if(!IsEmpty())
	{
		//循环删除链表中的节点
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

//根据索引获取元素
template<class T_ELELIST>
DWORD LinkedList<T_ELELIST>::GetElement(IN DWORD dwIndex,OUT T_ELELIST& Element){
		//判断索引是否合法
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

//根据元素获取链表中的索引
//没找到返回-1
//找到则返回第一个找到的值
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

//根据索引删除元素
template<class T_ELELIST>
DWORD LinkedList<T_ELELIST>::Delete(IN DWORD dwIndex)
{
	//判断索引是否合法
	if(dwIndex<0 || dwIndex>=m_dwLength){
		return INDEX_ERROR;
	}

	PNODE CurrentNode=GetIndexCurrentNode(dwIndex);

	if(!CurrentNode){
		return ERRORS;
	}
	
	//改指针
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

	//删除
	delete CurrentNode->pData;
	delete CurrentNode;
	m_dwLength--;
	return SUCCESS;
}

//获取链表中元素的数量
template<class T_ELELIST>
DWORD LinkedList<T_ELELIST>::GetSize(){
	return m_dwLength;
}
#endif
