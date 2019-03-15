#ifndef __MYSEARCHTREE_H__
#define __MYSEARCHTREE_H__

#include "mySeachTree.h"


template<class T>
class TreeNode{
public:
	 T* pData;
	TreeNode<T>* pLeft;
	TreeNode<T>* pRight;
	TreeNode<T>* pFather;
public:
	TreeNode(T& t){
		pData=new T();
		memset(pData,0,sizeof(T));
		memcpy(pData,&t,sizeof(T));
		pLeft=pRight=pFather=NULL;
	}

	~TreeNode(){
		delete pData;
	}

	//���رȽ������
	bool operator==(TreeNode<T>* pNode){
		
		return *(pNode->pData)>(*pData)?true:false;
		
	}

	bool operator>(TreeNode<T>* pNode){
		
		return *pData>(*(pNode->pData))?true:false;
	}

	bool operator<(TreeNode<T>* pNode){
		return *pData<(*(pNode->pData))?true:false;
	}


};

template<class T>
class MySortTree{
public:
	MySortTree();
	~MySortTree();
public:
	bool IsEmpty();//�ж����Ƿ�Ϊ��
	DWORD Insert(T& element);//����һ���ڵ�
	void Delete(T& element);//ɾ��һ���ڵ�
	TreeNode<T>* Search(T& element);//���Ҷ�Ӧ�ڵ�
	void InOrderTraverse(TreeNode<T>* pNode);//���������
	void PreOrderTraverse(TreeNode<T>* pNode);//ǰ�������
	void PostOrderTraverse(TreeNode<T>* pNode);//���������
private:
	TreeNode<T>* GetMaxNode(TreeNode<T>* pNode);//��ȡ��pNodeΪ�������ڵ�
	TreeNode<T>* GetMinNode(TreeNode<T>* pNode);//��ȡ��pNodeΪ������С�ڵ�
	TreeNode<T>* SearchNode(TreeNode<T>* pNode,T& element);//������Ӧ�ڵ�
	DWORD InsertNode(TreeNode<T>* pNode,T& element);//�����Ӧ�ڵ�
	void DeleteNode();
private:
	TreeNode<T>* pRoot;//���ڵ�
	int treeSize;//���Ĵ�С��
};

#endif
