// 数据类型的强制转换
// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"

void function1(){
	char ci=0xff;
	short si=ci;
	int ii=ci;
	printf("%d,%d,%d\n",ci,si,ii);
}

void function2(){
	unsigned char ci=0xff;
	unsigned short si=ci;
	unsigned  int ii=ci;
    printf("%d,%d,%d\n",ci,si,ii);
}

void function3(){
	int ii=0x12345678;
	short si=ii;
	char ci=ii;
    printf("%d,%d,%d\n",ci,si,ii);
}

/*int main(int argc, char* argv[])
{
	function1();
    function2();
	function3();
	int x=0;
	if(x=2){
		printf("Hello\n");
	}
	return 0;
}*/

