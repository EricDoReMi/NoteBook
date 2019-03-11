/*冒泡排序和折半查找*/						
						

#include <stdio.h>
#include <windows.h>

//冒泡排序了
template<class T>
void bubbleSort(T* arr,int arrLen){
	int i=0;
	int j=0;
	for(i=0;i<arrLen-1;i++){
		for(j=0;j<arrLen-1-i;j++){
			if(*(arr+j+1)<*(arr+j)){
			T* tmp=new T();
			*tmp=*(arr+j);
			*(arr+j)=*(arr+j+1);
			*(arr+j+1)=*tmp;
			delete tmp;
			}
		}
	}
}

//折半查找了，要查找的数组必须排好序
//arr     要查找的数组
//arrLen  数组的长度
//element 要查找的元素
//返回值 找到则返回对应下标，没找到返回-1
template<class T>
int findByMid(T* arr,int arrLen,T element){
	int beginIndex=0,endIndex=arrLen-1,midIndex;
	while(beginIndex<=endIndex){
		midIndex=(beginIndex+endIndex)/2;
		if(*(arr+midIndex)<element){
			beginIndex=midIndex+1;
			
		}else if(*(arr+midIndex)>element){
			endIndex=midIndex-1;
		}else{
			
			return midIndex;
		}
	}

	return -1;
}

template<class T>
void printArr(T* arr,int arrLen){
	int i=0;
	for(i=0;i<arrLen;i++){
		printf("%d\n",*(arr+i));
	}
}


/*int main(int argc,char* argv[]){
	int arr[]={2,6,1,5,6};
	char arrChr[]={2,6,1,5,6};
	bubbleSort(arr,5);
	bubbleSort(arrChr,5);

	return 0;
}*/