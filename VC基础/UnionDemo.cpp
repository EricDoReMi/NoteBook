// ������demo
// F7���룬F5ִ�У�F9��ϵ㣬shift+F5��ֹ����ִ��,F10 ������F11����

#include "stdafx.h"
#include<stdio.h>

union TestUnion{
	char x;
	int y;
};

union{
	char x;
	int y;
}T;

struct{
	char x;
	int y;
}St1;

/*int main(int argc, char* argv[])
{
	printf("%d\n",sizeof(TestUnion));//4
	TestUnion t;
	t.y=0x12345678;
	printf("%X,%X\n",t.y,t.x);//12345678,78
	T.y=0x12345678;
	printf("%X\n",T.y);
	St1.x='a';
	St1.y=0x12345678;
	printf("%X\n",St1.y);
	return 0;
}*/

