//÷∏’Î±æ÷ ¡∑œ∞
#include "stdafx.h"

void pointer5Fun1(){
	char* p1;	
	char** p2;	
	char*** p3;	
	char**** p4;	
	char***** p5;	
	char****** p6;	
	char******* p7;	

	char a=1;
	p1=&a;
	p2=&p1;
	p3=&p2;
	printf("%d %d\n",p2[0][0],*(*(p2+0)+0));

	int i=5;
	int* p_i=&i;
	printf("%d\n",p_i[0]);



}



/*int main(int argc, char* argv[])
{
	
	pointer5Fun1();
		
	return 0;
}*/

