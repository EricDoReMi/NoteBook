/*1设计一个结构?DateInfo,要求其满足下述要求。							
   							
   (1) 有三个成员： int year; int month;int day;							
???(2)?要求有个带参数的构造函数，其参数分别为对应年、月、日。							
   (3) 有一个无参数的构造函数，其初始的年、月、日分别为：2015、4、2。							
???(4)?要求有一个成员函数实现日期的设置：SetDay(int day)							
???(5)?要求有一个成员函数实现日期的获取: GetDay()							
???(6)?要求有一个成员函数实现年份的设置: SetYear(int year)							
???(7)?要求有一个成员函数实现年份的获取: GetYear()							
???(8)?要求有一个成员函数实现月份的设置: SetMonth(int month)							
???(9)?要求有一个成员函数实现月份的获取: GetMonth()							
							
							
2?设计一个结构?TimeInfo,要求其满足下述要求。							
???(1)?该结构中包含表示时间的时、分、秒。							
???(2)?设置该结构中时、分、秒的函数。							
???(3)?获取该结构中时、分、秒的三个函数：GetHour(),GetMinute()和GetSecond()。							
							
							
3 让TimeInfo继承DateInfo 分别使用DataInfo和TimeInfo的指针访问TimeInfo							
对象的成员.*/							

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