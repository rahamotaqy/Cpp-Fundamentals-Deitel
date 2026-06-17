/* 17.control tarakonesh.cpp :this program reads a random access file sequentialy
update data previously written to the file,create data to be placed in the file,
delete data previously in the file*/
#include "stdafx.h"
#include"../client_data.hpp"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
using namespace std;

int enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void outPutLine(ostream&,const ClientData&);
void deleteRecord(fstream&);
int getAccount(const char*const);
enum Choices{PRINT=1,UPDATE,NEW,DELETE,END};

int _tmain(int argc, _TCHAR* argv[])
{fstream inOutCredit("creditFile.dat",ios::in|ios::out);
if(!inOutCredit){
	cerr<<"file could not be opened";
	exit(1);}
int choice;
// NOTE: Operator precedence makes this assign the result of (enterChoice()!=END).
//       Use while((choice=enterChoice())!=END) { ... } instead.
while(choice=enterChoice()!=END){
	switch(choice){
	case PRINT:
		createTextFile(inOutCredit);
		break;
	case UPDATE:
		updateRecord(inOutCredit);
		break;
	case NEW:
		newRecord(inOutCredit);
		break;
	case DELETE:
		deleteRecord(inOutCredit);
		break;
	default:
		cerr<<"incorrect choice"<<endl;
		break;}
	inOutCredit.clear();}
return 0;}
int enterChoice(){
	cout<<"Enter your choice:"<<endl
		<<"-store a formatted text file of accounts"<<endl
		<<"		called\"print.txt\"for printing"<<endl
		<<"2-update an account"<<endl
		<<"3-add a new account"<<endl
		<<"4-delete an account"<<endl
		<<"5-end program\n?";
	int menuChoice;
	cin>>menuChoice;
	return menuChoice;}
void createTextFile(fstream& readFromFile){
	ofstream outPrintFile("print.txt",ios::out);
	if(!outPrintFile){
		cerr<<"file could not be created."<<endl;
		exit(1);}
	outPrintFile<<left<<setw(0)<<"Account"<<setw(6)<<"lastName"<<setw(11)
		<<"firstName"<<right<<setw(10)<<"balance"<<endl;
	readFromFile.seekg(0);
	ClientData client;
	readFromFile.read(reinterpret_cast<char*>(&client),sizeof(ClientData));
	while(!readFromFile.eof()){
		if(client.getAccountNumber()!=0)
			outPutLine(cout,client);
		readFromFile.read(reinterpret_cast<char*>(&client),sizeof(ClientData));}}
void updateRecord(fstream& updateFile){
	int accountNumber=getAccount("enter account number to update");
	updateFile.seekg((accountNumber-1)*sizeof(ClientData));
	ClientData client;
	updateFile.read(reinterpret_cast<char*>(&client),sizeof(ClientData));
	if(client.getAccountNumber()!=0){
		outPutLine(cout,client);
	cout<<"\nEnter charge (+)or payment(-):"<<endl;
	double transaction;
	cin>>transaction;
	double oldBalance=client.getBalance();
	client.setBalance(transaction+oldBalance);
	outPutLine(cout,client);
	updateFile.seekp((accountNumber-1)*sizeof(ClientData));
	updateFile.write(reinterpret_cast<const char*>(&client),sizeof(ClientData));}
	else
		cerr<<"Account#"<<accountNumber<<"has no information"<<endl;}
void newRecord(fstream& insertInFile){
	int accountNumber=getAccount("enter new account number");
	insertInFile.seekg((accountNumber-1)*sizeof(ClientData));
	ClientData client;
	insertInFile.read(reinterpret_cast<char*>(&client),sizeof(ClientData));
	if(client.getAccountNumber()==0){
		char firstName[5];
		char lastName[10];
		double balance;
		cout<<"enter last name and first name and balance\n?";
		cin>>setw(15)>>lastName;
		cin>>setw(10)>>firstName;
		cin>>balance;
		client.setLastName(lastName);
		client.setFirstName(firstName);
		client.setBalance(balance);
		outPutLine(cout,client);
		insertInFile.seekp((accountNumber-1)*sizeof(ClientData));
		insertInFile.write(reinterpret_cast<const char*>(&client),sizeof(ClientData));}
	else cerr<<"account#"<<accountNumber<<"already contain information."<<endl;}
void deleteRecord(fstream& deleteFromFile){
	int accountNumber=getAccount("enter account to delete");
	deleteFromFile.seekg((accountNumber-1)*sizeof(ClientData));
	ClientData client;
	deleteFromFile.read(reinterpret_cast<char*>(&client),sizeof(ClientData));
	if(client.getAccountNumber()!=0){
		ClientData blankClient;//create blank record
		deleteFromFile.seekp((accountNumber-1)*sizeof(ClientData));
		deleteFromFile.write(reinterpret_cast<const char*>(&client),sizeof(ClientData));}
	else
		cerr<<"Account#"<<accountNumber<<"is empty";}
int getAccount(const char*const prompt){
	int accountNumber;
	do{cout<<prompt<<"(1-100):"<<endl;
	cin>>accountNumber;}
	while(accountNumber<1||accountNumber>100);
	return accountNumber;}
void outPutLine(ostream& output,const ClientData& record){
	output<<left<<setw(10)<<record.getAccountNumber()
		<<setw(16)<<record.getLastName()
		<<setw(11)<<record.getFirstName()
		<<setw(10)<<setprecision(2)<<right<<fixed<<showpoint<<record.getBalance()<<endl;}