#include <stdio.h>
#include <windows.h>
#include "myErrorHead.h"

#include "myVectorHead.h"

#include "myListHead.h"

#include "mySeachTree.h"


struct Monster{
	int id;
	char* name;
	Monster(){
	
	}
	Monster(int id,char*name){
		this->id=id;
		this->name=name;
	}
	
	void printData(){
		printf("%d,%s\n",id,name);
	}
	
	bool operator>(Monster& m){
		if(this->id>m.id){
			return true;
		}else{
			return false;
		}
	
	}

	bool operator<(Monster& m){
		if(this->id>m.id){
			return false;
		}else{
			return true;
		}
	}

	bool operator==(Monster& m){
		if(this->id==m.id){
			return true;
		}else{
			return false;
		}
	}

};

void testMySearchTree(){
	MySortTree<Monster>* pMySortTree=new MySortTree<Monster>();
	Monster* m1=new Monster(5,"xiaobai");
	Monster* m2=new Monster(2,"xiaoxin");
	Monster* m3=new Monster(3,"xiaotu");
	Monster* m4=new Monster(9,"xiaotu");
	Monster* m5=new Monster(6,"xiaotu");
	pMySortTree->Insert(*m1);
	pMySortTree->Insert(*m2);
	pMySortTree->Insert(*m3);
	pMySortTree->Insert(*m4);
	pMySortTree->Insert(*m5);
	pMySortTree->InOrderTraverse();
	printf("------------------------\n");
	pMySortTree->Delete(*m3);
	pMySortTree->InOrderTraverse();
}

void testVector(){


Vector<int> * pMyVector=new Vector<int>(6);
	
	int i=0;
	for(i=1;i<7;i++){
		pMyVector->push_back(i);
	}

//	i=80;

	int m=90;
	
	pMyVector->insertInto(2,m);

	int n=0;
	pMyVector->erase(2,n);
	printf("%d\n",n);
	pMyVector->pop_back(n);
	pMyVector->pop_back(n);

	//pMyVector->clear();

	pMyVector->push_back(m);


//TestPrint
	for(i=1;(DWORD)i<=(pMyVector->size());i++){
		int j=0;
		pMyVector->at(i-1,j);
		printf("%d\n",j);
	}

	printf("还可以装入:%d\n",pMyVector->capacity());

}

void testLinkedList()
{
	LinkedList<int> * pLinkedList=new LinkedList<int>();
	int i=0;
	for(i=0;i<9;i++){
		pLinkedList->Insert(i);
	}

	int p=99;
	pLinkedList->Insert(0,p);
	p=98;
	pLinkedList->Insert(2,p);
	p=100;
	pLinkedList->Insert(10,p);
	
	pLinkedList->Delete(0);

	pLinkedList->Delete(2);

	pLinkedList->Delete(pLinkedList->GetSize()-1);

//TestPrint
	for(i=0;i<pLinkedList->GetSize();i++){
		int j=0;
		pLinkedList->GetElement(i,j);
		printf("%d\n",j);
	}
	p=98;
	p=pLinkedList->GetElementIndex(p);
	printf("-----%d\n",p);

}


int main(){
	//testVector();
	//testLinkedList();
	testMySearchTree();
	return 0;
}