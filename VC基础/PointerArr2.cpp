//����ָ����ϰ
#include "stdafx.h"

void pointer5Fun2(){
	int* (*px)[5];//px�Ǳ�������ָ����һ��int*����Ϊ5������
	printf("%d\n",sizeof(px));//���Ϊ 4 �˵�

	//��ֵ
	px=(int* (*)[5])10;//���Ϊ20
	printf("%d\n",px);//10
	px++;
	printf("%d\n",px);//30


}

void pointer5Fun3(){
	int arr[16]={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6};
	int (*px)[2];
	px=(int (*)[2])arr;
	
	printf("%d %d\n",px,arr);//һ����
	printf("%d %d\n",px+1,arr+1);

	printf("%d %d\n",*(*(px+1)+2),px[1][2]);

}

//ʹ������ָ�����һά����
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

