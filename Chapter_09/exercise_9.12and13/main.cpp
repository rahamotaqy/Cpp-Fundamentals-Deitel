// 9.12.rectangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const int arraySize=8;
static bool code=1;
class Rectangle
{
public:
	Rectangle(double[]);
	void setPoint(double[]);
	void masahat();
	void mohit();
	void draw();
private:
	double p[arraySize];
	double tool,arz;
	bool squre(double,double);
	void toolAndArz();
	void reset();
	int sortArray(double*);
	void setFillCharacter();
	void setPerimeterCharacter();
};

// NOTE: _tmain/_TCHAR are Windows-specific. Use int main() for portability.
int _tmain(int argc, _TCHAR* argv[])
{
	double arrayOfPoints[8];
	int order=1;
	do{
		cout<<"plz give me 4 points of a mostatil!"<<endl;
	for(int i=0;i<8;i++)
		cin>>arrayOfPoints[i];
	Rectangle r1(arrayOfPoints);
	r1.masahat();
	r1.mohit();
	r1.draw();
	cout<<"enter 1 to start over and 2 to exit";
	cin>>order;
	}while(order==1);
	return 0;
}
Rectangle::Rectangle(double a[])
{
	reset();
	setPoint(a);
}
 void Rectangle::setPoint(double x[])
{
	double q[arraySize];
	for(int i=0;i<arraySize;i++)
	{
		q[i]=(x[i]<20&&x[i]>=0)?x[i]:20;
		if(q[i]==20)
		{
			cout<<"wrong points(not in range!)"<<endl;
			code=0;
			return ;
		}
	}
	const double f=2;
	if(sqrt(pow(q[0]-q[2],f)+pow(q[1]-q[3],f))==sqrt(pow(q[4]-q[6],f)+pow(q[5]-q[7],f)))
	{
		for(int y=0;y<arraySize;y++)
			p[y]=q[y];
	}
	else
		{
			cout<<"not mostatil!!!"<<endl;
			code=0;
		}
}
void Rectangle::reset()
{
	for(int i=0;i<arraySize;i++)
		p[i]=0;
	code=1;
}
// NOTE: This non-void function needs a default return value at the end.
//       Add: return false; after the last else block.
bool Rectangle::squre(double a,double b)
{
	const double f=2;
	if((b*sqrt(f))!=a)
	{
		cout<<"yes!mostatil"<<endl;
		return true;
	}
	else if((b*sqrt(f))==a)
		{
			cout<<"noooo!morabba!"<<endl;
			return false;
	}
}
void Rectangle::toolAndArz()
{
	double ghotr;
	const double f=2;
	double hold[3]={0};
	hold[0]=sqrt(pow(p[0]-p[2],f)+pow(p[1]-p[3],f));
	hold[1]=sqrt(pow(p[0]-p[4],f)+pow(p[1]-p[5],f));
	hold[2]=sqrt(pow(p[0]-p[6],f)+pow(p[1]-p[7],f));
	switch(sortArray(hold))
	{
	case 0:
		(hold[1]>hold[2])?tool=hold[1],arz=hold[2]:tool=hold[0],arz=hold[1];
		break;
	case 1:
		(hold[0]>hold[2])?tool=hold[0],arz=hold[2]:tool=hold[2],arz=hold[0];
		break;
	case 2:
		(hold[1]>hold[0])?tool=hold[1],arz=hold[0]:tool=hold[0],arz=hold[1];
		break;
	}
	squre(hold[sortArray(hold)],tool);
}
void Rectangle::masahat()
{
	if(code==1)
	{
	toolAndArz();
	cout<<"masahat:"<<fixed<<setprecision(2)<<tool*arz<<"."<<endl;
	}
}
void Rectangle::mohit()
{
	if(code==1)
	{
	cout<<"mohit:"<<fixed<<setprecision(2)<<(tool+arz)*2<<"."<<endl;
	}
}
int Rectangle::sortArray(double*x)
{
	int q=0;
	double h=*x;//hold[0]
	for(int i=0;i<3;i++)
	{
		if(x[i]>h)
		{
			h=x[i];
			q=i;
		}
	}
	return q;
}
void Rectangle::draw()
{
	if(code==1)
	{
	double x1=p[0];
	for(int count=0;count<8;count+=2)
		x1=min(x1,p[count]);
	double x2=p[0];
	for(int count=0;count<8;count+=2)
		x2=max(x2,p[count]);
	double y1=p[1];
	for(int count=1;count<8;count+=2)
		y1=min(y1,p[count]);
	double y2=p[1];
	for(int count=1;count<8;count+=2)
		y2=max(y2,p[count]);

	for(int j=0;j<25;j++)
	{
		for(int i=0;i<25;i++)
		{
			if(i>x1&&i<=x2&&j>y1&&j<=y2)
				setFillCharacter();
			else if((i==x1)&&(j>=y1)&&(j<=y2)||
				(i==x2+1)&&(j>=y1)&&(j<=y2+1)||
				(j==y1)&&(i>=x1)&&(i<=x2)||
				(j==y2+1)&&(i>=x1)&&(i<=x2+1))
				setPerimeterCharacter();
			else
				cout<<" ";
		}
		cout<<endl;
	}
	}
}
void Rectangle::setFillCharacter()
{
	cout<<"*";
}
void Rectangle::setPerimeterCharacter()
{
	cout<<"@";
}
//vaghti belakhare ok shod ba nale goftam yes!!!
//va midunam chon khaili kamaram dard mikone bayad fekram dorost kar nakarde bashe
//motmaeenan rahat tar az in bud!
//ghesmate dovvomesh rasman ba zaveye 10 daraje nesbat be ofogh nesheste budam!