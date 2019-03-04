// 指针数组的用法了


#include "stdafx.h"

struct Arg{
	int a;
	char b;
	short c;
};

void pointArrFun1(){
	char* p1="if";
	char* p2="for";
	char* p3="while";
	char* p4="switch";

	char* keyword[]={p1,p2,p3,p4};

}

/*int main(int argc, char* argv[])
{
	Arg s;
	s.a=1;
	s.b=2;
	s.c=3;
	printf("%d,%d,%d\n",s.a,s.b,s.c);

	Arg* p_arg=&s;
	printf("%d,%d,%d\n",p_arg->a,p_arg->b,p_arg->c);
	
	return 0;
}*/

