// writing a random access file and reading the random access file sequentialy
// NOTE: stdafx.h is Visual Studio precompiled-header boilerplate.
//       For portable C++11, remove this line and add #include <string> for strncpy.
#include "stdafx.h"
#include<iostream>//for cin,cout,cerr,fixed,showpointios,right,left
#include<cstdlib>//for exit
// NOTE: strncpy requires <string> (or <string.h>) in standard C++.
#include<string>//for string
#include<fstream>//for ifstream,ofstream,ostream
#include<iomanip>//for setw,setPRECISION
using namespace std;
#ifndef CLIENT_H
#define CLIENT_H
class ClientData{
public:
	ClientData(int=0,string=" ",string=" ",double=0.0);
	void setAccountNumber(int);
	int getAccountNumber()const;
	void setFirstName(string);
	string getFirstName()const;
	void setLastName(string);
	string getLastName()const;
	void setBalance(double);
	double getBalance()const;
private:
	int accountNumber;
	char lastName[15];
	char firstName[10];
	double balance;
};
#endif
void outPutLine(ostream&,const ClientData&);
// NOTE: _tmain/_TCHAR are Windows-specific. Use int main() for portability.
int _tmain(int argc, _TCHAR* argv[]){
	ofstream outCredit("creditFile.dat",ios::out);
	if(!outCredit){
		cerr<<"file could not be opened to write."<<endl;
		exit(1);}
	/*ClientData blankClient;//create a sample blanket record
	for(int i=0;i<100;i++)
		outCredit.write(reinterpret_cast<const char*>(&blankClient),sizeof(ClientData));*///in ghesmat 100 ta recorde khali ro minevise
	/*ofstream outCredit2;
	outCredit2.open("credit",ios::in|ios::out|ios::binary);
	if(!outCredit){
		cerr<<"\n\nfile could not re open";
		exit(1);}
	cout<<"file :credit has been opened!but i dont know what is open for?!";*/
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
	ifstream inCredit("creditFile.dat",ios::in);
	if(!inCredit){
		cerr<<"\n\nfile can not open to read!";
		exit(1);}
	cout<<"state of stream is :"<<inCredit.rdstate()<<"and end of file is:"<<inCredit.eof()<<endl;
	cout<<left<<setw(10)<<"Account"<<setw(16)<<"LastName"<<setw(11)<<"FirstName"<<left<<setw(10)<<right<<"Balance\n"<<endl;//writing first line
	inCredit.read(reinterpret_cast<char*>(&Client),sizeof(ClientData));
	cout<<"state of stream is :"<<inCredit.rdstate()<<"and end of file is:"<<inCredit.eof()<<endl;
	inCredit.clear();
	cout<<"state of stream is :"<<inCredit.rdstate()<<"and end of file is:"<<inCredit.eof()<<endl;
	while(inCredit&&!inCredit.eof()){
		if(Client.getAccountNumber()!=0)
			outPutLine(cout,Client);
		inCredit.read(reinterpret_cast<char*>(&Client),sizeof(ClientData));}
	return 0;}
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

