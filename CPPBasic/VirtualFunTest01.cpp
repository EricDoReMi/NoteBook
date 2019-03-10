/*Ðéº¯ÊýÌ½Ë÷*/							

#include <stdio.h>
#include <windows.h>

class Base10{

public:
	int x;
	int y;
	Base10(){
		x=1;
		y=2;
	}
	
	virtual void print(){
		printf("%d,%d,%d\n",x,y);
	}

};

class Base10Child1:public Base10{
public:
	int A;
	Base10Child1(){
		A=6;
	}
	virtual void print(){
		printf("%d,%d,%d\n",x,y,A);
	}
	
};

class Base10Child2:public Base10{
public:
	int B;
	Base10Child2(){
		B=7;
	}
	virtual void print(){
		printf("%d,%d,%d\n",x,y,B);
	}
	
};

class Base10Child3:public Base10{
public:
	int C;
	Base10Child3(){
		C=9;
	}
	virtual void print(){
		printf("%d,%d,%d\n",x,y,C);
	}
	
};



void myTest(){
	Base10Child1 b1;
	Base10Child2 b2;
	Base10Child3 b3;
	Base10* pBArr[]={&b1,&b2,&b3};
	int i=0;
	for(i=0;i<3;i++){
		pBArr[i]->print();
	}

}


/*int main(int argc,char* argv[]){
	myTest();
	return 0;
}*/