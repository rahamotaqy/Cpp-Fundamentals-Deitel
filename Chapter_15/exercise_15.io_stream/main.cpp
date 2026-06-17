// 15.test io stream.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
     /*char* cPtr=new char[20];
	  char* cPtr1=new char[20];
	 char test,test1;
	 char a[20];
	 cout<<"eof is:"<<cin.eof()<<endl;
	 test=cin.get();
	 cout<<"test is:"<<test<<endl;
	 cout<<"eof is:"<<cin.eof()<<endl;
	 cin.clear();
	 cout<<"eof is:"<<cin.eof()<<endl;
	 cin.get(test1);
	 cout<<"test1 is:"<<test1<<endl;
	 cout<<"eof is:"<<cin.eof()<<endl;
	 cin.get(cPtr,20);
	 cout<<"cPtr is:"<<*cPtr<<endl
		 <<"the cPtr is:"<<cPtr<<"\nthe adress is:"<<&cPtr<<endl;
	 cin.get(a,20,'E');
	 cout<<"a is:"<<*a<<endl
		 <<"the a is:"<<a<<endl;
	 cout<<"the adress is:"<<&a<<endl;

	 cin.getline(cPtr1,20);
	 cout<<"cPtr1 is:"<<*cPtr1<<endl;
	 cin.getline(cPtr,20,'U');
	 cout<<"cPtr is:"<<*cPtr<<endl;)
	 */
	int test;
	cout<<"eof is:"<<cin.eof()<<endl;
	cout<<"enter a sentence and enter eof to end."<<endl;
	while((test=cin.get())!=EOF)
		cout.put(test);
	cout<<"eof is:"<<cin.eof()<<"\t"<<test<<endl;
	char t=cin.get();
	cout<<"t is:"<<t<<endl;
	cin.clear();
	t=cin.get();
	cout<<"t is:"<<t<<endl;
	cout<<"eof is:"<<cin.eof()<<"\t"<<t<<endl;
	cin.clear();
	t=cin.get();
	cout<<"t is:"<<t<<endl;
	cout<<"eof is:"<<cin.eof()<<"\t"<<t<<endl;
	cin.ignore();
	cout<<"eof is:"<<cin.eof()<<"\t"<<t<<endl;
	t=cin.get();
	cout<<"t is:"<<t<<endl;
	return 0;
}

//vaaa!in ceshe?!!