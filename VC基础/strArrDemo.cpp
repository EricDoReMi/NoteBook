// ָ��Ļ����÷���


#include "stdafx.h"
//��һ�������д洢�˽�ɫ��Ѫֵ��Ϣ������Ѫֵ������Ϊint���ͣ�ֵΪ100(10����)
//���г����п��ܵ�ֵ�Լ���ֵ��Ӧ�ĵ�ַ.
//

void arrFuntion1()
{
	char arr[6] = {'A','B','C','D','E','\0'};

	char names[] = "ABCDEF";

	printf("%s\n",arr);

	printf("%s\n",names);
}

void arrFunction2()
{
	char* x = "china";
	char y[] = "china";

	*(x+1)='A';
	*(y+1)='A';

	printf("%s\n",x);
	printf("%s\n",y);
	
}


/*int main(int argc, char* argv[])
{
	//arrFunction1();
	
	return 0;
}*/

