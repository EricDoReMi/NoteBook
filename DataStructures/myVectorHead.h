#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__
#include <windows.h>
#include "myVectorHead.h"

					
#define SUCCESS           	-5 // 成功		
#define ERRORS            	-1 // 失败		
#define MALLOC_ERROR		-2 // 申请内存失败		
#define INDEX_ERROR		 	-3 // 错误的索引号

template <class T_ELE>
class Vector{
public:
	Vector();
	Vector(DWORD dwSize);
	~Vector();

public:
	DWORD 	at(DWORD dwIndex,OUT T_ELE& pEle);				//根据给定的索引得到元素,返回值 SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
    DWORD   push_back(T_ELE& myElement);						//将元素存储到容器最后一个位置,返回下一个元素索引 或 SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
	DWORD	pop_back(OUT T_ELE& pEle);					    //删除最后一个元素 或 SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
	DWORD	insertInto(DWORD dwIndex,IN T_ELE& pElement);		//向指定位置新增一个元素，返回下一个元素索引 或 SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
	DWORD	capacity();			//返回在不增容的情况下，还能存储多少元素
	VOID	clear();			//清空所有元素
	BOOL	empty();			//判断Vector是否为空 返回true时为空
	DWORD	erase(DWORD dwIndex,OUT T_ELE& pEle);		//删除指定元素	或 SUCCESS ERROR MALLOC_ERROR INDEX_ERROR			
	DWORD	size();					//返回Vector元素数量的大小
private:
	DWORD expand();
private:
	DWORD m_dwIndex;//下一个可用索引
	DWORD m_dwIncrement;//每次增容的大小
	DWORD m_dwLen;//当前容器的大小
	DWORD m_dwInitSize;//默认初始化大小
	T_ELE* m_pVector;//容器的指针
};

template<class T_ELE>
Vector<T_ELE>::Vector():
m_dwIncrement(5),m_dwInitSize(100) //私有成员赋值
{
	m_pVector=new T_ELE[m_dwInitSize];
	memset(m_pVector,0,m_dwInitSize*sizeof(T_ELE));
	m_dwIndex=0;
	m_dwLen=m_dwInitSize;
	
}

template<class T_ELE>
Vector<T_ELE>::Vector(DWORD dwSize):
m_dwIncrement(5)
{	

	m_pVector=new T_ELE[dwSize];
	memset(m_pVector,0,dwSize*sizeof(T_ELE));
	m_dwInitSize=dwSize;
	m_dwIndex=0;
	m_dwLen=m_dwInitSize;
}

template<class T_ELE>
Vector<T_ELE>::~Vector()
{
	if(m_pVector){
		delete[] m_pVector;
		m_pVector=NULL;
	}
}

template<class T_ELE>
DWORD Vector<T_ELE>::expand()
{
	DWORD newLen=0;
	newLen=m_dwLen+m_dwIncrement;
	T_ELE* pT_ELE=new T_ELE[newLen];
	if(!pT_ELE){
		return MALLOC_ERROR;
	}
	memset(pT_ELE,0,newLen*sizeof(T_ELE));
	memcpy(pT_ELE,m_pVector,sizeof(T_ELE)*m_dwLen);
	delete[] m_pVector;
	m_pVector=pT_ELE;
	m_dwIndex=m_dwLen;
	m_dwLen=newLen;

	return SUCCESS;
}

//将元素存储到容器最后一个位置,返回下一个元素索引 或 SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
template<class T_ELE>
DWORD  Vector<T_ELE>::push_back(T_ELE& myElement)
{
	if(m_dwLen<=m_dwIndex){
		if(expand()!=SUCCESS){
			return ERRORS;
		}
	}
	
	memcpy(m_pVector+m_dwIndex,&myElement,sizeof(T_ELE));
	
	m_dwIndex++;
	return m_dwIndex;
}

//根据给定的索引得到元素,返回值 SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
template<class T_ELE>
DWORD Vector<T_ELE>::at(DWORD dwIndex,OUT T_ELE& pEle){

	if(dwIndex<0 || dwIndex>=m_dwLen){
		return INDEX_ERROR;
	}
	
	memcpy(&pEle,m_pVector+dwIndex,sizeof(T_ELE));
	
	return SUCCESS;

}

//向指定位置新增一个元素，返回下一个元素索引 或 SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
template<class T_ELE>
DWORD Vector<T_ELE>::insertInto(DWORD dwIndex,IN T_ELE& pElement){

	//判断序号是否在范围内
	if(dwIndex<0 || dwIndex>=m_dwLen){
		return INDEX_ERROR;
	}

	//扩容
	if(m_dwIndex>=m_dwLen){
		if(expand()!=SUCCESS){
			return ERRORS;
		}
	}

	//将dwIndex之后的元素后移
	int i=0;
	for(i=m_dwIndex;i>=dwIndex;i--){
		*(m_pVector+i)=*(m_pVector+i-1);
	}

	*(m_pVector+dwIndex)=pElement;
	
	m_dwIndex++;

	return m_dwIndex;

}

//删除指定元素	
//返回 m_dwIndex 或 SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
template<class T_ELE>
DWORD Vector<T_ELE>::erase(DWORD dwIndex,OUT T_ELE& pEle){
	//判断序号是否在范围内
	if(dwIndex<0 || dwIndex>=m_dwLen){
		return INDEX_ERROR;
	}
   
	//获得指定元素
	pEle=*(m_pVector+dwIndex);

	int i=0;
	for(i=dwIndex;i<m_dwIndex;i++){
		*(m_pVector+i)=*(m_pVector+i+1);
	}

	m_dwIndex--;

	return m_dwIndex;
}	

//删除最后一个元素 
//返回，m_dwIndex或 SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
template<class T_ELE>
DWORD Vector<T_ELE>::pop_back(OUT T_ELE& pEle){
	//判断动态数组是否为空
	if(!m_dwIndex){
		return INDEX_ERROR;
	}
	
	pEle=*(m_pVector+(m_dwIndex-1));
	m_dwIndex--;

	return m_dwIndex;

}

//返回Vector元素数量的大小
template<class T_ELE>
DWORD Vector<T_ELE>::size(){
	return m_dwIndex;
}

//返回在不增容的情况下，还能存储多少元素
template<class T_ELE>
DWORD Vector<T_ELE>::capacity(){
	return m_dwLen-m_dwIndex;
}

//清空所有元素
template<class T_ELE>
VOID Vector<T_ELE>::clear(){
	m_dwIndex=0;
}

//判断Vector是否为空 返回true时为空
template<class T_ELE>
BOOL Vector<T_ELE>::empty(){
	if(m_dwIndex){
		return false;
	}
	return true;
}		

#endif
