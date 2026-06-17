//7.final Credit program test.cpp 
//writing to a random access file
#include "stdafx.h"
#include"../client_data.hpp"
#include<iostream>//for cin,cout,cerr,fixed,showpointios,right,left
#include<cstdlib>//for exit
#include<string>//for string
#include<fstream>//for ifstream,ofstream,ostream
#include<iomanip>//for setw,setPRECISION
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ofstream outCredit("creditFile.dat",ios::out);
	if(!outCredit){
		cerr<<"file could not be created"<<endl;
		exit(1);}
	ClientData Client;//create a record
	cout<<"\nenter account number(1 to 100 and 0 to end input)\n?";
	int account;
	cin>>account;
	Client.setAccountNumber(account);
	while(account>0&&account<100){
		cout<<"enter last name and first name and balance\n?";
		char lastName[15];
		char firstName[10];
		double balance;
		cin>>setw(15)>>lastName;
		cin>>setw(10)>>firstName;
		cin>>balance;
		Client.setBalance(balance);
		Client.setFirstName(firstName);
		Client.setLastName(lastName);

		outCredit.seekp((Client.getAccountNumber()-1)*sizeof(ClientData));
		outCredit.write(reinterpret_cast<const char*>(&Client),sizeof(ClientData));
		cout<<"enter account number\n?";
		cin>>account;
		Client.setAccountNumber(account);}
	return 0;
}
void outPutLine(ostream& output,const ClientData& record){
	output<<left<<setw(10)<<record.getAccountNumber()
		<<setw(16)<<record.getLastName()
		<<setw(11)<<record.getFirstName()
		<<setw(10)<<setprecision(2)<<right<<fixed<<showpoint<<record.getBalance()<<endl;}
int ClientData::getAccountNumber()const{
	return accountNumber;}
void ClientData::setAccountNumber(int accountValue){
	//accountNumber=(accountValue>0&&accountValue<=100)?accountValue:-1;}
	accountNumber=accountValue;}
double ClientData::getBalance()const{
	return balance;}
void ClientData::setBalance(double balanceValue){
	balance=balanceValue;}
void ClientData::setFirstName(string first){
	const char* firstNameValue=first.data();
	int length=first.size();
	length=(length<15?length:14);
	strncpy(firstName,firstNameValue,length);
	firstName[length]='\0';}
void ClientData::setLastName(string last){
	const char* lastNameValue=last.data();
	int length=last.size();
	length=(length<10?length:9);
	strncpy(lastName,lastNameValue,length);
	lastName[length]='\0';}
string ClientData::getFirstName()const{
	return firstName;}
string ClientData::getLastName()const{
	return lastName;}
ClientData::ClientData(int ac,string f,string l,double bal){
	setAccountNumber(ac);
	setLastName(l);
	setBalance(bal);
	setFirstName(f);}