// typedef 关键字的使用
// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

typedef int vector[10];

typedef int name[5][5];

typedef struct student
{
	int x;
	int y;
}stu;


/*int main(int argc, char* argv[])
{
	BYTE b=15;

	vector v;
	v[0]=1;

	name arrName;
	arrName[0][0]=0;

	stu s;
	s.x=0;
	s.y=0;

	return 0;
}*/

