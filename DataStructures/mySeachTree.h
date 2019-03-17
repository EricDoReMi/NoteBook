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
		pData=NULL;
	}

	//���رȽ������
	bool operator==(TreeNode<T>& pNode){
		
		return *(pNode.pData)>(*pData)?true:false;
		
	}

	bool operator>(TreeNode<T>& pNode){
		
		return *pData>(*(pNode.pData))?true:false;
	}

	bool operator<(TreeNode<T>& pNode){
		return *pData<(*(pNode.pData))?true:false;
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
	DWORD Delete(T& element);//ɾ��һ���ڵ�
	TreeNode<T>* Search(T& element);//���Ҷ�Ӧ�ڵ�
	void InOrderTraverse();//���������
	void PreOrderTraverse();//ǰ�������
	void PostOrderTraverse();//���������
	void clearTree();//��սڵ���
private:
	TreeNode<T>* GetMaxNode(TreeNode<T>* pNode);//��ȡ��pNodeΪ�������ڵ�
	TreeNode<T>* GetMinNode(TreeNode<T>* pNode);//��ȡ��pNodeΪ������С�ڵ�
	TreeNode<T>* SearchNode(TreeNode<T>* pNode,T& element);//������Ӧ�ڵ�
	DWORD InsertNode(TreeNode<T>* pNode,T& element);//�����Ӧ�ڵ�
	DWORD InsertNode(TreeNode<T>** pNode,TreeNode<T>* pNodeInsert);//�����Ӧ�ڵ�
	void InOrderTraverse(TreeNode<T>* pNode);//���������
	void PreOrderTraverse(TreeNode<T>* pNode);//ǰ�������
	void PostOrderTraverse(TreeNode<T>* pNode);//���������
	void clearTree(TreeNode<T>** pNode);//��սڵ���
	DWORD DeleteNode(TreeNode<T>** pNode);
private:
	TreeNode<T>* pRoot;//���ڵ�
	int treeSize;//���Ĵ�С��
};

template<class T>
MySortTree<T>::MySortTree(){
	pRoot=NULL;
	treeSize=0;
}

template<class T>
MySortTree<T>::~MySortTree(){
	clearTree();
}

//�ж����Ƿ�Ϊ��
template<class T>
bool MySortTree<T>::IsEmpty(){
	if(pRoot && treeSize){
		return false;
	}
	return true;
}

//����һ���ڵ�
template<class T>
DWORD MySortTree<T>::Insert(T& element){
	if(InsertNode(pRoot,element)){
		return TREESUCCESS;
	}

	return TREEERROR;
	
}

//�����Ӧ�ڵ�
template<class T>
DWORD MySortTree<T>::InsertNode(TreeNode<T>* pNode,T& element){

	TreeNode<T>* pNewNode=new TreeNode<T>(element);
	
	

	//���ڵ�����
	if(!pNode && treeSize==0){
		pRoot=pNewNode;
		treeSize++;
		return TREESUCCESS;

	}
	
	if(*(pNode->pData)==element){
		return TREEERROR;
	}

	if(*(pNode->pData)>element && pNode->pLeft){
		InsertNode(pNode->pLeft,element);
		
	}else if(*(pNode->pData)<element && pNode->pRight){
		InsertNode(pNode->pRight,element);

	}else if(*(pNode->pData)>element && (!(pNode->pLeft))){
		pNode->pLeft=pNewNode;
		pNewNode->pFather=pNode;
		treeSize++;

	}else if(*(pNode->pData)<element && (!(pNode->pRight))){
		pNode->pRight=pNewNode;
		pNewNode->pFather=pNode;
		treeSize++;
	}
	
	return TREESUCCESS;
}


//�����Ӧ�ڵ�
template<class T>
DWORD MySortTree<T>::InsertNode(TreeNode<T>** pNode,TreeNode<T>* pNodeInsert){
	

	//���ڵ��Ҷ�ӽڵ�����
	if(!(*pNode)){
		*pNode=pNodeInsert;
		treeSize++;
		return TREESUCCESS;

	}
	
	if(*((*pNode)->pData)==*(pNodeInsert->pData)){
		return TREEERROR;
	}

	if(*((*pNode)->pData)>*(pNodeInsert->pData)){
		InsertNode(&((*pNode)->pLeft),pNodeInsert);
		
	}else if(*((*pNode)->pData)<*(pNodeInsert->pData)){
		InsertNode(&((*pNode)->pRight),pNodeInsert);

	}
	return TREESUCCESS;
}

//���������
template<class T>
void MySortTree<T>::InOrderTraverse(){
	InOrderTraverse(pRoot);
}

//���������
template<class T>
void MySortTree<T>::InOrderTraverse(TreeNode<T>* pNode){
	if(pNode){
		InOrderTraverse(pNode->pLeft);
		pNode->pData->printData();
		InOrderTraverse(pNode->pRight);
	}
}

