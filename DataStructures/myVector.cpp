#include "myVector.h"

template <class T_ELE>
class Vector{
public:
	Vector();
	Vector(DWORD dwSize);
	~Vector();
public:
	DWORD	at(DWORD dwIndex,OUT T_ELE* pEle);				//根据给定的索引得到元素				
    DWORD   push_back(T_ELE Element);						//将元素存储到容器最后一个位置				
	VOID	pop_back();					                   //删除最后一个元素				
	DWORD	insert(DWORD dwIndex, T_ELE Element);					//向指定位置新增一个元素				
	DWORD	capacity();					//返回在不增容的情况下，还能存储多少元素				
	VOID	clear();					//清空所有元素				
	BOOL	empty();					//判断Vector是否为空 返回true时为空				
	VOID	erase(DWORD dwIndex);					//删除指定元素				
	DWORD	size();					//返回Vector元素数量的大小				

private:
	BOOL expand();
private:
	DWORD m_dwIndex;//下一个可用索引
	DWORD m_dwIncrement;//每次增容的大小
	DWORD m_dwLen;//当前容器的大小
	DWORD m_dwInitSize;//默认初始化大小
	T_ELE* m_pVector;//容器的指针
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



