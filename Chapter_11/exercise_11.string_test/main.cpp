// 11.test.string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#ifndef STRING_H
#define STRING_H
class String
{
	friend istream &operator>>(istream&,String&);
	friend ostream &operator<<(ostream&,const String&);
public:
	String(const char* ="");//conversion/default constructor
	String(const String&);//copy constructor
	~String();//destructor

	const String& operator=(const String&);
	const String& operator+=(const String&);

	bool operator!()const;
	bool operator==(const String&)const;
	bool operator<(const String&)const;

	bool operator>(const String& right)const
	{
		return right<*this;
	}
	bool operator>=(const String& right)const
	{
		return !(*this<right);
	}
	bool operator!=(const String& right)const
	{
		return !(*this==right);
	}
	bool operator<=(const String& right)const
	{
		return !(right<*this);
	}
	char& operator[](int);
	char operator[](int)const;
	String operator()(int,int=0)const;
	int getLength()const;
private:
	char* sPtr;
	int length;

	void setString(const char*);//utility function
};
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	String s1("happy ");
	String s2("birthday ");
	String s3;
	cout<<"s1 is: "<<s1<<" ;s2 is: "<<s2<<" ;s3 is: "<<s3<<" ;"<<endl;
	cout<<boolalpha<<"\n\nthe result of comparing s2 and s1:\ns2==s1\t"<<(s2==s1)
		<<"\ns2!=s1\t"<<(s2!=s1)
		<<"\ns2>s1\t"<<(s2>s1)
		<<"\ns2<s1\t"<<(s2<s1)
		<<"\ns2>=s1\t"<<(s2>=s1)
		<<"\ns2<=s1\t"<<(s2<=s1)
		<<"\n\n";
	cout<<"testing !s3:"<<endl;
	if(!s3)
		{cout<<"s3 is empyt.assigning s1 to s3:"<<endl;
		s3=s1;
		cout<<"s3 is: "<<s3<<endl;
		}
	cout<<"\ns1+=s2 yeilds s1= ";
	s1+=s2;
	cout<<s1;
	cout<<"\n\ns1+=\" to you \" yields\n";
	s1+="to you";
	cout<<"s1 is:"<<s1<<endl;

	cout<<"the substring of s1 starting at\n"
		<<"location 0 for 14 characters, s1(0,14), is:\n"
		<<s1(0,14)<<"\n\n";
	cout<<"the substring of s1 starting at \n"
		<<"location 15,s1(15),is:"
		<<s1(15)<<"\n\n";
	String *s4Ptr=new String (s1);
	cout<<"*s4Ptr"<<*s4Ptr<<"\n\n";
	cout<<"assigning *s4Ptr to *s4Ptr"<<endl;
	*s4Ptr=*s4Ptr;
	cout<<"s4Ptr="<<*s4Ptr<<endl;
	delete s4Ptr;
	s1[0]='H';
	s1[6]='B';
	cout<<"\ns1 after s1[0]='H' and s1[6]='B' is:"
		<<s1<<"\n\n";
	cout<<"attempt to assign 'd' to s1[30] yields:"<<endl;
	s1[30]='d';
	

	return 0;
}
String::String(const char* s)
	:length((s!=0)?strlen(s):0)
{
	cout<<"conversion and default constructor : "<<s<<" called."<<endl;
	setString(s);
}
String::String(const String& copy)
	:length(copy.length)
{
	cout<<"copy constructor: "<<copy.sPtr<<" called."<<endl;
	setString(copy.sPtr);
}
String::~String()
{
	cout<<"destructor : "<<sPtr<<" called."<<endl;
	delete[] sPtr;
}
const String& String::operator=(const String& right)
{
	cout<<"operator= called."<<endl;
	if(&right!=this)
	{
		delete[] sPtr;
		length=right.length;
		setString(right.sPtr);
	}
	else
		cout<<"Attempted to assign a string to itself!"<<endl;
	return *this;
}
const String& String::operator+=(const String& right)
{
	size_t newLength=length+right.length;
	char* tempPtr=new char[newLength+1];
	strcpy(tempPtr,sPtr);
	strcpy(tempPtr+length,right.sPtr);
	delete[]sPtr;
	sPtr=tempPtr;
	length=newLength;
	return *this;
}
bool String::operator!()const
{
	return length==0;
}
bool String::operator==(const String& right)const
{
	return strcmp(sPtr,right.sPtr)==0;
}
bool String::operator<(const String& right)const
{
	return strcmp(sPtr,right.sPtr)<0;
}
char& String::operator[](int subscript)
{
	if(subscript<0||subscript>=length)
	{
		cerr<<"ERROR:subscript: "<<subscript<<" out of range!"<<endl;
		exit(1);
	}
	return sPtr[subscript];
}
char String::operator[](int subscript)const
{
	if(subscript<0||subscript>=length)
	{
		cerr<<"ERROR:subscript: "<<subscript<<" out of range!"<<endl;
		exit(1);
	}
	return sPtr[subscript];
}
String String::operator()(int index,int subLength)const
{
	if(index<0||index>=length||subLength<0)
		return "";
	int len;
	if((index+subLength>length)||(length==0))
		len=length-index;
	else 
		len=subLength;
	char* tempPtr=new char[len+1];
	strncpy(tempPtr,&sPtr[index],len);
	tempPtr[len+1]='\0';
	String tempString(tempPtr);
	delete []tempPtr;
	return tempString;
}
int String::getLength()const
{
	return length;
}
void String::setString(const char* string2)
{
	sPtr=new char[length+1];
	if(string2!=0)
		strcpy(sPtr,string2);
	else
		sPtr[0]='\0';
}
ostream& operator<<(ostream& output,const String& s)
{
	output<<s.sPtr;
	return output;
}
istream& operator>>(istream& input,String& s)
{
	char temp[100];
	input>>setw(100)>>temp;
	s=temp;
	return input;
}
