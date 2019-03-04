// 结构体对齐
// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"

#pragma pack(4)
struct T{
	char c;
	double a;
	double b;
	
};
#pragma pack()

/*int main(int argc, char* argv[])
{	
	
    T t;
	printf("%d\n",sizeof(t));
	
	return 0;
}*/

