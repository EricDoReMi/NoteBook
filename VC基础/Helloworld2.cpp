// F7���룬F5ִ�У�F9��ϵ㣬shift+F5��ֹ����ִ��,F10 ������F11����

#include "stdafx.h"


void helloWorld(){
	printf("HelloWorld\n");
	getchar();
}

// ���ڻ����������Helloworld
void f(){
	int arr[5]={1,2,3,4,5};
	arr[6]=(int)helloWorld;//mov dword ptr ds:[ebp+4],helloWorld��ַ
}

//����ֹͣ��Helloworld
void f1(){
	int i;
	int arr[5]={0};
	for(i=0;i<=5;i++){
		arr[i]=0;//��i=5ʱ��arr[i]�����޸���i��ֵΪ0
		printf("helloWorld\n");
	}
}

/*int main(int argc, char* argv[])
{
    //f();

    f1();

	return 0;
}*/
