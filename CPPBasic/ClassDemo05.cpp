/*public��private��ʵ��*/						
						

#include <stdio.h>
#include <windows.h>

//��ĳ�ԱĬ�϶���private��
class Base{
public:
	Base(){
		this->x=1;
		this->y=2;
	}
private:
	int x;
	int y;


};


class Children:Base{
public:
	int a;
	int b;
};


/*int main(int argc,char* argv[]){
	Children c;
	int* pC=(int*)&c;
	printf("%d,%d",*pC,*(pC+1));
	return 0;
}*/