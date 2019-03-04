// 字符串数组
// F7编译，F5执行，F9打断点，shift+F5终止程序执行,F10 跳进，F11步进

#include "stdafx.h"
#include "string.h"

typedef struct student
{
	int num;
	char name[20];
	char sex;
	int age;
	int score;
	char addr[30];
}Student;


/*int main(int argc, char* argv[])
{
	Student stu[10];

	stu[0].num=1001;
	strcpy(stu[0].name,"张三");
	stu[0].sex='M';
	stu[0].age=28;
	stu[0].score=99;
	strcpy(stu[0].addr,"成都市");

	printf("%d %s %c %d %d %s\n",stu[0].num,stu[0].name,stu[0].sex,stu[0].age,stu[0].score,stu[0].addr);


	return 0;
}*/

