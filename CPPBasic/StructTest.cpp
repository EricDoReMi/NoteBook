//½á¹¹ÌåÌ½Ë÷

#include <stdio.h>

struct Person
{
	void fn_1(){
		printf("Person:Fn_1\n");	
	}

	void fn_2(){
		printf("Person:fn_2\n");
	}
};

struct Person1{
	int x;
	void fn_1(){
		printf("Person:Fn_1\n");
	}
	void fn_2(){
		x=10;
		printf("Person:fn_2:%d\n",x);
	}

};

/*int main(int argc,char* argv[]){
	rson* pPerson=NULL;
	pPerson->fn_1();
	pPerson->fn_2();
    Person1* p1=NULL;
	p1->fn_1();
	p1->fn_2();
	return 0;

}*/