//����һ���ṹ��Monster���ܹ��洢�ֵĸ�����Ϣ(������һ����Ա�ǽṹ������)��

//����һ��Monster���͵����飬����Ϊ10.

//��дһ��������Ϊ�ڶ����е����鸳ֵ.

//��дһ���������ܹ�ͨ������ID����ӡ��ǰ��������������Ϣ.

#include "stdafx.h"
#include "string.h"
#include "stdlib.h"
#define random(x)(rand()%x)

struct Point
{
	int x;
	int y;
};

struct Monster
{
	int id;
	char* mName;
	Point p;
};

Monster arrMonster[10];

void setArrMonster(){
	int i=0;
	
	for(i=0;i<10;i++){
				
		int id;
		id=i+1;
		
		char *idStr=(char *)malloc(10);
		



		sprintf(idStr,"%d",id);

		Monster m;
		m.id=i+1;
		m.mName=(char *) malloc(7+strlen(idStr)+1);
		sprintf(m.mName,"%s%s","Monster",idStr);
		Point p;
		p.x=random(100);
		p.y=random(100);
		m.p=p;
		arrMonster[i]=m;
		free(idStr);
	}
}

void getArrMonster(int id){
	if(id>0 && id<11){
		int i=0;
		for(i=0;i<10;i++){
			Monster m;
			m=arrMonster[i];
			if(m.id==id){
				printf("id:%d,name:%s,X:%d,Y:%d\n",id,m.mName,m.p.x,m.p.y);
			}
		}

	}else{
		printf("invalid id\n");
	}
}

void clearArrMaster(){
	int i=0;
	for(i=0;i<10;i++){
		Monster m=arrMonster[i];
		m.id=0;
		free(m.mName);
		m.p.x=0;
		m.p.y=0;
	}
}



/*int main(int argc, char* argv[])
{	
	int id;
	id=5;
	setArrMonster();
	getArrMonster(id);
	clearArrMaster();
	return 0;
}*/

