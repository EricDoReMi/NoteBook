// 逻辑与位运算符测试
// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"

void logicFun1(){
	char a=2;
	unsigned char b=3;
	printf("%d\n",a&b);
	printf("%d\n",a|b);
	printf("%d\n",~a);
	printf("%d\n",a^b);
	printf("%d\n",a<<2);
	printf("%d\n",a>>2);
}

/*1、定义一个unsiged char 类型，通过程序为第3、5、7位赋值,赋值时不能
影响到其它位原来的值.*/

void logicFun2(unsigned char a){
	printf("%d\n",a | 0x00000100);//3
	printf("%d\n",a | 0x00010000);//5
	printf("%d\n",a | 0x01000000);//7
}

//判断某个位的值是否为1.
bool logicFun3(unsigned char a,int n){
	
	
	return (a>>(n-1)) & 0x00000001;
}

//读取第7、6、5位的值，以十进制显示(unsigned).
void logicFun5(unsigned char a){
	unsigned char tmp=((a>>4) & 0x7);
	printf("%d\n",tmp);
}

/*int main(int argc, char* argv[])
{
	logicFun5(182);

	return 0;
}*/

