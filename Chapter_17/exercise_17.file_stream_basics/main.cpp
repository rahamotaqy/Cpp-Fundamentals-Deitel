// 17.test fstream.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstdlib>
using namespace std;

void outPutLine(string);
int _tmain(int argc, _TCHAR* argv[])
{
	ofstream setword("words.dat",ios::app);
	if(!setword){
		cerr<<"file could not be opened"<<endl;
		exit(1);}
	cout<<"enter the words"<<endl<<"enter eof to end!\n?"<<endl;
	char word[10];
	while(cin>>word){
		setword<<word<<endl;
		cout<<"\n?";}
	ifstream getWord("words.dat",ios::in);
	if(!getWord){
		cerr<<"file could not be opened"<<endl;
		exit(1);}
	cout<<right<<setw(12)<<"words:"<<endl;
	while(getWord>>word)
		outPutLine(word);
	ofstream modifywords("words.dat",ios::app);
	if(!modifywords){
		cout<<"file could not reopen!"<<endl;
		exit(1);}
	cout<<"\nenter the words"<<endl<<"enter eof to end!\n?"<<endl;
	cin.clear();//in nabashe in cin kar nemikone.
	modifywords.clear();
	while(cin>>word){
		modifywords<<word<<endl;
		cout<<"\n?";}
	getWord.close();
	getWord.open("words.dat",ios::in);
	if(!getWord){
		cerr<<"file could not be opened"<<endl;
		exit(1);}
	cout<<right<<setw(12)<<"words:"<<endl;
	//cout<<"esharegare mogheiiate file mortabet ba get word is here now:"<<getWord.tellg()<<endl;
	//getWord.seekg(0);
	//cout<<"esharegare mogheiiate file mortabet ba get word is here now:"<<getWord.tellg()<<endl;//in chera -1 hast va chera kar nemikone?
	getWord.clear();//in chikar mikone??
	while(getWord>>word)
		outPutLine(word);
	int e;
	cin.clear();
	cin>>e;
	return 0;
}
void outPutLine(string w)
{
	cout<<left<<setw(10)<<w;
}