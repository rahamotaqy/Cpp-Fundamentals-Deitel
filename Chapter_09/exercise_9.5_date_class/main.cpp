// 9.5.cpp : Defines the entry point for the console application.
//
//age nakhaiim tak tak real va imag ro begirim nemidunam chetori bayad az ham tashkhiseshun bedam!!!:(
#include "stdafx.h"
#include<iostream>
using namespace std;
#include<iomanip>
#include<string>

	static double realPart=0;
	static double imaginaryPart=0;
	static double exRealPart=0;
	static double exImaginaryPart=0;
class Complex
{
public:
	Complex(double r=0,double i=0)
	{
		setComplex(r,i);
	}
	void printComplex()
	{
		cout<<"("<<realPart<<" + "
			<<imaginaryPart<<"i)"<<endl;
	}
	void sumComplex()
	{
		cout<<"the result:\n("<<exRealPart<<","<<exImaginaryPart<<"i)+("<<realPart<<","<<imaginaryPart<<"i)=";
		realPart=realPart+exRealPart;
		imaginaryPart=imaginaryPart+exImaginaryPart;
		
	}
	void resetComplex()
	{
		setComplex(0,0);
	}
	/*void getComplex()
	{
		cout<<"plz enter two complex number:\n";
		double i1,i2,i3,i4;
		cin>>i1;
		cout<<"+";
		cin>>i2;
		cout<<"i"<<"\n";
		cin>>i3;
		cout<<"+";
		cin>>i4;
		cout<<"i";
		setComplex(i1,i2);
		setComplex(i3,i4);
	}*/
private:

	//utility function?!
	void setComplex(double a,double b)
	{
		exRealPart=realPart;
		realPart=a;
		exImaginaryPart=imaginaryPart;
		imaginaryPart=b;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Complex x;
	x.printComplex();
	//x.getComplex();
	Complex y(3.2,4.7);
	y.printComplex();
	Complex z(0,0.3);
	z.printComplex();
	z.sumComplex();
	z.printComplex();
	return 0;
}
//moshkele modele gereftane complex az karbare! nabayad inghad sade bashe!

