// Helloworld.cpp : Defines the entry point for the console application.
// F7���룬F5ִ�У�F9��ϵ㣬shift+F5��ֹ����ִ��,F10 ������F11����

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

