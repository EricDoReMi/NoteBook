//ºê¶¨Òå Demo

#include "stdafx.h"

#define TRUE 1
#define FALSE 0
#define PI 3.141592653
#define DEBUG 0
#define MAX(A,B) ((A)>(B)?(A):(B))

int defineDemoFun1(){
	return FALSE;
}

double defineDemoFun2(int r){
	return PI*2*r;
}

void defineDemoFun3(){
	if(DEBUG){
		printf("Debug");
	}
}

void defineDemoFun5(int a,int b){
	printf("%d\n",MAX(a,b));
}

/*int main(int argc, char* argv[])
{
	defineDemoFun5(3,5);
	return 0;
}*/

