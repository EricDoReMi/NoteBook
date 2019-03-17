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

	//重载比较运算符
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
	bool IsEmpty();//判断树是否为空
	DWORD Insert(T& element);//新增一个节点
	DWORD Delete(T& element);//删除一个节点
	TreeNode<T>* Search(T& element);//查找对应节点
	void InOrderTraverse();//中序遍历了
	void PreOrderTraverse();//前序遍历了
	void PostOrderTraverse();//后序遍历了
	void clearTree();//清空节点了
private:
	TreeNode<T>* GetMaxNode(TreeNode<T>* pNode);//获取以pNode为根的最大节点
	TreeNode<T>* GetMinNode(TreeNode<T>* pNode);//获取以pNode为根的最小节点
	TreeNode<T>* SearchNode(TreeNode<T>* pNode,T& element);//搜索对应节点
	DWORD InsertNode(TreeNode<T>* pNode,T& element);//插入对应节点
	DWORD InsertNode(TreeNode<T>** pNode,TreeNode<T>* pNodeInsert);//插入对应节点
	void InOrderTraverse(TreeNode<T>* pNode);//中序遍历了
	void PreOrderTraverse(TreeNode<T>* pNode);//前序遍历了
	void PostOrderTraverse(TreeNode<T>* pNode);//后序遍历了
	void clearTree(TreeNode<T>** pNode);//清空节点了
	DWORD DeleteNode(TreeNode<T>** pNode);
private:
	TreeNode<T>* pRoot;//根节点
	int treeSize;//树的大小了
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

//判断树是否为空
template<class T>
bool MySortTree<T>::IsEmpty(){
	if(pRoot && treeSize){
		return false;
	}
	return true;
}

//新增一个节点
template<class T>
DWORD MySortTree<T>::Insert(T& element){
	if(InsertNode(pRoot,element)){
		return TREESUCCESS;
	}

	return TREEERROR;
	
}

//插入对应节点
template<class T>
DWORD MySortTree<T>::InsertNode(TreeNode<T>* pNode,T& element){

	TreeNode<T>* pNewNode=new TreeNode<T>(element);
	
	

	//根节点的情况
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


//插入对应节点
template<class T>
DWORD MySortTree<T>::InsertNode(TreeNode<T>** pNode,TreeNode<T>* pNodeInsert){
	

	//根节点和叶子节点的情况
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

//中序遍历了
template<class T>
void MySortTree<T>::InOrderTraverse(){
	InOrderTraverse(pRoot);
}

//中序遍历了
template<class T>
void MySortTree<T>::InOrderTraverse(TreeNode<T>* pNode){
	if(pNode){
		InOrderTraverse(pNode->pLeft);
		pNode->pData->printData();
		InOrderTraverse(pNode->pRight);
	}
}

//前序遍历了
template<class T>
void MySortTree<T>::PreOrderTraverse(){
	PreOrderTraverse(pRoot);
}

//前序遍历了
template<class T>
void MySortTree<T>::PreOrderTraverse(TreeNode<T>* pNode){
	if(pNode){
		pNode->pData->printData();
		PreOrderTraverse(pNode->pLeft);
		PreOrderTraverse(pNode->pRight);
	}
}
//后序遍历了
template<class T>
void MySortTree<T>::PostOrderTraverse(){
	PostOrderTraverse(pRoot);
}

//后序遍历了
template<class T>
void MySortTree<T>::PostOrderTraverse(TreeNode<T>* pNode){
	if(pNode){
		PostOrderTraverse(pNode->pLeft);
		PostOrderTraverse(pNode->pRight);
		pNode->pData->printData();
		
	}
}

//清空节点了
template<class T>
void MySortTree<T>::clearTree(){
	clearTree(&pRoot);
	treeSize=0;
}

//清空节点了
template<class T>
void MySortTree<T>::clearTree(TreeNode<T>** pNode){
	if(pNode){
		clearTree(&((*pNode)->pLeft));
		clearTree(&((*pNode)->pRight));
		delete *pNode;
		*pNode=NULL;
		
	
	}
}

//查找对应节点
template<class T>
TreeNode<T>* MySortTree<T>::Search(T& element){
	return SearchNode(pRoot,element);
}


//搜索对应节点
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

//获取以pNode为根的最小节点
template<class T>
TreeNode<T>* MySortTree<T>::GetMinNode(TreeNode<T>* pNode){
	if(!pNode){
		return pNode->pFather;
	}
	
	return GetMinNode(pNode->pLeft);
}

//获取以pNode为根的最大节点
template<class T>
TreeNode<T>* MySortTree<T>::GetMaxNode(TreeNode<T>* pNode){
	if(!pNode){
		return pNode->pFather;
	}
	
	return GetMaxNode(pNode->pRight);
}

//删除一个节点
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

//删除一个节点
template<class T>
DWORD MySortTree<T>::DeleteNode(TreeNode<T>** pNode1){
	TreeNode<T>* pNode=*pNode1;
	//叶子节点的情况
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

	//只有一个子树的情况
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

	//左右子树都有的情况
	if(pNode->pLeft && pNode->pRight){
		//将左子树插入右子树
		InsertNode(&(pNode->pRight),pNode->pLeft);
		

		
		pNode->pFather->pRight=pNode->pRight;

		delete *pNode1;
		*pNode1=NULL;
		
		return TREESUCCESS;
	}


}
#endif


