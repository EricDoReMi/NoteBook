/*4?设计一个结构叫做MyString，要求该结构能够完成以下功能：						
  (1)?构造函数能够根据实际传入的参数分配实际存储空间；						
  (2) 提供一个无参的构造函数，默认分配大小为1024个字节；						
  (3)?析构函数释放该空间；						
  (4)?编写成员函数SetString，可以将一个字符串赋值给该结构；						
  (5)?编写成员函数PrintString，可以将该结构的内容打印到屏幕上；						
  (6)?编写成员函数AppendString，用于向已有的数据后面添加数据；						
  (7)?编写成员函数Size，用于得到当前数据的真实长度。						
  编写测试程序，测试这个结构。*/						
						

#include <stdio.h>
#include <windows.h>

struct MyString{
	char* pMyString;
	MyString(){
		pMyString=(char*)malloc(1024);
	}
	MyString(int strLen){
		pMyString=(char*)malloc(strLen+1);
	}

	~MyString(){
		free(pMyString);
	}

	void setString(char* inputStr){
		strcpy(pMyString,inputStr);
	}

	void printString(){
		printf("%s\n",pMyString);
	}

	int getMyStringSize(){
		return strlen(pMyString);
		
	}

	void appendStr(char* appendStr){
		int len=strlen(pMyString)+strlen(appendStr)+2;
		char* pNewMyString=(char*)malloc(len);
		strcpy(pNewMyString,pMyString);
		
		strcpy(pNewMyString+strlen(pMyString),appendStr);
		free(pMyString);
		pMyString=pNewMyString;
	}

};


/*int main(int argc,char* argv[]){
	MyString myString(3);
	myString.setString("abc");
	myString.appendStr("de");
	myString.printString();
	printf("len:%d\n",myString.getMyStringSize());
	return 0;
}*/