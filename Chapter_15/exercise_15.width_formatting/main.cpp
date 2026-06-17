// 15.test width.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int widthValue=4;
	char sentence[10];
	cout<<"enter a sentece:"<<endl;
	cin.width(5);//input only 5 character from sentence.
	while(cin>>sentence)
	{
		cout.width(widthValue++);
		cout<<sentence<<"\n";
		cin.width(5);//input 5 more character from sentence.
	}//end while

	return 0;
}

//man hanu nafahmideam in endl vagean chikar mikone va dastane in buffer va flush chie?!
