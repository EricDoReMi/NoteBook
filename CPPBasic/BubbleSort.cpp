/*ð��������۰����*/						
						

#include <stdio.h>
#include <windows.h>

//ð��������
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

//�۰�����ˣ�Ҫ���ҵ���������ź���
//arr     Ҫ���ҵ�����
//arrLen  ����ĳ���
//element Ҫ���ҵ�Ԫ��
//����ֵ �ҵ��򷵻ض�Ӧ�±꣬û�ҵ�����-1
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