/*public和private的实现*/						
						

#include <stdio.h>
#include <windows.h>

//类的成员默认都是private的
class Base{

	int x;
	int y;

};

class Base2{
public:
	int x;
	int y;
};



class Children:Base2{
public:
	int a;
	int b;
};

class Children2:public Base2{
public:
	int a;
	int b;
};



/*int main(int argc,char* argv[]){
	Children2 c2;
	c2.x=1;

	return 0;
}*/