#include "stdafx.h"
#include<iostream>
#include<cstring>
#include<iomanip>
#include<ctime>
using namespace std;
#ifndef DATE_H
#define DATE_H
class Date
{
public:
	Date(int,int,int);
	Date();
	Date(int,int);
	Date(const char *const,int,int);
	void printType3(const char*const);
	void printType2(int);
	void print1()const;
	void print2()const;
	void print3()const;
//	static int* getValue();
	~Date();
private:
	int checkDay(int)const;
	int day,month,year;
	static const int daysPerMonths[13];
};
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	Date d1(5,13,2004);
	d1.print2();
	d1.print3();
	Date d2(230,2006);
	Date d3("march",26,2008);
	Date d4;

	//Date d4(Date::getValue())   agha mikham az karbar begiram in tarikho ba esharegar be araye int befrestam be shey !!chikar konam?!
	return 0;
}
const int Date::daysPerMonths[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
/*int*Date::getValue()
{
	cout<<"give me the date you wanna print!";
	int value[3];
	for(int i=0;i<3;i++)
		cin>>value[i];
	return value;

}*/
Date::Date()
{
	int y=time(0)/(334*24*60*60);
	year=1970+y-1;
	int d=time(0)%(334);
	month=d/30;
	day=d%30;
	//((time(0)%y)/60*60*24)/
	cout<<"\n\n\nconstructor for current time called:\n";
	print1();

}
//chon natunestam az tavabe e kelase ctime sardar biaram
//va besheddat kundard am daram az inke estesnaha ro biaram ta daghigh beshe mazooram.
Date::Date(int mn,int dy,int yr)
{
	if(mn>0&&mn<=12)
		month=mn;
	else{
		month=1;
		cout<<"invalid month("<<mn<<") set to 1.\n";
		}
	year=yr;
	day=checkDay(dy);
	cout<<"\n\nconstructor type 1 called.for date:";
	print1();
}
Date::Date(int d,int yr)
{
	int allDays=(d>0&&d<365)?d:1;
	if(allDays==1)
		cout<<"wrong day("<<d<<") setting to 1.\n"<<endl;
	year=yr;
	cout<<"\n\nconstructor type 2 called.for date:";
	printType2(allDays);
}

Date::Date(const char *const m,int b,int c)
{
	if(b>0&&b<30)
		day=b;
	else 
	{
		day=1;
		cout<<"wrong day("<<b<<") setting to 1.\n"<<endl;
	}
	year=c;

	cout<<"\n\nconstructor type 3 called.for date:";
	printType3(m);
}
void Date::printType2(int a)
{
	cout<<setfill('0')<<setw(3)<<a<<' '<<year;
}
void Date::printType3(const char*const a )
{
	cout<<a<<' '<<day<<","<<year<<endl;
}
void Date::print1()const
{
	cout<<"\nprinting type 1 is:"<<setfill('0')<<setw(2)<<month<<"/"<<setw(2)<<day<<"/"<<year<<endl;;
}
void Date::print2()const
{
	int daysTillNow=0;
	for(int mn=0;mn<month;mn++)
		daysTillNow+=daysPerMonths[mn];
	daysTillNow+=day;
	cout<<"printing type 2 is:"<<setfill('0')<<setw(3)<<daysTillNow<<' '<<year<<endl;
}
void Date::print3()const
{
	static const char *months[13]={" ","january","february","march","april","may","june","july","august","september","october","november","december"};
	cout<<"printing type 3 is:"<<months[month]<<' '<<setfill('0')<<setw(2)<<day<<","<<year<<endl;
}
Date::~Date()
{
	cout<<"\ndate object destructor.";
	cout<<endl;
}
int Date::checkDay(int testDay)const
{
	if(testDay>0&&testDay<=daysPerMonths[month])
		return testDay;
	if(month==2&&testDay==29&&(year%400==0||(year%4==0&&year%100!=0)))
		return testDay;
	cout<<"invalid day("<<testDay<<") set to 1.\n";
	return 1;
}