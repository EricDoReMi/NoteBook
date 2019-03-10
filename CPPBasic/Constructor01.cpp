//构造函数探索

#include <stdio.h>
#include <windows.h>

struct Cal2
{
	int x;
	int y;
	char* arr;
	//无参构造函数
	Cal2(){
		arr=(char*)malloc(10);
	}

	//构造函数，构造函数的重载了
	Cal2(int x,int y){
		this->x=x;
		this->y=y;
		arr=(char*)malloc(10);
	}

	//析构函数了
	~Cal2(){
		printf("调用析构函数\n");
		free(arr);
	}

	//成员函数
	void print(){
		printf("%d,%d\n",x,y);
	}

	//成员函数重载
	void print(int x){
		printf("%d\n",x);
	}

};



/*int main(int argc,char* argv[]){
	Cal2 pC(2,3);
	
	pC.print();

	Cal2 pC2();

	return 0;

}*/