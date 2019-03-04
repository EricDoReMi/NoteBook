#include "stdafx.h"

// �����ַ�����ĳ�����
int strlen(char* s)
{
	int len=0;
	while(*s!=0){
		len++;
		s++;
	}

	return len;
}

//�����ַ���src��dest�С�����ָ��Ϊdest��ֵ��
char* strcpy(char* dest,char* src){
	char* result;
	result=dest;
	while((*(dest++)=*(src++))!=0);

	return result;
}

//���ַ���src��ӵ�destβ��������ָ��Ϊdest��ֵ��
char* strcat(char* dest,char* src){
	char* result;
	result=dest;
	while(*(dest)!=0)
		dest++;
	strcpy(dest,src);
	return result;
}

//4��int strcmp ( char* s1, char* s2);			
//һ������0  ��һ������1			
int strcmp(char* s1,char* s2){
	int result;
	result=0;
	while(*s1!=0 && *s2!=0){
		if((*s1)!=(*s2)){
			result=1;
			break;
		}
		s1++;
		s2++;
	}

	if((*s1)!=0 || (*s2)!=0){
		result=1;
	}

	return result;
}



/*int main(int argc, char* argv[])
{
	char arr[5]	={'A','V','S','C',0};
	char arrSource[5]={'b','c','t','u',0};
	
	int result;
	result=strcmp(arr,arrSource);

	printf("%d\n",result);
	return 0;
}*/

