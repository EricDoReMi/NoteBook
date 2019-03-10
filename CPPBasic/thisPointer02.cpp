//½á¹¹ÌåÌ½Ë÷

#include <stdio.h>

struct sclass2
{
	int x;
	int y;
	int z;



int PlusPointer3(){
		return x+y+z;
	}


};

struct sclass3
{

};


int PlusPointer2(sclass2* s){
		return s->x+s->y+s->z;
	}


/*int main(int argc,char* argv[]){
	sclass2 s;

	printf("%d\n",sizeof(sclass2));
	s.x=1;
	s.y=2;
	s.z=3;

	printf("%d\n",sizeof(sclass3));
	int a=s.PlusPointer3();


	return 0;
}*/

