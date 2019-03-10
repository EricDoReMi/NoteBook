//¼Ì³ÐµÄÌ½Ë÷,¶à²ã¼Ì³ÐÌ½Ë÷

#include <stdio.h>
#include <windows.h>

struct X
{
	int a;
	int b;
};

struct Y:X
{
	int a;
	int c;
};

struct Z:Y
{
	int e;
	int f;
};



/*int main(int argc,char* argv[]){
	Z z;

	printf("%d\n",sizeof(z));
	z.X::a=1;
	z.Y::a=2;
	printf("%d\n",z.Y::a);
	
	return 0;
}*/