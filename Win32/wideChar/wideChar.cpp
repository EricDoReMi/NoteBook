// wideChar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL,"");
	char x='中';
	wchar_t x1='中';
	wchar_t x2=L'中';

	char str1[]="中0国";
	wchar_t str2[]=L"中0国";

	printf("%s\n",str1);
	wprintf(L"%s\n",str2);

	printf("%d\n",strlen(str1));

	printf("%d\n",wcslen(str2));

	wchar_t a1[]=L"中国";
	wchar_t a2[]=L"好";
	//wcscpy(a1,a2);
	wcscat(a1,a2);
	wprintf(L"%s\n",a1);

	CHAR cha[]="中国";
	WCHAR chw[]=L"你中国";
	WCHAR chw2[]=L"国";
	TCHAR cht[]=TEXT("中国");
	
	printf("%d\n",wcscmp(chw,chw2));

	wprintf(L"%s\n",wcsstr(chw,chw2));

	MessageBox(0,cht,"Hello",MB_OK);
	
	return 0;
}

