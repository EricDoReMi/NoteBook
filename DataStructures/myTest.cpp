#include <stdio.h>
#include <windows.h>
#include "myErrorHead.h"

#include "myVectorHead.h"

#include "myListHead.h"

#include "mySeachTree.h"

struct My{
	int x[10];
	int y[10];
	int z[10];
	My(int i){
		memcpy(this->x,&i,10);
		memcpy(this->y,&i,10);
		memcpy(this->z,&i,10);
	}
};

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
	testLinkedList();

	return 0;
}