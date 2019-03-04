//数组和桶排序
// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"

__int64 f21(){
	__int64 a=0x1234567890;
	
	return a;
}

void funaa1(char a,char b){

}

void funaa2(){
	char a=1;
	char b=2;
}

void funaa3(){
	int v_0 = 1;
	int v_1 = 2;
	int v_2 = 3;
	int v_3 = 4;
	int v_4 = 5;
	int v_5 = 6;
	int v_6 = 7;
	int v_7 = 8;
	int v_8 = 9;
	int v_9 = 10;

}

void funaa5(){
	int arr[10]={1,2,3,4,5};
	int aa=arr[8];
}

void funaa6(){
	//short arr[3]={1,2,3};
	short arr22[4]={1,2,3,4};
}

void funaa7(){
	int x = 1;			
	int y = 2;			
	int r;			
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};			
			
	r = arr[1];			
	r = arr[x];			
	r = arr[x+y];			
	r = arr[x*2+y];			

}

void tankSort(){
	int arr[6]={1,5,3,1,2,9};
	int ret[10]={0};
	int i=0,k=0,t=0;
	for(i=0;i<6;i++){
		ret[arr[i]]++;
	}

	for(k=0;k<10;k++){
		t=ret[k];
		
			while(t>0){
				printf("%d\n",k);
				t--;
		
		}
	}
	
}

void arr2Wei(){
	int arr[2][3]={
		{1,2,3},
		{4,5,6}
	};

	int arr2[2][3]={
		{1,2},
		{3}
	};

	int arr3[][5]={0};
}

void arr2Wei2(){

	int arr[5][12] = {						
				
		{1,2,1,4,5,6,7,8,9,1,2,3},
		{1,2,1,4,5,6,7,8,9,1,2,3},
		{1,2,1,4,5,6,7,8,9,1,2,3},
		{1,2,1,4,5,6,7,8,9,1,2,3},
		{1,2,1,4,5,6,7,8,9,1,2,2}

	};						

	int i,j,sum;
	i=0;
	j=0;

	sum=0;

	for(i=0;i<5;i++){
		for(j=0;j<12;j++){
			if(i==1 && arr[i][j]>8){
				arr[i][j]=99;
			}
			
		}
	}

	for(i=0;i<5;i++){

		for(j=0;j<12;j++){

			sum+=arr[i][j];
				
			if(j<11){
					printf("%d,",arr[i][j]);
				}else{
					printf("%d",arr[i][j]);
				}
			
		}

		printf("\n");
	}

	printf("%d\n",sum);

}

void arr2Wei3(){
	int arr[8]={3,5,7,9,12,25,34,55};
	int arrTwo[6]={4,7,9,11,13,16};

	int arrRst[14]={0};

	int i=0;
	int j=0;
	int k=0;

	while(i<8 && j<6){
     
		if(arr[i]<arrTwo[j]){
				
				
					arrRst[k]=arr[i];
				    i++;
				
				
			
		}else{
		    
				
				
					arrRst[k]=arrTwo[j];
					j++;
				
				
			
		}
		k++;
	}

	while(k<14){
		if(i<8 && j==6){
			arrRst[k]=arr[i];
			i++;
		}
		if(j<6 && i==8){
			arrRst[k]=arrTwo[j];
			j++;
		}
		k++;
	}

	for(i=0;i<14;i++){
		printf("%d,",arrRst[i]);
	}

}

/*int main(int argc, char* argv[])
{
    
    arr2Wei3();

	return 0;
}*/
