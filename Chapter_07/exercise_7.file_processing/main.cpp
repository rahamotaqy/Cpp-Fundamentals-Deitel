// 7.test inClientFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;

bool shouldDisplay(int type,double balance);
void outPutLine(int account,const string name,double balance);
int getRequest();
enum RequestType{ZERO_BALANCE=1,CREDIT_BALANCE,DEBIT_BALANCE,END};
int _tmain(int argc, _TCHAR* argv[])
{
/*	ofstream inClientFile("client.dat",ios::out);
	if(!inClientFile){
		cerr<<"cant open file"<<endl;
		exit(1);}
	cout<<"enter the account,name and balance"<<endl
		<<"and oef to END input\n?";*/
	int account;
	double balance;
	char name[30];
	/*while(cin>>account>>name>>balance){
	inClientFile<<account<<' '<<name<<' '<<balance<<' '<<endl;
	cout<<"\n?";}*/
	ifstream outClientFile("TextFile1.txt",ios::in);
	if(!outClientFile){
		cerr<<"cant open file"<<endl;
		exit(1);}
	cout<<setw(10)<<left<<"Account"<<setw(13)<<"name"<<"balance"<<endl<<fixed<<showpoint;
	while(outClientFile>>account>>name>>balance)
		outPutLine(account,name,balance);
	ifstream ClientFile("TextFile1.txt",ios::in);
	if(!ClientFile){
		cerr<<"cant open file"<<endl;
		exit(1);}
	int request;
	request=getRequest();
	while(request!=END){
		switch(request){
			case ZERO_BALANCE:
				cout<<"Account with ZERO_BALANCE:\n";
				break;
			case CREDIT_BALANCE:
				cout<<"Account with CREDIT_BALANCE:\n";
				break;
			case DEBIT_BALANCE:
				cout<<"Account with DEBIT_BALANCE:\n";
				break;}
		ClientFile>>account>>name>>balance;
		while(!ClientFile.eof()){//inja dadeye 4 om ke akharin dade ast va debit hastesh ro ke mikhune dge checkesh nemikone chon eof esh engar false mishe!!
			if(shouldDisplay(request,balance))
				outPutLine(account,name,balance);
			ClientFile>>account>>name>>balance;}//end inner while
		ClientFile.clear();
		ClientFile.seekg(0);
		request=getRequest();}//end outer while
	cout<<"End of run."<<endl;
	return 0;
}
int getRequest()
{
	int request;
	cout<<"enter request"<<endl
		<<"1-zero balance\n2-credit balance\n3-debit balance\n4-end"
		<<fixed<<showpoint;
	do{cout<<"\n?";
	cin>>request;}
	while(request<ZERO_BALANCE&&request>END);
	return request;}
bool shouldDisplay(int request,double balance){
	if(request==ZERO_BALANCE&&balance==0)
		return true;
	if(request==CREDIT_BALANCE&&balance>0)
		return true;
	if(request==DEBIT_BALANCE&&balance<0)
		return true;
	return false;}
void outPutLine(int account,const string name,double balance){
	cout<<left<<setw(10)<<account<<setw(13)<<name
		<<setw(7)<<setprecision(2)<<right<<balance<<endl;}