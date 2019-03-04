//数组指针练习
#include "stdafx.h"

void pointer5Fun2(){
	int* (*px)[5];//px是变量名，指向了一个int*长度为5的数组
	printf("%d\n",sizeof(px));//宽度为 4 了的

	//赋值
	px=(int* (*)[5])10;//宽度为20
	printf("%d\n",px);//10
	px++;
	printf("%d\n",px);//30


}

void pointer5Fun3(){
	int arr[16]={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6};
	int (*px)[2];
	px=(int (*)[2])arr;
	
	printf("%d %d\n",px,arr);//一样的
	printf("%d %d\n",px+1,arr+1);

	printf("%d %d\n",*(*(px+1)+2),px[1][2]);

}

//使用数组指针遍历一维数组
void pointer5Fun5(){
	int arr[5]={1,2,3,4,5};
	int (*px)[1]=(int(*)[1])&arr;
	int i=0;
	for(i=0;i<5;i++){
		printf("%d ",*(*(px+i)));
	}
}


/*int main(int argc, char* argv[])
{
	
	pointer5Fun5();
		
	return 0;
}*/

