//���캯��̽��

#include <stdio.h>
#include <windows.h>

struct Cal2
{
	int x;
	int y;
	char* arr;
	//�޲ι��캯��
	Cal2(){
		arr=(char*)malloc(10);
	}

	//���캯�������캯����������
	Cal2(int x,int y){
		this->x=x;
		this->y=y;
		arr=(char*)malloc(10);
	}

	//����������
	~Cal2(){
		printf("������������\n");
		free(arr);
	}

	//��Ա����
	void print(){
		printf("%d,%d\n",x,y);
	}

	//��Ա��������
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