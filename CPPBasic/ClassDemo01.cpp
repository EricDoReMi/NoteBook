/*将定义与实现分离*/						
						

#include <stdio.h>
#include <windows.h>
#include "ClassDemo01.h"

void Test::Init(int x,int y,int z){
	this->x=x;
	this->y=y;
	this->z=z;
}

void Test::Function1(){
	printf("Total:%d\n",this->x+this->y+this->z);
}

/*int main(int argc,char* argv[]){
	Test t;
	t.Init(1,2,3);
	t.Function1();
	return 0;
}*/