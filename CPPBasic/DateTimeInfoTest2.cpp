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
#include "DateTimeInfoTest2.h"




DateInfo::DateInfo(){
		year=2015;
		month=4;
		day=2;
	}

DateInfo::DateInfo(int year,int month,int day){
		this->year=year;
		this->month=month;
		this->day=day;
	}

void DateInfo::setDay(int day){
		this->day=day;
	}

int DateInfo::getDay(){
		return this->day;
	}

void DateInfo::setMonth(int month){
		this->month=month;
	}

int DateInfo::getMonth(){
		return this->month;
	}

void DateInfo::setYear(int year){
		this->year=year;
	}

int DateInfo::getYear(){
		return this->year;
	}


TimeInfo::TimeInfo(){
		this->hour=0;
		this->min=0;
		this->sec=0;
		
	}

TimeInfo::TimeInfo(int year,int month,int day,int hour,int min,int sec):DateInfo(year,month,day){
	
		this->hour=hour;
		this->min=min;
		this->sec=sec;
	}

void TimeInfo::setHour(int hour){
		this->hour=hour;
	}

	int TimeInfo::getHour(){
		return this->hour;
	}

	void TimeInfo::setMin(int min){
		this->min=min;
	}

	int TimeInfo::getMin(){
		return this->min;
	}

	void TimeInfo::setSec(int sec){
		this->sec=sec;
	}

	int TimeInfo::getSec(){
		return this->sec;
	}
	
	void TimeInfo::test(){
		printf("TimeInfoTest\n");
	}


/*t main(int argc,char* argv[]){
	TimeInfo timeInfo(2018,1,16,11,15,32);
	printf("Year:%d Mon:%d Day:%d Hour:%d Min:%d Sec:%d\n",timeInfo.getYear(),timeInfo.getMonth(),timeInfo.getDay(),timeInfo.getHour(),timeInfo.getMin(),timeInfo.getSec());
	//timeInfo.test();
	return 0;
}*/