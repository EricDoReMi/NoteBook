// 分析结构体的分配空间规律
// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"

struct S1
{
	char c;
	double i;
};

struct S5
{
	int c1;
	char c2[10];
};

struct S3
{
	char c1;
	S1 s;
	char c2;
	char c3;
};

struct S2
{
	char c1;
	S1 s;
	char c2;
	double c3;
};



/*int main(int argc, char* argv[])
{	
	
    S1 s1;
	S5 s5;
	S3 s3;
	S2 s2;
	printf("%d %d %d %d\n",sizeof(S1),sizeof(S5),sizeof(S3),sizeof(S2));
	
	return 0;
}*/

