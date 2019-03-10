/*Ðéº¯ÊýÌ½Ë÷*/							

#include <stdio.h>
#include <windows.h>

class Base9{

public:
	int x;
	Base9(){
		x=100;
	}
	void Fun_1(){
		printf("fun01\n");
	}

	virtual void Fun_2(){
		printf("fun02\n");
	}

};

class Base9Child1:public Base9{
public:
	int x;
	Base9Child1(){
		x=200;
	}
	void Fun_1(){
		printf("Child1---Fun_5\n");
	}
	virtual void Fun_2(){
		printf("Child1---Fun_6\n");
	}

};

void myTest(Base9* pB){
	printf("%d\n",pB->x);

	pB->Fun_1();
	pB->Fun_2();

}


/*int main(int argc,char* argv[]){
	Base9 b1;
	myTest(&b1);
	Base9Child1 bc1;
	myTest(&bc1);
	return 0;
}*/