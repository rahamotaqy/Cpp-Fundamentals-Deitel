// 9.7.time.cpp : Defines the entry point for the console application.
//

// NOTE: stdafx.h is Visual Studio precompiled-header boilerplate; remove for portable C++.
#include "stdafx.h"
#include<iostream>
using namespace std;
#include<ctime>
#include<iomanip>

class Time
{
public:
	Time(int hour=0,int min=0,int sec=0)
	{
		setTime(hour,min,sec);
		check(hour,min,sec);
		t1=time(0);
	}
	void check(int h,int m,int s)
	{
		(setHour(h))?cout<<"\n":cout<<"wrong input!\nhour turned into 0\n";
		(setMinute(m))?cout<<"\n":cout<<"wrong input!\nminute turned into 0\n";
		(setSecond(s))?cout<<"\n":cout<<"wrong input!\nsecond turned into 0\n";
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
	void tick()
	{
		int t2=time(0);
		int passedSecond=t2-t1;
		int passedMinute=(passedSecond+getSecond())/60;
		int passedHour=(getMinute()+passedMinute)/60;
		t1=t2;
		setSecond((passedSecond+getSecond())%60);
		setMinute((getMinute()+passedMinute)%60);
		setHour(passedHour+getHour()%24);
	}
	void printStandard()
	{
		cout<<((getHour()==0)||(getHour()==12)?12:getHour()%12)<<":"<<setfill('0')<<setw(2)<<getMinute()
			<<":"<<setw(2)<<getSecond()<<(hour<12?"am":"pm")<<endl;
	}
private:
	int second,minute,hour,t1;
};

// NOTE: _tmain/_TCHAR are Windows-specific. Use int main() for portability.
int _tmain(int argc, _TCHAR* argv[])
{
	Time tehranTime(23,59,50);
	cout<<"enter 1 to print time!";
	int order;
	cin>>order;
	do{
		tehranTime.tick();
		tehranTime.printStandard();
		cin>>order;
	}while(order==1);
	Time myTime(33,20,70);

	return 0;
}

//kollan tavabeii ke faghat tavassote tavabe e dge bekar borde mishan tavabe e komaki ya utility hastand?