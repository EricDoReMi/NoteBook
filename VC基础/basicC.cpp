// C语言语法基础
// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"
int g_x=5;
int g_y=6;
int g_z=8;
int g_r=0;
int arr2[5]={2,5,7,9,3};
int arr3[9]={2,11,3,6,1,0,22,-1,-3};


void max1(){
	if(g_x>=g_y){
		if(g_z>=g_x){
			g_r=g_z;
		}else{
			g_r=g_x;
		}	
	}else{
		if(g_z>=g_y){
			g_r=g_z;
		}else{
		    g_r=g_y;
		}
	}
}

void max2(){
	int i=0;
	for(i=0;i<5;i++){
		if(i==0){
			g_r=arr2[i];
		}else{
			if(arr2[i]>g_r){
				g_r=arr2[i];
			}
		}
	}
}

void arrSum(){
	int i=0;
	g_r=0;
	for(i=0;i<5;i++){
		g_r=g_r+arr2[i];
	}
}

void popArr(){
	int i=0;
	int j=0;
	int isSorted=0;
	for(i=0;i<8;i++){
       isSorted=1;
	   for(j=0;j<8-i;j++){
		   if(arr3[j]>arr3[j+1]){
			  int tmp=0;
			  tmp=arr3[j];
			  arr3[j]=arr3[j+1];
			  arr3[j+1]=tmp;
			  isSorted=0;
		   }
		  
	   }
	   if(isSorted){
				break;
		   }
	
	}
}




/*int main(int argc, char* argv[])
{
	max1();
	printf("%d\n",g_r);

	arrSum();
	printf("%d\n",g_r);

	popArr();
	return 0;
}*/

