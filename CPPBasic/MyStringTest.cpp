/*4?���һ���ṹ����MyString��Ҫ��ýṹ�ܹ�������¹��ܣ�						
  (1)?���캯���ܹ�����ʵ�ʴ���Ĳ�������ʵ�ʴ洢�ռ䣻						
  (2) �ṩһ���޲εĹ��캯����Ĭ�Ϸ����СΪ1024���ֽڣ�						
  (3)?���������ͷŸÿռ䣻						
  (4)?��д��Ա����SetString�����Խ�һ���ַ�����ֵ���ýṹ��						
  (5)?��д��Ա����PrintString�����Խ��ýṹ�����ݴ�ӡ����Ļ�ϣ�						
  (6)?��д��Ա����AppendString�����������е����ݺ���������ݣ�						
  (7)?��д��Ա����Size�����ڵõ���ǰ���ݵ���ʵ���ȡ�						
  ��д���Գ��򣬲�������ṹ��*/						
						

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