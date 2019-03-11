//结构体探索

#include <stdio.h>
#include <windows.h>

struct Cal
{
	int x;
	int y;

	int add(int x,int y){
		return this->x+this->y+x+y+y;
	}

	int sub(){
		return x-y;
	}

	int mul(){
		return x*y;
	}

	int div(){
		return x/y;
	}

	//返回this指针的地址
	int returnCalAddress(){
		return (DWORD)this;
	}
};



/*int main(int argc,char* argv[]){
	Cal pC;
	pC.x=9;
	pC.y=3;
	Cal pC2;
	pC2=pC;
	printf("%d\n",pC2.x);
	int z=pC.add(2,3);
	printf("%d\n",z);
	pC.div();
	pC.mul();
	pC.sub();

	printf("%X\n",pC.returnCalAddress());

	return 0;

}*/