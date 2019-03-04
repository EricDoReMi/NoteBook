#include "stdafx.h"

// 返回字符数组的长度了
int strlen(char* s)
{
	int len=0;
	while(*s!=0){
		len++;
		s++;
	}

	return len;
}

//复制字符串src到dest中。返回指针为dest的值。
char* strcpy(char* dest,char* src){
	char* result;
	result=dest;
	while((*(dest++)=*(src++))!=0);

	return result;
}

//将字符串src添加到dest尾部。返回指针为dest的值。
char* strcat(char* dest,char* src){
	char* result;
	result=dest;
	while(*(dest)!=0)
		dest++;
	strcpy(dest,src);
	return result;
}

//4、int strcmp ( char* s1, char* s2);			
//一样返回0  不一样返回1			
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

