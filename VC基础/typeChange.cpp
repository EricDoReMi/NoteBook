// �������͵�ǿ��ת��
// F7���룬F5ִ�У�F9��ϵ㣬shift+F5��ֹ����ִ��,F10 ������F11����

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

