// 11.test.Array..cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include<iomanip>
#include<cstdlib>
#ifndef ARRAY_H
#define ARRAY_H
class Array
{
	friend ostream &operator<<(ostream&,const Array&);
	friend istream &operator>>(istream&,Array &);
public:
	Array(int=10);
	Array(const Array&);
	~Array();
	int getSize();
	const Array &operator=(const Array &);
	bool operator==(const Array&)const;
	bool operator!=(const Array& right)const
	{
		return !(*this==right);
	}
	int &operator[](int);
	int operator[](int)const;
private:
	int size;
	int *Ptr;
};
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	int yourSize;
	cout<<"Enter a size for array integers1:";
	cin>>yourSize;
	Array integers1(yourSize);
	Array integers2;
	cout<<"\nsize of array integers 1 is:\n"<<integers1.getSize()
		<<"\nintegers1 after intialization:\n"<<integers1;
	cout<<"\nsize of array integers 2 is:\n"<<integers2.getSize()
		<<"\nintegers2 after intialization:\n"<<integers2;
	cout<<"\nEnter "<<integers1.getSize()+integers2.getSize()<<"integers!\n";
	cin>>integers1>>integers2;
	cout<<"\nAfter input the Arrays contaion:\nintegers1:\n"<<integers1
		<<"\nintegers2:\n"<<integers2;
	cout<<"\nEvaluating: integers1!=integers2"<<endl;
	if(integers1!=integers2)
		cout<<"\nintegers1 and integers 2 are not equal"<<endl;
	Array integers3=integers1;
	cout<<"size of array integers 3 is:"<<integers3.getSize()
		<<"\narray after initialization:\n"<<integers3;
	cout<<"\nAssigning integers 2 to integers 1:";
	integers1=integers2;
	cout<<"\nintegers1:\n"<<integers1
		<<"\nintegers2:\n"<<integers2;
	cout<<"\nEvaluating: integers1==integers2 :";
	if(integers1==integers2)
		cout<<"\nintegers1 and integers 2 are equal"<<endl;
	cout<<"\nintegers 1[5] is:"<<integers1[5]
	<<"\nAssigning 1000 to integers1[5]:";
	integers1[5]=1000;
	cout<<"\nintegers1:\n"<<integers1;
	cout<<"\n\nAttempting to assign 1000 to integers1[100]";
	integers1[100]=1000;
	return 0;
}

Array::Array(int arraySize)
{
	size=(arraySize>0)?arraySize:10;//validate size.
	Ptr=new int[size];
	for(int i=0;i<size;i++)
		Ptr[i]=0;
}
Array::Array(const Array &arrayToCopy)
	:size(arrayToCopy.size)
{
	Ptr=new int[size];
	for(int i=0;i<size;i++)
		Ptr[i]=arrayToCopy.Ptr[i];
}
Array::~Array()
{
	delete[]Ptr;
}
int Array::getSize()
{
	return size;
}
const Array &Array::operator=(const Array& right)
{
	if(this!=&right)
	{
		if(size!=right.size)
		{
			delete[] Ptr;
			size=right.size;
			Ptr=new int[size];
		}
		for(int i=0;i<size;i++)
			Ptr[i]=right.Ptr[i];
	}
	return *this;	
}
bool Array::operator==(const Array &right)const
{
	if(size!=right.size)
		return false;
	for(int i=0;i<size;i++)
		if(Ptr[i]!=right.Ptr[i])
			return false;
	return true;
}
int &Array::operator[](int subscript)
{
	if(subscript<0||subscript>=size)
	{
		cerr<<"\nERROR:subscript"<<subscript<<"out of range!"<<endl;
		exit(1);
	}
	return Ptr[subscript];
}
int Array::operator[](int subscript)const
{
	if(subscript<0||subscript>=size)
	{
		cerr<<"\nERROR:subscript"<<subscript<<"out of range!"<<endl;
		exit(1);
	}
	return Ptr[subscript];
}
istream &operator>>(istream& input,Array &a)
{
	for(int i=0;i<a.size;i++)
		input>>a.Ptr[i];
	return input;
}
ostream &operator<<(ostream &output,const Array &a)
{
	for(int i=0;i<a.size;i++)
	{
		output<<setw(12)<<a.Ptr[i];
	if((i+1)%4==0)
		output<<endl;
	}
	return output;
}
