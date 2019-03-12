#include "myVector.h"

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
	T_ELE* m_pVector;//������ָ��
};


template<class T_ELE>
Vector<T_ELE>::Vector():
m_dwIncrement(5),m_dwInitSize(100)
{
	T_ELE* pT_ELE=new T_ELE[this->m_dwInitSize];
	memset(pT_ELE,this->m_dwInitSize*sizeof(T_ELE),0);
	this->m_dwIndex=0;
	this->m_dwLen=this->m_dwInitSize;
	this->m_pVector=pT_ELE;
}

template<class T_ELE>
Vector<T_ELE>::Vector(DWORD dwSize):
m_dwIncrement(5)
{	

	T_ELE* pT_ELE=new T_ELE[dwSize];
	memset(pT_ELE,this->m_dwInitSize*sizeof(T_ELE),0);
	this->m_dwInitSize=dwSize;
	this->m_dwIndex=0;
	this->m_dwLen=this->m_dwInitSize;
	this->m_pVector=pT_ELE;

}



