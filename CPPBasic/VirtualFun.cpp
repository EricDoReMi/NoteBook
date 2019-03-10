/*Ðéº¯ÊýÌ½Ë÷*/							

#include <stdio.h>
#include <windows.h>

class Base5{
	int x;
	int y;
public:
	Base5(){
		this->x=1;
		this->x=2;
	}
	void Fun_1(){
		printf("fun01\n");
	}

	virtual void Fun_2(){
		printf("fun02\n");
	}
	virtual void Fun_3(){
		printf("fun03\n");
	}
};


/*int main(int argc,char* argv[]){
	
	Base5 b;
	Base5* pB=&b;
	typedef void (*PVirtualFun)(void);
	PVirtualFun pVirtualFun;
	
	int i=0;
	for(i=0;i<2;i++){
		pVirtualFun=(PVirtualFun)*((int*)(*(int*)pB)+i);
		pVirtualFun();

	}

	return 0;
}*/