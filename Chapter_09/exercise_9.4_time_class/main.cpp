// 9.4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
using namespace std;
#include<ctime>
#include<iomanip>

class Time
{
public:
	Time()
	{
		second=time(0)%60;
		minute=(time(0)/60)%60;
		hour=(time(0)/3600)%24;
	}
	void printTime()
	{
		cout<<setfill('0')<<setw(2)<<hour<<":"<<minute<<":"<<second<<(hour<12?"AM":"PM")<<endl;
	}
private:
	int hour;
	int minute;
	int second;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Time t1;
	cout<<"plz enter any thing!";
	char h;
	cin>>h;
	Time t2;
	t1.printTime();
	t2.printTime();
	return 0;
}

