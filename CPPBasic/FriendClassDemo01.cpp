//友元类的使用

#include <stdio.h>
#include <windows.h>

struct XiaoMu{
private:
	int x;
	int y;
public:
	friend struct Friend;
	XiaoMu(){
		x=1;
		y=2;
	}
};

struct Friend{
	void printXiaoMu(XiaoMu& xiaomu){
		printf("%d,%d\n",xiaomu.x,xiaomu.y);
	}
};



/*int main(int argc,char* argv[]){
	Friend f;
	XiaoMu x;
	f.printXiaoMu(x);
	return 0;
}*/