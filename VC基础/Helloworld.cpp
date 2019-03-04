// Helloworld.cpp : Defines the entry point for the console application.
// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"

int add2(int x,int y){
	
	return x+y;
}

int add3(int x,int y,int z){
	int t=add2(x,y);
	int r=add2(t,z);
	return r;
}

int add5(int x,int y,int z,int a,int b){
	return add2(x,y)+add3(z,a,b);
}




/*int main(int argc, char* argv[])
{
	add5(1,2,3,4,5);


	return 0;
}*/

