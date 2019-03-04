#include "stdafx.h"
#include "stdlib.h"

//这一堆数据中存储了角色的名字信息(WOW)，请列出角色名的内存地址.
char arrDatas[100]={
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x07,0x09,					
	0x00,0x20,0x10,0x03,0x03,0x0C,0x00,0x00,0x44,0x00,					
	0x00,0x33,0x00,0x47,0x0C,0x0E,0x00,0x0D,0x00,0x11,					
	0x00,0x00,0x00,0x02,0x64,0x00,0x00,0x00,0xAA,0x00,					
	0x00,0x00,0x64,0x10,0x00,0x00,0x00,0x00,0x00,0x00,					
	0x00,0x00,0x02,0x00,0x74,0x0F,0x41,0x00,0x00,0x00,					
	0x01,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x0A,0x00,					
	0x00,0x02,0x57,0x4F,0x57,0x00,0x06,0x08,0x00,0x00,					
	0x00,0x00,0x00,0x64,0x00,0x0F,0x00,0x00,0x0D,0x00,					
	0x00,0x00,0x23,0x00,0x00,0x64,0x00,0x00,0x64,0x00					

};

// 返回字符数组的长度了
int strlen1(char* s)
{
	int len=0;
	while((*s)!=0){
		len++;
		s++;
	}

	return len;
}

//复制字符串src到dest中。返回指针为dest的值。
char* strcpy1(char* dest,char* src){
	char* result;
	result=dest;
	while((*(dest++)=*(src++))!=0);

	return result;
}

//将字符串src添加到dest尾部。返回指针为dest的值。
char* strcat1(char* dest,char* src){
	char* result;
	result=dest;
	while(*(dest)!=0)
		dest++;
	strcpy1(dest,src);
	return result;
}

//4、int strcmp ( char* s1, char* s2);			
//一样返回0  不一样返回1			
int strcmp1(char* s1,char* s2){
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

//编写函数，返回角色名字信息的地址
void FindRoleNameAddr(char* pData,char* pRoleName){
	
	int pRoleNameLen=strlen1(pRoleName);
	char* pDataEnd=pData+99;
	
	while(pData<=(pDataEnd-pRoleNameLen)){
		
		if(!strcmp1(pData,pRoleName)){
			printf("address:%X,roleName:%s",pData,pData);
		}
		

		int pDataLen=strlen1(pData);
		if((pData+pDataLen)<pDataEnd){
			if(((*pData>=65) && (*pData<=90)) || (((*pData>=97) && (*pData<=122)))){
				pData+=(pDataLen+1);
			}else{
				pData++;
			}
			
		
			
		}
	}
}

int checkWord(char* pData){
	if (((*pData>=65) && (*pData<=90)) || ((*pData>=97) && (*pData<=122)))
		return 1;
	return 0;
}

//请编写函数，遍历上面数据中所有角色名字.
void getRoleNameAddr(char* pData){
	
	char* pDataEnd=pData+99;
	
	while(pData<pDataEnd){
		
		char* pDataTmp;
		if(checkWord(pData)){
			int dataLen=1;
			int flag=1;
			pDataTmp=pData+1;
			
			while(*pDataTmp!=0){
				dataLen++;
				if(!checkWord(pDataTmp)){
					flag=0;
					break;
				}
					pDataTmp++;
			}

			if(flag){
				printf("%s\n",pData);
			}
			pData+=dataLen;

		}else{
			pData++;
		}


			
						
	}
}



/*int main(int argc, char* argv[])
{
	//FindRoleNameAddr(arrDatas,"WOW");
	getRoleNameAddr(arrDatas);
	char* t=(char*)0x427B7C;
	printf("%s\n",t);
	return 0;
}*/

