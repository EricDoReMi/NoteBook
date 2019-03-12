/*1���һ���ṹ?DateInfo,Ҫ������������Ҫ��							
   							
   (1) ��������Ա�� int year; int month;int day;							
???(2)?Ҫ���и��������Ĺ��캯����������ֱ�Ϊ��Ӧ�ꡢ�¡��ա�							
   (3) ��һ���޲����Ĺ��캯�������ʼ���ꡢ�¡��շֱ�Ϊ��2015��4��2��							
???(4)?Ҫ����һ����Ա����ʵ�����ڵ����ã�SetDay(int day)							
???(5)?Ҫ����һ����Ա����ʵ�����ڵĻ�ȡ: GetDay()							
???(6)?Ҫ����һ����Ա����ʵ����ݵ�����: SetYear(int year)							
???(7)?Ҫ����һ����Ա����ʵ����ݵĻ�ȡ: GetYear()							
???(8)?Ҫ����һ����Ա����ʵ���·ݵ�����: SetMonth(int month)							
???(9)?Ҫ����һ����Ա����ʵ���·ݵĻ�ȡ: GetMonth()							
							
							
2?���һ���ṹ?TimeInfo,Ҫ������������Ҫ��							
???(1)?�ýṹ�а�����ʾʱ���ʱ���֡��롣							
???(2)?���øýṹ��ʱ���֡���ĺ�����							
???(3)?��ȡ�ýṹ��ʱ���֡��������������GetHour(),GetMinute()��GetSecond()��							
							
							
3 ��TimeInfo�̳�DateInfo �ֱ�ʹ��DataInfo��TimeInfo��ָ�����TimeInfo							
����ĳ�Ա.*/							

#include <stdio.h>
#include <windows.h>


struct DateInfo
{
	int year;
	int month;
	int day;
	DateInfo(){
		year=2015;
		month=4;
		day=2;
	}

	DateInfo(int year,int month,int day){
		this->year=year;
		this->month=month;
		this->day=day;
	}

	void setDay(int day){
		this->day=day;
	}

	int getDay(){
		return this->day;
	}

	void setMonth(int month){
		this->month=month;
	}

	int getMonth(){
		return this->month;
	}

	void setYear(int year){
		this->year=year;
	}

	int getYear(){
		return this->year;
	}
};

struct TimeInfo:DateInfo{
	int hour;
	int min;
	int sec;
	TimeInfo(){
		this->hour=0;
		this->min=0;
		this->sec=0;
		
	}

	TimeInfo(int year,int month,int day,int hour,int min,int sec){
		DateInfo* pFather=(DateInfo*)this;
		pFather->year=year;
		pFather->month=month;
		pFather->day=day;
		this->hour=hour;
		this->min=min;
		this->sec=sec;
	}

	void setHour(int hour){
		this->hour=hour;
	}

	int getHour(){
		return this->hour;
	}

	void setMin(int min){
		this->min=min;
	}

	int getMin(){
		return this->min;
	}

	void setSec(int sec){
		this->sec=sec;
	}

	int getSec(){
		return this->sec;
	}

};



/*int main(int argc,char* argv[]){
	TimeInfo timeInfo(2018,1,16,11,15,32);
	printf("Year:%d Mon:%d Day:%d Hour:%d Min:%d Sec:%d\n",timeInfo.getYear(),timeInfo.getMonth(),timeInfo.getDay(),timeInfo.getHour(),timeInfo.getMin(),timeInfo.getSec());

	
	return 0;
}*/