//ǰ�������
template<class T>
void MySortTree<T>::PreOrderTraverse(){
	PreOrderTraverse(pRoot);
}

//ǰ�������
template<class T>
void MySortTree<T>::PreOrderTraverse(TreeNode<T>* pNode){
	if(pNode){
		pNode->pData->printData();
		PreOrderTraverse(pNode->pLeft);
		PreOrderTraverse(pNode->pRight);
	}
}
//���������
template<class T>
void MySortTree<T>::PostOrderTraverse(){
	PostOrderTraverse(pRoot);
}

//���������
template<class T>
void MySortTree<T>::PostOrderTraverse(TreeNode<T>* pNode){
	if(pNode){
		PostOrderTraverse(pNode->pLeft);
		PostOrderTraverse(pNode->pRight);
		pNode->pData->printData();
		
	}
}

//��սڵ���
template<class T>
void MySortTree<T>::clearTree(){
	clearTree(&pRoot);
	treeSize=0;
}

//��սڵ���
template<class T>
void MySortTree<T>::clearTree(TreeNode<T>** pNode){
	if(pNode){
		clearTree(&((*pNode)->pLeft));
		clearTree(&((*pNode)->pRight));
		delete *pNode;
		*pNode=NULL;
		
	
	}
}

//���Ҷ�Ӧ�ڵ�
template<class T>
TreeNode<T>* MySortTree<T>::Search(T& element){
	return SearchNode(pRoot,element);
}


//������Ӧ�ڵ�
template<class T>
TreeNode<T>* MySortTree<T>::SearchNode(TreeNode<T>* pNode,T& element){
	if(!pNode){
		return NULL;
	}

	if(*(pNode->pData)==element){
		return pNode;
	}

	if(*(pNode->pData)>element){
		return SearchNode(pNode->pLeft,element);
	}

	if(*(pNode->pData)<element){
		return SearchNode(pNode->pRight,element);
	}
	
}

//��ȡ��pNodeΪ������С�ڵ�
template<class T>
TreeNode<T>* MySortTree<T>::GetMinNode(TreeNode<T>* pNode){
	if(!pNode){
		return pNode->pFather;
	}
	
	return GetMinNode(pNode->pLeft);
}

//��ȡ��pNodeΪ�������ڵ�
template<class T>
TreeNode<T>* MySortTree<T>::GetMaxNode(TreeNode<T>* pNode){
	if(!pNode){
		return pNode->pFather;
	}
	
	return GetMaxNode(pNode->pRight);
}

//ɾ��һ���ڵ�
template<class T>
DWORD MySortTree<T>::Delete(T& element){
	TreeNode<T>* pNode=Search(element);
	if(!pNode){
		return TREEERROR;	
	}
	if(DeleteNode(&pNode)){
		return TREESUCCESS;
	}

	return TREEERROR;
}

//ɾ��һ���ڵ�
template<class T>
DWORD MySortTree<T>::DeleteNode(TreeNode<T>** pNode1){
	TreeNode<T>* pNode=*pNode1;
	//Ҷ�ӽڵ�����
	if((!(pNode->pLeft)) && (!(pNode->pRight))){
		if(*(pNode->pFather)<(*pNode)){
			pNode->pFather->pRight=NULL;
		}else if(*(pNode->pFather)>*pNode){
			pNode->pFather->pLeft=NULL;
		}

		delete *pNode1;
		(*pNode1)=NULL;
		treeSize--;
		return TREESUCCESS;
	}

	//ֻ��һ�����������
	if(pNode->pLeft && (!(pNode->pRight))){
		if(*(pNode->pFather)<(*pNode)){
			pNode->pFather->pRight=pNode->pLeft;
		}else if(*(pNode->pFather)>(*pNode)){
			pNode->pFather->pLeft=pNode->pLeft;
		}
		pNode->pLeft->pFather=pNode->pFather;
		delete *pNode1;
		*pNode1=NULL;
		treeSize--;
		return TREESUCCESS;
	}

	
	if(pNode->pRight && (!(pNode->pLeft))){
		if(*(pNode->pFather)<(*pNode)){
			pNode->pFather->pRight=pNode->pRight;
		}else if(*(pNode->pFather)>(*pNode)){
			pNode->pFather->pLeft=pNode->pRight;
		}

		pNode->pRight->pFather=pNode->pFather;

		delete *pNode1;
		treeSize--;
		*pNode1=NULL;
		return TREESUCCESS;
	}

	//�����������е����
	if(pNode->pLeft && pNode->pRight){
		//������������������
		InsertNode(&(pNode->pRight),pNode->pLeft);
		

		
		pNode->pFather->pRight=pNode->pRight;

		delete *pNode1;
		*pNode1=NULL;
		
		return TREESUCCESS;
	}


}
#endif


