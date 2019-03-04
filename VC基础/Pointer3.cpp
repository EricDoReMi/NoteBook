// 数组的本质

#include "stdafx.h"

void PrintArray(char arr[],int nLength){
	int i=0;
	for(i=0;i<nLength;i++){
		printf("%d\n",*(arr+i));
	}
}

/*int main(int argc, char* argv[])
{
	char arr[10]={1,2,3,4,5,6,7,8,9,10};
	char* p=arr;
	int i=0;
	for(i=0;i<10;i++){
		*(p+i)=*(p+i)*2;
	}
    int lengthArr=10;
	PrintArray(p,lengthArr);
	return 0;
}*/

