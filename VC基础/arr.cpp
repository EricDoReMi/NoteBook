// �����ʹ��
// F7���룬F5ִ�У�F9��ϵ㣬shift+F5��ֹ����ִ��,F10 ������F11����

#include "stdafx.h"


int arr[10] = {1,3,7,11,5,9};

void fun(){
	printf("%d\n",arr[0]);
	printf("%d\n",arr[1]);
	printf("%d\n",arr[2]);
	printf("%d\n",arr[3]);
	printf("%d\n",arr[4]);
	printf("%d\n",arr[5]);

	int x = arr[5];
	printf("%d\n",x);
}

void fun2(){
	arr[0]=888;
	arr[1]=99;
	printf("%d\n",arr[0]);
	printf("%d\n",arr[1]);
	printf("%d\n",arr[2]);
	printf("%d\n",arr[3]);
	printf("%d\n",arr[4]);
	printf("%d\n",arr[5]);

	int x = arr[5];
	printf("%d\n",x);
}


/*int main(int argc, char* argv[])
{
	fun2();

	return 0;
}*/

