#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__
#include <windows.h>
#include "myVectorHead.h"

					
#define SUCCESS           	-5 // �ɹ�		
#define ERRORS            	-1 // ʧ��		
#define MALLOC_ERROR		-2 // �����ڴ�ʧ��		
#define INDEX_ERROR		 	-3 // �����������

template <class T_ELE>
class Vector{
public:
	Vector();
	Vector(DWORD dwSize);
	~Vector();

public:
	DWORD 	at(DWORD dwIndex,OUT T_ELE& pEle);				//���ݸ����������õ�Ԫ��,����ֵ SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
    DWORD   push_back(T_ELE& myElement);						//��Ԫ�ش洢���������һ��λ��,������һ��Ԫ������ �� SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
	DWORD	pop_back(OUT T_ELE& pEle);					    //ɾ�����һ��Ԫ�� �� SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
	DWORD	insertInto(DWORD dwIndex,IN T_ELE& pElement);		//��ָ��λ������һ��Ԫ�أ�������һ��Ԫ������ �� SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
	DWORD	capacity();			//�����ڲ����ݵ�����£����ܴ洢����Ԫ��
	VOID	clear();			//�������Ԫ��
	BOOL	empty();			//�ж�Vector�Ƿ�Ϊ�� ����trueʱΪ��
	DWORD	erase(DWORD dwIndex,OUT T_ELE& pEle);		//ɾ��ָ��Ԫ��	�� SUCCESS ERROR MALLOC_ERROR INDEX_ERROR			
	DWORD	size();					//����VectorԪ�������Ĵ�С
private:
	DWORD expand();
private:
	DWORD m_dwIndex;//��һ����������
	DWORD m_dwIncrement;//ÿ�����ݵĴ�С
	DWORD m_dwLen;//��ǰ�����Ĵ�С
	DWORD m_dwInitSize;//Ĭ�ϳ�ʼ����С
	T_ELE* m_pVector;//������ָ��
};

template<class T_ELE>
Vector<T_ELE>::Vector():
m_dwIncrement(5),m_dwInitSize(100) //˽�г�Ա��ֵ
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

//��Ԫ�ش洢���������һ��λ��,������һ��Ԫ������ �� SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
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

//���ݸ����������õ�Ԫ��,����ֵ SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
template<class T_ELE>
DWORD Vector<T_ELE>::at(DWORD dwIndex,OUT T_ELE& pEle){

	if(dwIndex<0 || dwIndex>=m_dwLen){
		return INDEX_ERROR;
	}
	
	memcpy(&pEle,m_pVector+dwIndex,sizeof(T_ELE));
	
	return SUCCESS;

}

//��ָ��λ������һ��Ԫ�أ�������һ��Ԫ������ �� SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
template<class T_ELE>
DWORD Vector<T_ELE>::insertInto(DWORD dwIndex,IN T_ELE& pElement){

	//�ж�����Ƿ��ڷ�Χ��
	if(dwIndex<0 || dwIndex>=m_dwLen){
		return INDEX_ERROR;
	}

	//����
	if(m_dwIndex>=m_dwLen){
		if(expand()!=SUCCESS){
			return ERRORS;
		}
	}

	//��dwIndex֮���Ԫ�غ���
	int i=0;
	for(i=m_dwIndex;i>=dwIndex;i--){
		*(m_pVector+i)=*(m_pVector+i-1);
	}

	*(m_pVector+dwIndex)=pElement;
	
	m_dwIndex++;

	return m_dwIndex;

}

//ɾ��ָ��Ԫ��	
//���� m_dwIndex �� SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
template<class T_ELE>
DWORD Vector<T_ELE>::erase(DWORD dwIndex,OUT T_ELE& pEle){
	//�ж�����Ƿ��ڷ�Χ��
	if(dwIndex<0 || dwIndex>=m_dwLen){
		return INDEX_ERROR;
	}
   
	//���ָ��Ԫ��
	pEle=*(m_pVector+dwIndex);

	int i=0;
	for(i=dwIndex;i<m_dwIndex;i++){
		*(m_pVector+i)=*(m_pVector+i+1);
	}

	m_dwIndex--;

	return m_dwIndex;
}	

//ɾ�����һ��Ԫ�� 
//���أ�m_dwIndex�� SUCCESS ERROR MALLOC_ERROR INDEX_ERROR
template<class T_ELE>
DWORD Vector<T_ELE>::pop_back(OUT T_ELE& pEle){
	//�ж϶�̬�����Ƿ�Ϊ��
	if(!m_dwIndex){
		return INDEX_ERROR;
	}
	
	pEle=*(m_pVector+(m_dwIndex-1));
	m_dwIndex--;

	return m_dwIndex;

}

//����VectorԪ�������Ĵ�С
template<class T_ELE>
DWORD Vector<T_ELE>::size(){
	return m_dwIndex;
}

//�����ڲ����ݵ�����£����ܴ洢����Ԫ��
template<class T_ELE>
DWORD Vector<T_ELE>::capacity(){
	return m_dwLen-m_dwIndex;
}

//�������Ԫ��
template<class T_ELE>
VOID Vector<T_ELE>::clear(){
	m_dwIndex=0;
}

//�ж�Vector�Ƿ�Ϊ�� ����trueʱΪ��
template<class T_ELE>
BOOL Vector<T_ELE>::empty(){
	if(m_dwIndex){
		return false;
	}
	return true;
}		

#endif
