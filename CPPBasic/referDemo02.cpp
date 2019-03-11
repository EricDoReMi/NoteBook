//引用类型探索

#include <stdio.h>
#include <windows.h>

void testMe(int& i){
	i=5;
}

void testMe(int* pI){
	*pI=3;
}

/*int main(int argc,char* argv[]){
	int i=6;
	testMe(i);
	printf("%d\n",i);
	testMe(&i);
	return 0;
}*/