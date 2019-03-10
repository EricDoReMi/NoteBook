/*public和private的实现*/						
						

#include <stdio.h>
#include <windows.h>

struct Test{
private:
	int x;
	int y;
public:
	int z;
	void printTest(){
		printf("x:%d,y:%d,z:%d\n",this->x,this->y,this->z);
	}
};



/*int main(int argc,char* argv[]){
	Test t;
	
	int* pT=(int*)&t;

	*pT=1;
	*(pT+1)=2;

	printf("sizeOfTest:%d\n",sizeof(t));
	
	t.z=10;

	t.printTest();

	return 0;
}*/