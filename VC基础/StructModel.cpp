// �ṹ���ʹ��
// F7���룬F5ִ�У�F9��ϵ㣬shift+F5��ֹ����ִ��,F10 ������F11����

#include "stdafx.h"

struct sDemo{
	char* name;
};

struct stDemo{
	int a;
	char b;
    short c;
	int arr[10];
	sDemo sd;

};

void fStruct(){
	sDemo sd;
	sd.name="abc";
	printf("%s",sd.name);

}

void ffun2(){
	stDemo std;
	std.a=10;
	std.b='a';
	std.c=18;
	sDemo s;
	s.name="HelloWorld";

	int i=0;
	for(i=0;i<10;i++){
		std.arr[i]=i;
	}
	for(i=0;i<10;i++){
		printf("%d\n",std.arr[i]);
	}
	std.sd=s;
	printf("%s",std.sd.name);
}

void ffun3(stDemo std){
	
}

stDemo ffun5(){
	stDemo std;
	std.a=10;
	std.b='a';
	std.c=18;
	sDemo s;
	s.name="HelloWorld";

	int i=0;
	for(i=0;i<10;i++){
		std.arr[i]=i;
	}
	std.sd=s;
	return std;
}

/*int main(int argc, char* argv[])
{	
	stDemo std;
    
	std=ffun5();
	return 0;
}*/

