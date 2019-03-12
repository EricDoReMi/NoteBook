//运算符重载

#include <stdio.h>
#include <windows.h>

struct Number{
private:
	int x;
	int y;
public:
	Number();
	Number(int x,int y);
	void Print();
	Number& operator=(Number& pNumber);
	friend Number& operator++(Number& pNumber);
	friend Number& operator--(Number& pNumber);
	friend Number operator+(Number& pNumber1,const Number& pNumber2);
	friend Number operator-(Number& pNumber1,const Number& pNumber2);
	friend bool operator>(Number& pNumber1,const Number& pNumber2);
	friend bool operator<(Number& pNumber1,const Number& pNumber2);
	
};

Number::Number(){
	this->x=0;
	this->y=0;
}

Number::Number(int x,int y){
	this->x=x;
	this->y=y;
}

//等号操作符重载不能用友元函数
Number& Number::operator=(Number& pNumber){
	this->x=pNumber.x;
	this->y=pNumber.y;
	return *this;
	}

void Number::Print(){
	printf("x:%d,y:%d\n",this->x,this->y);
}

Number& operator++(Number& pNumber){
	pNumber.x++;
	pNumber.y++;
	return pNumber;
	
}
Number& operator--(Number& pNumber){
	pNumber.x--;
	pNumber.y--;
	return pNumber;
}
Number operator+(Number& pNumber1,const Number& pNumber2){
	Number* pNumber=new Number;
	
	
	pNumber->x=pNumber1.x+pNumber2.x;
	pNumber->y=pNumber1.y+pNumber2.y;
	Number tmp=*pNumber;
	delete pNumber;
	return tmp;
}
Number operator-(Number& pNumber1,const Number& pNumber2){
	Number* pNumber=new Number;
	pNumber->x=pNumber1.x-pNumber2.x;
	pNumber->y=pNumber1.y-pNumber2.y;
	Number tmp=*pNumber;
	delete pNumber;
	return tmp;
}

bool operator>(Number& pNumber1,const Number& pNumber2){
	if(pNumber1.x>pNumber2.x){
		return true;
	}else{
		return false;
	}
}

bool operator<(Number& pNumber1,const Number& pNumber2){
	if(pNumber1.x>pNumber2.x){
		return false;
	}else{
		return true;
	}
}

/*int main(int argc,char* argv[]){
	Number n1(1,2);
	Number n2(5,6);
	printf("%d\n",n2>n1);
	Number n3;
	Number n5;
	n3++;
	n5=n1+n2;
	printf("%x\n",&n5);
	n3=n5;
	printf("%x\n",&n3);
	n3.Print();	
	
	return 0;
}*/