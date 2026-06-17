// 9.7.time.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include<ctime>
#include<iomanip>

class DateAndTime
{
public:
	DateAndTime(int hour=0,int min=0,int sec=0,int dd=1,int mm=1,int yy=2000)
	{
		setTime(hour,min,sec);
		check(hour,min,sec);
		t1=time(0);
		setDate(dd,mm,yy);
	}
	
	void tick()
	{
		int t2=time(0);
		int passedSecond=t2-t1;
		int passedMinute=(passedSecond+getSecond())/60;
		int passedHour=(getMinute()+passedMinute)/60;
		// NOTE: C++ does not allow void expressions as operands of ?:.
//       Replace with if((passedHour+getHour())/24) nextDay(); else cout << endl;
((passedHour+getHour())/24)?nextDay():cout<<endl;
		t1=t2;
		setSecond((passedSecond+getSecond())%60);
		setMinute((getMinute()+passedMinute)%60);
		setHour(passedHour+getHour()%24);
	}
	void printStandard()
	{
		cout<<setw(4)<<year<<"/"<<setw(2)<<month<<"/"<<setw(2)<<day<<"\t";
		cout<<((getHour()==0)||(getHour()==12)?12:getHour()%12)<<":"<<setfill('0')<<setw(2)<<getMinute()
			<<":"<<setw(2)<<getSecond()<<(hour<12?"am":"pm")<<endl;
		if((month==1)&&(day==1))
			cout<<"HAPPY NEW YEAR!"<<endl;
	}
	void printUniversal()
	{
		cout<<year<<"/"<<setw(2)<<setfill('0')<<month<<"/"<<setw(2)<<day<<"\t"<<hour<<":"<<minute<<":"<<second<<"."<<endl;
	}
private:
	int day,month,year;
	int second,minute,hour,t1;
	int getDay()
	{
		return day;
	}
	int getMonth()
	{
		return month;
	}
	int getYear()
	{
		return year;
	}
		void setDate(int d,int m,int y)
	{
		setDay(d);
		setMonth(m);
		setYear(y);
	}
	bool setDay(int ddd)
	{
		day=(ddd>0&&ddd<31)?ddd:1;
		if(day==ddd)
			return true;
		else {
			cout<<"\nwrong input!\nturnning day to 1."<<endl;
			return false;
			}	
	}
	bool setMonth(int mmm)
	{
		month=(mmm>0&&mmm<13)?mmm:1;
		if(month==mmm)
			return true;
		else {
			cout<<"\nwrong input!\nturnning month to 1."<<endl;
			return false;
			}
	}
	bool setYear(int yyy)
	{
		year=(yyy>1999)?yyy:2000;
		if(year==yyy)
			return true;
		else {
			cout<<"\nwrong input!\nturnning year to 2000."<<endl;
			return false;
			}
	}
	void check(int h,int m,int s)
	{
		(setHour(h))?cout<<"":cout<<"wrong input!\nhour turned into 0\n";
		(setMinute(m))?cout<<"":cout<<"wrong input!\nminute turned into 0\n";
		(setSecond(s))?cout<<"":cout<<"wrong input!\nsecond turned into 0\n";
	}
	void setTime(int h,int m,int s)
	{
		setHour(h);
		setMinute(m);
		setSecond(s);
	}
	bool setHour(int hh)
	{
		hour=(hh>0)&&(hh<24)?hh:0;
		if(hour==hh)
			return true;
		else return false;
	}
	bool setMinute(int mm)
	{
		minute=(mm>0)&&(mm<60)?mm:0;
		if(minute==mm)
			return true;
		else return false;
	}
	bool setSecond(int ss)
	{
		second=(ss>0)&&(ss<60)?ss:0;
		if(second==ss)
			return true;
		else return false;
	}
	int getHour()
	{
		return hour;
	}
	int getMinute()
	{
		return minute;
	}
	int getSecond()
	{
		return second;
	}
	void nextDay()
	{
		int newDay=getDay();
		int newMonth=getMonth();
		int newYear=getYear();
		newDay=(getDay()==30)?1:getDay()+1;
		if(newDay==1)
		{
			if(getMonth()<12)
				newMonth=getMonth()+1;
			else
			{
				newMonth=1;
				newYear=getYear()+1;
			}
		}
		setDay(newDay);
		setMonth(newMonth);
		setYear(newYear);
	}
};

// NOTE: _tmain/_TCHAR are Windows-specific. Use int main() for portability.
int _tmain(int argc, _TCHAR* argv[])
{
	DateAndTime t2;
	cout<<"intial date and time is:"<<endl;
	t2.printStandard();
	DateAndTime t1(23,58,30,2,4,2004);
	cout<<"t1 is:"<<endl;
	t1.printStandard();
	t1.printUniversal();
	cout<<"enter 1 to print date and time and 2 to stop!"<<endl;
	int order;
	cin>>order;
	while(order==1)
	{
		t1.tick();
		t1.printStandard();
		cout<<"enter 1 to print date and time and 2 to stop!"<<endl;
		cin>>order;
	}
	DateAndTime t3(40,70,40,3,56,6);
	cout<<"t3 is wrong input:"<<endl;
	t3.printStandard();
	t3.printUniversal();

	return 0;
}

