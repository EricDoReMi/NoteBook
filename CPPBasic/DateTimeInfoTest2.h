class DateInfo
{

	int year;
	int month;
	int day;
public:
	DateInfo();

	DateInfo(int year,int month,int day);

	void setDay(int day);

	int getDay();

	void setMonth(int month);

	int getMonth();

	void setYear(int year);

	int getYear();
};

class TimeInfo:public DateInfo{
	int hour;
	int min;
	int sec;

	void test();
public:
	TimeInfo();

	TimeInfo(int year,int month,int day,int hour,int min,int sec);

	void setHour(int hour);

	int getHour();

	void setMin(int min);

	int getMin();

	void setSec(int sec);

	int getSec();

};