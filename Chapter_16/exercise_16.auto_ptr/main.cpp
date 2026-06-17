// 16.test.autp_ptr.cpp : Defines the entry point for the console application.
//

// NOTE: stdafx.h is Visual Studio precompiled-header boilerplate; remove for portable C++.
#include "stdafx.h"
#include<iostream>
using namespace std;
#include<exception>
#include<memory>
#include<new>
#include<cstdlib>
class Error:public exception
{
public:
	Error()
		// NOTE: std::exception has no (message, code) constructor. Inherit from std::runtime_error instead.
:exception("error occured.",110){
	}//end constructor
};//end class error
void getValue()
{
// NOTE: std::auto_ptr is removed in C++17 and unsafe for arrays. Use std::unique_ptr<int[]>.
	auto_ptr<int>test(new int[5]);
	int arrayname[2];
	cout<<"enter 7 enteger to input;";
	for(int i=0;i<7;i++)
		if
	

// NOTE: _tmain/_TCHAR are Windows-specific. Use int main() for portability.
int _tmain(int argc, _TCHAR* argv[])
{
	

	return 0;
}

