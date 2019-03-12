/*冒泡排序和折半查找*/						
						

#include <stdio.h>
#include <windows.h>

struct Number1{
private:
	int x;
	int y;
public:
	Number1();
	Number1(int x,int y);
	
	void Print();
	Number1& operator=(Number1& pNumber);
	friend Number1& operator++(Number1& pNumber);
	friend Number1& operator--(Number1& pNumber);
	friend Number1 operator+(Number1& pNumber1,const Number1& pNumber2);
	friend Number1 operator-(Number1& pNumber1,const Number1& pNumber2);
	friend bool operator>(Number1& pNumber1,const Number1& pNumber2);
	friend bool operator<(Number1& pNumber1,const Number1& pNumber2);
	
};

Number1::Number1(){
	this->x=0;
	this->y=0;
}

Number1::Number1(int x,int y){
	this->x=x;
	this->y=y;
}

//等号操作符重载不能用友元函数
Number1& Number1::operator=(Number1& pNumber){
	this->x=pNumber.x;
	this->y=pNumber.y;
	return *this;
	}

void Number1::Print(){
	printf("x:%d,y:%d\n",this->x,this->y);
}

Number1& operator++(Number1& pNumber){
	pNumber.x++;
	pNumber.y++;
	return pNumber;
	
}
Number1& operator--(Number1& pNumber){
	pNumber.x--;
	pNumber.y--;
	return pNumber;
}

Number1 operator+(Number1& pNumber1,const Number1& pNumber2){
	Number1* pNumber=new Number1;	
	pNumber->x=pNumber1.x+pNumber2.x;
	pNumber->y=pNumber1.y+pNumber2.y;
	Number1 tmp=*pNumber;
	delete pNumber;
	return tmp;
}

Number1 operator-(Number1& pNumber1,const Number1& pNumber2){
	Number1* pNumber=new Number1;
	pNumber->x=pNumber1.x-pNumber2.x;
	pNumber->y=pNumber1.y-pNumber2.y;
	Number1 tmp=*pNumber;
	delete pNumber;
	return tmp;
}

bool operator>(Number1& pNumber1,const Number1& pNumber2){
	if(pNumber1.x>pNumber2.x){
		return true;
	}else{
		return false;
	}
}

bool operator<(Number1& pNumber1,const Number1& pNumber2){
	if(pNumber1.x>pNumber2.x){
		return false;
	}else{
		return true;
	}
}

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


int main(int argc,char* argv[]){
	int arr[]={2,6,1,5,6};
	char arrChr[]={2,6,1,5,6};
	bubbleSort(arr,5);
	bubbleSort(arrChr,5);
	Number1 n1(1,2);
	Number1 n2(6,2);
	Number1 n3(3,1);
	Number1 n4(2,2);
	Number1 n5(3,2);
	Number1 n6(9,2);
	Number1 arrNum[]={n1,n2,n3,n4,n5,n6};
	bubbleSort(arrNum,6);
	
	for(int i=0;i<6;i++){
		arrNum[i].Print();
	}
	
	return 0;
}