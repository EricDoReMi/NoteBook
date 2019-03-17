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
		//��ʼ��Node�ڵ�
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
		void InOrderTraverse(TreeNode<T>* pNode);//�������
		void PreOrderTraverse(TreeNode<T>* pNode);//ǰ�����
		void PostOrderTraverse(TreeNode<T>* pNode);//�������
		TreeNode<T>* GetRoot();//���ظ��ڵ�
		int GetDepth(TreeNode<T>* pNode);//����ĳ���ڵ�ĸ߶�/���
private:
		void init();
		void clearTree(TreeNode<T>* pNode);
private:
		TreeNode<T>* m_pRoot;//�����ָ��
		int m_size;//����Ԫ���ܸ���
};

template<class T>
MyBTree<T>::MyBTree(){
	init();
}

template<class T>
MyBTree<T>::~MyBTree(){
	//�ͷ����нڵ�ռ�
	clearTree(m_pRoot);

	
}

template<class T>
void MyBTree<T>::init(){

	Monster m1(1,1,"ciwei");
	Monster m2(2,2,"Ұ��");
	Monster m3(3,3,"С����");
	Monster m4(4,4,"С��");
	Monster m5(5,5,"���");
	Monster m6(6,6,"Ƥ����");
	Monster m7(7,7,"�����");

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

//����ĳ���ڵ�ĸ߶�/���
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

//�������
template<class T>
void MyBTree<T>::InOrderTraverse(TreeNode<T>* pNode){
	if(pNode){
		InOrderTraverse(pNode->pLeft);
		printf("%d,%s\n",pNode->element.ID,pNode->element.Name);
		
		InOrderTraverse(pNode->pRight);
	}
}

//ǰ�����
template<class T>
void MyBTree<T>::PreOrderTraverse(TreeNode<T>* pNode){
	if(pNode){
		printf("%d,%s\n",pNode->element.ID,pNode->element.Name);
		PreOrderTraverse(pNode->pLeft);
		
		PreOrderTraverse(pNode->pRight);
	}
}

//�������
template<class T>
void MyBTree<T>::PostOrderTraverse(TreeNode<T>* pNode){
	if(pNode){
		PreOrderTraverse(pNode->pLeft);
		PreOrderTraverse(pNode->pRight);
		printf("%d,%s\n",pNode->element.ID,pNode->element.Name);

		
	}
}

//���ظ��ڵ�
template<class T>
TreeNode<T>* MyBTree<T>::GetRoot(){
	return m_pRoot;
}
#endif
