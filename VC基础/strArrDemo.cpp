// 指针的基本用法了


#include "stdafx.h"
//这一堆数据中存储了角色的血值信息，假设血值的类型为int类型，值为100(10进制)
//请列出所有可能的值以及该值对应的地址.
//

void arrFuntion1()
{
	char arr[6] = {'A','B','C','D','E','\0'};

	char names[] = "ABCDEF";

	printf("%s\n",arr);

	printf("%s\n",names);
}

void arrFunction2()
{
	char* x = "china";
	char y[] = "china";

	*(x+1)='A';
	*(y+1)='A';

	printf("%s\n",x);
	printf("%s\n",y);
	
}


/*int main(int argc, char* argv[])
{
	//arrFunction1();
	
	return 0;
}*/

