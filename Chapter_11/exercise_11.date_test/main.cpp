// 11.test.Date.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream&,const Date&);
public:
	Date(int m=1,int d=1,int y=1990);
	void setDate(int,int,int);
	Date& operator++();
	Date operator++(int);
	const Date& operator+=(int);
	bool leapYear(int y)const;
	bool endOfMonth(int d)const;
private:
	static const int days[];
	int month,day,year;
	void helpIncrement();
};
// NOTE: _tmain/_TCHAR are Windows-specific. Use int main() for portability.
int _tmain(int argc, _TCHAR* argv[])
{
	Date d1;
	Date d2(12,27,1992);
	Date d3(0,99,8045);

	cout<<"d1 is: "<<d1<<"\nd2 is: "<<d2<<"\nd3 is: "<<d3<<endl;
	cout<<"\n\nd2+7 is: "<<(d2+=7);
	d3.setDate(2,28,1992);
	cout<<"\n\nd3 is: "<<d3;
	cout<<"\n++d3 is: "<<++d3<<"\t(leap year allows 29)";
	Date d4(7,13,2002);
	cout<<"\ntesting the prefix increment operator\n";
	cout<<"\nd4 is:"<<d4;
	cout<<"\n++d4 is: "<<++d4;
	cout<<"\nd4 is: "<<d4;
	cout<<"\n\ntesting the postfix increment operator:";
	cout<<"\nd4 is: "<<d4;
	cout<<"\nd4++ is: "<<d4++;
	cout<<"\nd4 is: "<<d4<<endl;
	return 0;
}
const int Date::days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
Date::Date(int mm,int dd,int yy)
{
	setDate(mm,dd,yy);
}
void Date::setDate(int m,int d,int y)
{
	month=(m>=1&&m<=12)?m:1;
	year=(y>1990&&y<2100)?y:1990;
	if(month==2&&leapYear(year))
		day=(d>0&&d<=29)?d:1;
	else
		day=(d>0&&d<=days[month])?d:1;
}
//overloaded prefix intecrement operator
Date& Date::operator++()
{
	helpIncrement();
	return *this;//refrence return to create an lvalue
}
//overloaded postfix increment operator,note that the dummy integer parameter does not have a parameter name
Date Date::operator++(int)
{
	Date temp=*this;
	helpIncrement();
	return temp;
}
const Date& Date::operator+=(int additionalDays)
{
	for(int i=0;i<additionalDays;i++)
		helpIncrement();
	return *this;
}
bool Date::leapYear(int testYear)const
{
	if(testYear%400==0||
		(testYear%100!=0&&testYear%4==0))
		return true;
	else
		return false;
}
bool Date::endOfMonth(int testDay)const
{
	if(month==2&&leapYear(year))
		return testDay==29;
	else
		return testDay==days[month];
}
void Date::helpIncrement()
{
	if(!endOfMonth(day))
		day++;
	else
		if(month<12)
		{
			month++;
			day=1;
		}
		else
		{
			year++;
			month=1;
			day=1;
		}
}
ostream& operator<<(ostream& output,const Date& d)
{
	// NOTE: String literals are const; use static const char* monthName[13].
static char* monthName[13]={"","january","february","march","april","may",
		"june","july","august","september","october","november","december"};
	output<<monthName[d.month]<<' '<<d.day<<", "<<d.year;
	return output;
}