// 循环语句的使用及反汇编
// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"


void myDoWhile(int x,int y){
	do{
		printf("wo!\n");
		x++;
	}while(x<y);

}

void myWhile(int x,int y){
	
	while(x<y){
		printf("hello world\n");
		x++;
	}

}

void myFor(int x,int y){
	int i=0;
	for(i=x;x<y;x++){
		printf("WoW\n");
		x++;
	}
}



/*int main(int argc, char* argv[])
{
	//myDoWhile(0,8);
	
	//myWhile(1,6);

	//myFor(2,2);
	//MessageBox(0,0,0,0);
	return 0;
}*/

