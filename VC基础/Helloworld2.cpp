// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"


void helloWorld(){
	printf("HelloWorld\n");
	getchar();
}

// 基于缓冲区溢出的Helloworld
void f(){
	int arr[5]={1,2,3,4,5};
	arr[6]=(int)helloWorld;//mov dword ptr ds:[ebp+4],helloWorld地址
}

//永不停止的Helloworld
void f1(){
	int i;
	int arr[5]={0};
	for(i=0;i<=5;i++){
		arr[i]=0;//当i=5时，arr[i]正好修改了i的值为0
		printf("helloWorld\n");
	}
}

/*int main(int argc, char* argv[])
{
    //f();

    f1();

	return 0;
}*/
