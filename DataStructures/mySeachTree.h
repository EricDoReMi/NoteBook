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

	//重载比较运算符
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
	bool IsEmpty();//判断树是否为空
	DWORD Insert(T& element);//新增一个节点
	void Delete(T& element);//删除一个节点
	TreeNode<T>* Search(T& element);//查找对应节点
	void InOrderTraverse(TreeNode<T>* pNode);//中序遍历了
	void PreOrderTraverse(TreeNode<T>* pNode);//前序遍历了
	void PostOrderTraverse(TreeNode<T>* pNode);//后序遍历了
private:
	TreeNode<T>* GetMaxNode(TreeNode<T>* pNode);//获取以pNode为根的最大节点
	TreeNode<T>* GetMinNode(TreeNode<T>* pNode);//获取以pNode为根的最小节点
	TreeNode<T>* SearchNode(TreeNode<T>* pNode,T& element);//搜索对应节点
	DWORD InsertNode(TreeNode<T>* pNode,T& element);//插入对应节点
	void DeleteNode();
private:
	TreeNode<T>* pRoot;//根节点
	int treeSize;//树的大小了
};

#endif
