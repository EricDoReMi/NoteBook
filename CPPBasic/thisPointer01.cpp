//½á¹¹ÌåÌ½Ë÷

#include <stdio.h>

struct sclass
{
	int x;
	int y;
	int z;

	int Plus3(sclass* ps){
		return ps->x+ps->y+ps->z;
	}
};

int Plus(sclass s){
	return s.x+s.y+s.z;
}

int Plus2(sclass* ps){
	return ps->x+ps->y+ps->z;
}

/*int main(int argc,char* argv[]){
	sclass s;
	s.x=1;
	s.y=2;
	s.z=3;
	//Plus(s);

	//Plus2(&s);
	s.Plus3(&s);
	return 0;
}*/

