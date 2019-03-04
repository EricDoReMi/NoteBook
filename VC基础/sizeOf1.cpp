// sizeof关键字的使用
// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"

struct st1
{
	char a;
	short b;
	int c;

};

struct st2
{
	char a;
	int c;
	short b;
};

/*int main(int argc, char* argv[])
{
	printf("%d\n",sizeof(char));
	printf("%d\n",sizeof(short));
	printf("%d\n",sizeof(int));
	printf("%d\n",sizeof(long int));
	printf("%d\n",sizeof(__int64));
	printf("%d\n",sizeof(float));
	printf("%d\n",sizeof(double));

	int x=10;

	//printf("%d\n",sizeof(x));

	char arr1[10]={0};
	short arr2[10]={0};
	int arr3[10]={0};

	printf("%d %d %d\n",sizeof(arr1),sizeof(arr2),sizeof(arr3));

    printf("%d %d %d\n",sizeof(arr1[0]),sizeof(arr2[0]),sizeof(arr3[0]));

	st1 s1;
	st2 s2;
	printf("%d %d\n",sizeof(s1),sizeof(s2));//8 12
	printf("%d %d\n",sizeof(st1),sizeof(st2));

	return 0;
}*/

