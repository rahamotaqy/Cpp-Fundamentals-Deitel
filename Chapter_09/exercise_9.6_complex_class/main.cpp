// 9.6.cpp : Defines the entry point for the console application.
//
//if we assume that the book means adding two objects(initialized) bye adding two rational number:
/*nemitunam ham surato makhrajo private elam konam(ke yani natunam static elam
konam va sarasari initial konam va ham moteghayyere int bedam barashun.vase hamin arraye dorost kardam*/
//estefade az lable khaili bade?khaili mamnooe?!
#include "stdafx.h"
#include<iostream>
using std::cout;
using std::endl;
using std::fixed;
#include<iomanip>
using std::setprecision;

static int count=0;
static int numerator[10]={0};
static int denumerator[10]={0};
class Rational
{
private:
	void setRational(int a,int b)
	{
		again:
		if(count<10){
		numerator[count]=a/bmm(a,b);
		denumerator[count]=b/bmm(a,b);
		count++;}
		else{count=0;
			goto again;}
	}
	int bmm(int a,int b)
	{
		int bigger;
		int smaller;
		bigger=(a>b)?a:b;
		smaller=(a<b)?a:b;
		int hold=bigger%smaller;
		while(hold!=0)
		{
			bigger=smaller;
			smaller=hold;
			hold=bigger%smaller;
		}
	return smaller;
	}
	public:
	Rational(int surat=1,int makhraj=1)
	{
		setRational(surat,makhraj);
	}
	void sum()
	{
		int s1,s2;
		if(count>1)
		{
			s1=numerator[count-2]*denumerator[count-1]+numerator[count-1]*denumerator[count-2];
			s2=denumerator[count-2]*denumerator[count-1];
			s1/=bmm(s1,s2);
			s2/=bmm(s1,s2);
			cout<<"\nthe result of "<<numerator[count-1]
				<<"/"<<denumerator[count-1]<<"+"<<numerator[count-2]
				<<"/"<<denumerator[count-2]<<"is:\n"<<s1<<"/"<<s2<<endl;
		}
		else {s1=numerator[count-1];
		s2=denumerator[count-1];}
	}
	void tafrigh()
	{
		int s1,s2;
		if(count>1)
		{
			s1=numerator[count-2]*denumerator[count-1]-numerator[count-1]*denumerator[count-2];
			s2=denumerator[count-2]*denumerator[count-1];
			s1/=bmm(s1,s2);
			s2/=bmm(s1,s2);
			cout<<"\nthe result of "<<numerator[count-2]<<"/"<<denumerator[count-2]<<"-"
				<<numerator[count-1]<<"/"<<denumerator[count-1]<<"is:\n"<<s1<<"/"<<s2<<endl;
		}
	}
	void zarb()
	{
		int s1,s2;
		if(count>1)
		{
			s1=numerator[count-1]*numerator[count-2];
			s2=denumerator[count-1]*denumerator[count-2];
			s1/=bmm(s1,s2);
			s2/=bmm(s1,s2);
			cout<<"the result of :\n "<<numerator[count-1]<<"/"<<denumerator[count-1]
			<<" * "<<numerator[count-2]<<"/"<<denumerator[count-2]<<" = "<<s1
			<<"/"<<s2<<"."<<endl;
		}
	}
	void divide()
	{
		if(count>1)
		{
			int s1=numerator[count-1]*denumerator[count-2];
			int s2=denumerator[count-1]*numerator[count-2];
			s1/=bmm(s1,s2);
			s2/=bmm(s1,s2);
			cout<<"the result of :\n "<<numerator[count-1]<<"/"<<denumerator[count-1]
			<<" / "<<numerator[count-2]<<"/"<<denumerator[count-2]<<" = "<<s1
			<<"/"<<s2<<"."<<endl;
		}
	}
	void decimalFormatPrint()
	{
		double s=static_cast<double>(numerator[count-1])/denumerator[count-1];
		cout<<"\n\nthe decimal format is:"<<fixed<<setprecision(4)<<s<<endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Rational r1(33,3);
	r1.sum();
	Rational r2(21,9);
	r2.sum();
	r2.tafrigh();
	Rational r3(60,45);
	r3.divide();
	r3.zarb();
	r3.decimalFormatPrint();

	return 0;
}