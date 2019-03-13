#include "myVectorHead.h"
#include <stdio.h>

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
	for(i=1;i<=pMyVector->size();i++){
		int j=0;
		pMyVector->at(i-1,j);
		printf("%d\n",j);
	}

	printf("还可以装入:%d\n",pMyVector->capacity());

}


int main(){
	testVector();
	return 0;
}