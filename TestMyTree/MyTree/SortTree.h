#ifndef __SORTTREE_H__
#define __SORTTREE_H__
#include <windows.h>
#include "SortTree.h"

class Monster{
public:
	int ID;
	int Level;
	char Name[20];
public:
	Monster(){}
	Monster(int ID,int Level,char* pName){
		this->ID=ID;
		this->Level=Level;
		memcpy(this->Name,pName,strlen(pName)+1);
	}
};

template<class T>
class TreeNode{
public:
	T element;
	TreeNode<T>* pLeft;
	TreeNode<T>* pRight;

	TreeNode(T& ele){
		//初始化Node节点
		memset(&element,0,sizeof(TreeNode));
		memcpy(&element,&ele,sizeof(TreeNode));
		pLeft=NULL;
		pRight=NULL;
	}

};

template<class T>
class MyBTree{

public:
		MyBTree();
		~MyBTree();
public:
		void InOrderTraverse(TreeNode<T>* pNode);//中序遍历
		void PreOrderTraverse(TreeNode<T>* pNode);//前序遍历
		void PostOrderTraverse(TreeNode<T>* pNode);//后序遍历
		TreeNode<T>* GetRoot();//返回根节点
		int GetDepth(TreeNode<T>* pNode);//返回某个节点的高度/深度
private:
		void init();
		void clearTree(TreeNode<T>* pNode);
private:
		TreeNode<T>* m_pRoot;//根结点指针
		int m_size;//树中元素总个数
};

template<class T>
MyBTree<T>::MyBTree(){
	init();
}

template<class T>
MyBTree<T>::~MyBTree(){
	//释放所有节点空间
	clearTree(m_pRoot);

	
}

template<class T>
void MyBTree<T>::init(){

	Monster m1(1,1,"ciwei");
	Monster m2(2,2,"野狼");
	Monster m3(3,3,"小白兔");
	Monster m4(4,4,"小新");
	Monster m5(5,5,"伍佰");
	Monster m6(6,6,"皮卡丘");
	Monster m7(7,7,"张天空");

	TreeNode<Monster>* pTreeNode1=new TreeNode<Monster>(m1);
	TreeNode<Monster>* pTreeNode2=new TreeNode<Monster>(m2);
	TreeNode<Monster>* pTreeNode3=new TreeNode<Monster>(m3);
	TreeNode<Monster>* pTreeNode4=new TreeNode<Monster>(m4);
	TreeNode<Monster>* pTreeNode5=new TreeNode<Monster>(m5);
	TreeNode<Monster>* pTreeNode6=new TreeNode<Monster>(m6);
	TreeNode<Monster>* pTreeNode7=new TreeNode<Monster>(m7);
	
	m_pRoot=pTreeNode5;
	m_size=7;
	pTreeNode5->pLeft=pTreeNode4;
	pTreeNode5->pRight=pTreeNode6;

	pTreeNode4->pLeft=pTreeNode1;
	pTreeNode1->pRight=pTreeNode2;

	pTreeNode6->pLeft=pTreeNode3;
	pTreeNode3->pRight=pTreeNode7;
	
}

template<class T>
void MyBTree<T>::clearTree(TreeNode<T>* pNode){
	if(pNode){
		clearTree(pNode->pLeft);
		clearTree(pNode->pRight);
		delete pNode;
		pNode=NULL;
	}
}

//返回某个节点的高度/深度
template<class T>
int MyBTree<T>::GetDepth(TreeNode<T>* pNode){
	if(pNode==NULL)
	{
		return 0;
	}

	int m=GetDepth(pNode->pLeft);
	int n=GetDepth(pNode->pRight);

	return m>n?(m+1):(n+1);
}

//中序遍历
template<class T>
void MyBTree<T>::InOrderTraverse(TreeNode<T>* pNode){
	if(pNode){
		InOrderTraverse(pNode->pLeft);
		printf("%d,%s\n",pNode->element.ID,pNode->element.Name);
		
		InOrderTraverse(pNode->pRight);
	}
}

//前序遍历
template<class T>
void MyBTree<T>::PreOrderTraverse(TreeNode<T>* pNode){
	if(pNode){
		printf("%d,%s\n",pNode->element.ID,pNode->element.Name);
		PreOrderTraverse(pNode->pLeft);
		
		PreOrderTraverse(pNode->pRight);
	}
}

//后序遍历
template<class T>
void MyBTree<T>::PostOrderTraverse(TreeNode<T>* pNode){
	if(pNode){
		PreOrderTraverse(pNode->pLeft);
		PreOrderTraverse(pNode->pRight);
		printf("%d,%s\n",pNode->element.ID,pNode->element.Name);

		
	}
}

//返回根节点
template<class T>
TreeNode<T>* MyBTree<T>::GetRoot(){
	return m_pRoot;
}
#endif
