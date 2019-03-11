//引用类型探索

#include <stdio.h>
#include <windows.h>

struct Base13{
private:
	int x;
	int y;
public:
	Base13(){
		x=1;
		y=2;
	}
	Base13(int x,int y){
		this->x=x;
		this->y=y;
	}

	friend void Print(Base13& bp);
};

void Set(Base13& bp){
		Base13 b(8,9);
		bp=b;
		
	}

void Print(Base13& bp){
		printf("%d,%d\n",bp.x,bp.y);
	}


/*int main(int argc,char* argv[]){
	Base13 b;
	Set(b);
	Print(b);
	return 0;
}*/