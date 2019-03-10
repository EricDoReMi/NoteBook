//¼Ì³ĞµÄÌ½Ë÷

#include <stdio.h>
#include <windows.h>

struct Person3
{
	int age;
	int sex;
};

struct Teacher3:Person3
{
	int level;
	int classId;
};

struct Student3:Person3
{
	int code;
	int score;
};



/*int main(int argc,char* argv[]){

	Teacher3 teacher;
	teacher.age=36;
	teacher.sex=1;
	teacher.classId=1;
	teacher.level=1;
	
	Student3 student;
	student.age=19;
	student.sex=1;
	student.code=5;
	student.score=98;

	Person3* p3=&teacher;
	printf("%d\n",p3->age);
	
	return 0;
}*/