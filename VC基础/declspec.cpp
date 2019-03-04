// Helloworld.cpp : Defines the entry point for the console application.
// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"

void __declspec(naked) myfun(){

	__asm{
		push ebp
		mov ebp,esp
		sub esp,0x48
		push ebx
		push esi
		push edi

		lea edi,dword ptr ds:[ebp-0x48]
		mov eax,0xCCCCCCCC
		mov ecx,0x12
		rep stosd

		pop edi
		pop esi
		pop ebx
		mov esp,ebp
		pop ebp

		ret
	}
}

int __declspec(naked) myfun2(int x,int y,int z){

	__asm{
		//提升栈
		push ebp
		mov ebp,esp
		sub esp,0x48
		push ebx
		push esi
		push edi
		lea edi,dword ptr ds:[ebp-0x48]
		mov eax,0xCCCCCCCC
		mov ecx,0x12
		rep stosd

		mov dword ptr ds:[ebp-0x4],0x2
		mov dword ptr ds:[ebp-0x8],0x3
		mov dword ptr ds:[ebp-0xc],0x4

		mov eax,dword ptr ds:[ebp+8]
		add eax,dword ptr ds:[ebp+0xC]
        add eax,dword ptr ds:[ebp+0x10]
		add eax,dword ptr ds:[ebp-0x4]
		add eax,dword ptr ds:[ebp-0x8]
		add eax,dword ptr ds:[ebp-0xc]

		pop edi
		pop esi
		pop ebx
		mov esp,ebp
		pop ebp
		ret
	
	}
}

int __cdecl plus1(int x,int y){
	return x+y;
}

int __stdcall plus2(int x,int y){
	return x+y;
}

int __fastcall plus3(int x,int y){
	return x+y;
}


/*int main(int argc, char* argv[])
{
	//myfun();

	int d =0;
    
	d=myfun2(1,2,3);

    printf("%d",d);

   
	int a,b,c;

	a=plus1(1,2);
	b=plus2(1,2);
	c=plus3(1,2);

	printf("%d,%d,%d",a,b,c);


	return 0;
}*/

