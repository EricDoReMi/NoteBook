// 联合体demo
// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

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

