/*Ä£°å*/						
						

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

template<class T>
struct Base12{
	T x;
	T y;
	Base12(T x,T y){
		this->x=x;
		this->y=y;
	}

	T Max(){
		if(x>y){
			return x;	
		}else{
			return y;
		}
	}

	void swap(){
		T tmp=this->x;
		this->x=y;
		this->y=tmp;
	}

};


/*int main(int argc,char* argv[]){
	Base12<int> b(2,3);
	printf("%d\n",b.Max());
	b.swap();
	printf("%d,%d\n",b.x,b.y);

	return 0;
}*/