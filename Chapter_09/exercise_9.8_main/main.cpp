// 9.8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iomanip>
using namespace std;
#include<iostream>

class Date
{
public:
	Date(int dd=1,int mm=1,int yy=2000)
	{
		setDate(dd,mm,yy);
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
			cout<<"\nwrong input!\nturnning month to 2000."<<endl;
			return false;
			}
	}
	void printDate()
	{
		cout<<setw(4)<<year<<"/"<<setw(2)<<month<<"/"<<setw(2)<<day<<endl;
		if((month==1)&&(day==1))
			cout<<"HAPPY NEW YEAR!"<<endl;
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
private:
	int day,month,year;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Date date1(8,12,2000);
	cout<<"\ndate1 is:";
	date1.printDate();
	Date date2(37,2,3);
	cout<<"\ndate2 is:";
	date2.printDate();
	Date date3(28,12,2000);
	cout<<"\ndate3 is:";
	date3.printDate();
	int order;
	cout<<"\nenter 1 to go to next day and 2 to stop!";
		cin>>order;
	while(order==1)
	{
		date3.nextDay();
		date3.printDate();
		cout<<"\nenter 1 to go to next day and 2 to stop!";
		cin>>order;
	};
	date2=date3;
	cout<<"\ndate 2=date3 :\ndate2="<<endl;
	date2.printDate();
	return 0;
}

