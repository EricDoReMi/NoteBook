/*Ðéº¯ÊýÌ½Ë÷*/							

#include <stdio.h>
#include <windows.h>

class Base6{

public:

	virtual void Fun_1(){
		printf("fun01\n");
	}

	virtual void Fun_2(){
		printf("fun02\n");
	}
	virtual void Fun_3(){
		printf("fun03\n");
	}
};

class Base6Child1:public Base6{
public:
	virtual void Fun_5(){
		printf("Child1---Fun_5\n");
	}
	virtual void Fun_6(){
		printf("Child2---Fun_6\n");
	}

};

class Base6Child2:public Base6{
public:
	virtual void Fun_1(){
		printf("Child2---Fun_1\n");
	}
	virtual void Fun_2(){
		printf("Child2---Fun_2\n");
	}

};


/*int main(int argc,char* argv[]){
	
	Base6 b;
	
	typedef void (*PVirtualFun)(void);
	PVirtualFun pVirtualFun;
	
	printf("Base6VirtualTableAdd:%x\n",*(int*)&b);
	int i=0;
	for(i=0;i<3;i++){
		pVirtualFun=(PVirtualFun)*((int*)(*(int*)&b)+i);
		pVirtualFun();
		printf("Base5Fun:%d,Add:%X\n",i+1,(int*)pVirtualFun);

	}

	Base6 b1;
	printf("Base6VirtualTableB1Add:%x\n",*(int*)&b1);
	for(i=0;i<3;i++){
		pVirtualFun=(PVirtualFun)*((int*)(*(int*)&b1)+i);
		pVirtualFun();
		printf("Base5Fun:%d,Add:%X\n",i+1,(int*)pVirtualFun);

	}


	Base6Child1 c1;
	printf("Base6Child1VirtualTableAdd:%x\n",*(int*)&c1);

	for(i=0;i<5;i++){
		pVirtualFun=(PVirtualFun)*((int*)(*(int*)&c1)+i);
		pVirtualFun();
		printf("Child1Fun:%d,Add:%X\n",i+1,(int*)pVirtualFun);
	}

	Base6Child2 c2;
	printf("Base6Child2VirtualTableAdd:%x\n",*(int*)&c2);

	for(i=0;i<3;i++){
		pVirtualFun=(PVirtualFun)*((int*)(*(int*)&c2)+i);
		pVirtualFun();
		printf("Child2Fun:%d,Add:%X\n",i+1,(int*)pVirtualFun);
	}

	return 0;
}*/