// wideChar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL,"");
	char x='��';
	wchar_t x1='��';
	wchar_t x2=L'��';

	char str1[]="��0��";
	wchar_t str2[]=L"��0��";

	printf("%s\n",str1);
	wprintf(L"%s\n",str2);

	printf("%d\n",strlen(str1));

	printf("%d\n",wcslen(str2));

	wchar_t a1[]=L"�й�";
	wchar_t a2[]=L"��";
	//wcscpy(a1,a2);
	wcscat(a1,a2);
	wprintf(L"%s\n",a1);

	CHAR cha[]="�й�";
	WCHAR chw[]=L"���й�";
	WCHAR chw2[]=L"��";
	TCHAR cht[]=TEXT("�й�");
	
	printf("%d\n",wcscmp(chw,chw2));

	wprintf(L"%s\n",wcsstr(chw,chw2));

	MessageBox(0,cht,"Hello",MB_OK);
	
	return 0;
}

