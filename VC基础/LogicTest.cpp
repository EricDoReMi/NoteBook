// �߼���λ���������
// F7���룬F5ִ�У�F9��ϵ㣬shift+F5��ֹ����ִ��,F10 ������F11����

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

/*1������һ��unsiged char ���ͣ�ͨ������Ϊ��3��5��7λ��ֵ,��ֵʱ����
Ӱ�쵽����λԭ����ֵ.*/

void logicFun2(unsigned char a){
	printf("%d\n",a | 0x00000100);//3
	printf("%d\n",a | 0x00010000);//5
	printf("%d\n",a | 0x01000000);//7
}

//�ж�ĳ��λ��ֵ�Ƿ�Ϊ1.
bool logicFun3(unsigned char a,int n){
	
	
	return (a>>(n-1)) & 0x00000001;
}

//��ȡ��7��6��5λ��ֵ����ʮ������ʾ(unsigned).
void logicFun5(unsigned char a){
	unsigned char tmp=((a>>4) & 0x7);
	printf("%d\n",tmp);
}

/*int main(int argc, char* argv[])
{
	logicFun5(182);

	return 0;
}*/

