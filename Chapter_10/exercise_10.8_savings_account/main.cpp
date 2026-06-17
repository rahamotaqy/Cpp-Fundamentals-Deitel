// 10.8.account.cpp :
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class SavingAccount
{
public:
	SavingAccount(const char*const,const char*const,double);
	void calculateMonthlyInterest();
	static void modifyInterestRate(double);
	void printSavingBalance(double)const;
	~SavingAccount();
private:
	double savingBalance;//mizane pas andaze jari
	static double annualInterestRate;//nerkhe soode mahane
	static int count;//kode moshtari
	char* firstName;
	char* lastName;
};

int _tmain(int argc, _TCHAR* argv[])
{
	SavingAccount saver1("zahra","mottaqi",2000.0);
	saver1.calculateMonthlyInterest();
	SavingAccount::modifyInterestRate(0.04);
	saver1.calculateMonthlyInterest();
	SavingAccount saver2("mohammadHadi","moqaddam",3000.0);
	SavingAccount::modifyInterestRate(0.03);
	saver2.calculateMonthlyInterest();
	SavingAccount::modifyInterestRate(0.04);
	saver2.calculateMonthlyInterest();
	return 0;
}
double SavingAccount::annualInterestRate=0.03;
int SavingAccount::count=0;
SavingAccount::SavingAccount(const char*const first,const char*const last,double sB)
{
	firstName=new char[strlen(first)+1];
	strcpy(firstName,first);
	lastName=new char[strlen(last)+1];
	strcpy(lastName,last);
	count++;
	savingBalance=(sB>0)?sB:0;
	cout<<"constructor for ("<<firstName<<","<<lastName<<") called.\nthe code is:"<<count<<"\nthe initial savingBalance is :"<<savingBalance<<"."<<endl;
}
void SavingAccount::calculateMonthlyInterest()
{
	double monthlyInterest=savingBalance*annualInterestRate/12;
	savingBalance+=monthlyInterest;
	printSavingBalance(monthlyInterest);
}
void SavingAccount::modifyInterestRate(double newRate)
{
	annualInterestRate=newRate;
}
void SavingAccount::printSavingBalance(double mI)const
{
	cout<<"your current balance is:"<<savingBalance<<"\nand your last month interest is:"<<mI<<"."<<endl;
}
SavingAccount::~SavingAccount()
{
	cout<<"destructor for ("<<firstName<<","<<lastName<<") called."<<endl;
	delete[] firstName;
	delete[] lastName;
	count--;
	cout<<"the code is:"<<count<<endl;
}
//hahaha:)barname bedune ghalate kampayli:)))