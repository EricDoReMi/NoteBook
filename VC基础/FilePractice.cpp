//将记事本的.exe文件读取到内存，并返回读取后在内存中的地址.

//将内存中的数据存储到一个文件中，(.exe格式)，然后双击打开，看是否能够使用.

// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>


int getFileSize(FILE *P_file){
	int filesize=0;
	fseek(P_file,0,SEEK_END);
	filesize=ftell(P_file);
	fseek(P_file, 0, SEEK_SET);
	return filesize;
}

char* saveFileToMem(FILE *p_file,int fileSize){
	char* p_m;
	p_m=(char*)malloc(fileSize);
	if(p_m==NULL){
		return 0;
	}
	memset(p_m,0,fileSize);
	fread(p_m,1,fileSize,p_file);
	return p_m;
}

/*int main(int argc, char* argv[])
{
	FILE *p_file=fopen("Hello.exe","rb");
	FILE *p_file1=fopen("HelloWorld1.exe","wb");
	char* p_m;
	p_m=NULL;
	if(p_file){
		int fileSize=getFileSize(p_file);
		p_m=saveFileToMem(p_file,fileSize);
		if(p_file1){
			fwrite(p_m,1,fileSize,p_file1);
			fclose(p_file1);
			p_file1=NULL;
		}

		if(p_m){
			free(p_m);
		}
		fclose(p_file);
		p_file=NULL;
	}

	return 0;
}*/

