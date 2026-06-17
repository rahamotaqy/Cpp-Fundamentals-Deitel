// 13.employee.test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<typeinfo>
using namespace std;
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee
{
public:
	Employee(const string&,const string&,const string&);
	virtual ~Employee();
	void setFirstName(const string&);
	string getFirstName()const;
	void setLastName(const string&);
	string getLastName()const;
	void setSocialSecurityNumber(const string&);
	string getSocialSecurityNumber()const;

	virtual void print()const;
	virtual double earning()const=0;
private:
	string firstName;
	string lastName;
	string socialSecurityNumber;
};
#endif
class SalariedEmployee:public Employee
{
public:
	SalariedEmployee(const string&,const string&,const string&,double);
	~SalariedEmployee();
	void setWeeklySalary(double);
	double getWeeklySalary()const;
	virtual double earning()const;
	virtual void print()const;
private:
	double weeklySalary;
};
class ComissionEmployee:public Employee
{
public:
	ComissionEmployee(const string&,const string&,const string&,int,double);
	~ComissionEmployee();
	void setComissionRate(double);
	double getComissionRate()const;
	void setGrossSale(int);
	double getGrossSale()const;
	virtual double earning()const;
	virtual void print()const;
private:
	int grossSale;
	double comissionRate;
};
class BasePluseComissionEmployee:public ComissionEmployee
{
public:
	BasePluseComissionEmployee(const string&,const string&,const string&,double,double,int);
	~BasePluseComissionEmployee();
	void setBaseSalary(double);
	double getBaseSalary()const;
	virtual double earniing()const;
	virtual void print()const;
private:
	int baseSalary;
};
class HourlyEmployee:public Employee
{
public:
	HourlyEmployee(const string&,const string&,const string&,double,double);
	~HourlyEmployee();
	void setWage(double);
	double getWage()const;
	void setHours(double);
	double getHours()const;
	virtual double earning()const;
	virtual void print()const;
private:
	double wage;
	double hours;
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<fixed<<setprecision(2);
	vector<Employee*>employees(4);
	employees[0]=new ComissionEmployee("zahra","mottaghi","12342-2",289,6.8);
	employees[1]=new BasePluseComissionEmployee("ahmad","rasekh","223-876",300,4.3,3000);
	employees[2]=new HourlyEmployee("mohammad","moqadam","335-66",58.8,45.6);
	employees[3]=new SalariedEmployee("peyman","musavi","223-44",2223.2);
	for(size_t i=0;i<employees.size();i++)
	{
		employees[i]->print();
		cout<<endl;
		BasePluseComissionEmployee* derivedPtr=dynamic_cast<BasePluseComissionEmployee*>(employees[i]);
		if(derivedPtr!=0)
		{
			double oldBaseSalary=derivedPtr->getBaseSalary();
			cout<<"\nold base salary:$"<<oldBaseSalary<<endl;
			derivedPtr->setBaseSalary(1.1*oldBaseSalary);
			cout<<"new base salary with 10% increase is:$"<<derivedPtr->getBaseSalary()<<endl;
		}
		cout<<"earned:$"<<employees[i]->earning()<<"\n\n";
	}
		for(size_t j=0;j<employees.size();j++)
		{
			cout<<"deleting object of "<<typeid(*employees[j]).name()<<endl;
			delete employees[j];
		}
	return 0;
}
Employee::Employee(const string& first,const string& last,const string& ssn)
	:firstName(first),lastName(last),socialSecurityNumber(ssn)
{
	cout<<"Employee constructor called."<<endl;
}
Employee::~Employee()
{
	cout<<"Employee destructor called."<<endl;
}
void Employee::print()const
{
	cout<<getFirstName()<<' '<<getLastName()<<"\nsocial security number:"
		<<getSocialSecurityNumber()<<endl;
}
void Employee::setFirstName(const string& first)
{
	firstName=first;
}
string Employee::getFirstName()const
{
	return firstName;
}
void Employee::setLastName(const string& last)
{
	lastName=last;
}
string Employee::getLastName()const
{
	return lastName;
}
void Employee::setSocialSecurityNumber(const string& ssn)
{
	socialSecurityNumber=ssn;
}
string Employee::getSocialSecurityNumber()const
{
	return socialSecurityNumber;
}
SalariedEmployee::SalariedEmployee(const string& first,const string& last,const string& ssn,double ws)
	:Employee(first,last,ssn)
{
	setWeeklySalary(ws);
	cout<<"Salaried Employee constructor called."<<endl;
}
SalariedEmployee::~SalariedEmployee()
{
	cout<<"Salaried Employee destructor called."<<endl;
}
double SalariedEmployee::earning()const
{
	return getWeeklySalary();
}
void SalariedEmployee::print()const
{
	cout<<"salaried employee:\n";
	Employee::print();
	cout<<"weekly salary:"<<getWeeklySalary()<<endl;
}
double SalariedEmployee::getWeeklySalary()const
{
	return weeklySalary;
}
void SalariedEmployee::setWeeklySalary(double ws)
{
	weeklySalary=ws;
}
HourlyEmployee::HourlyEmployee(const string& first,const string& last,const string& ssn,double h,double w)
	:Employee(first,last,ssn)
{
	setWage(w);
	setHours(h);
	cout<<"hourlyEmployee constructor called."<<endl;
}
HourlyEmployee::~HourlyEmployee()
{
	cout<<"HourlyEmployee destructor called."<<endl;
}
void HourlyEmployee::setWage(double ww)
{
	wage=(ww<0?0:ww);
}
double HourlyEmployee::getWage()const
{
	return wage;
}
void HourlyEmployee::setHours(double hh)
{
	hours=(hh<0?0:hh);
}
double HourlyEmployee::getHours()const
{
	return hours;
}
double HourlyEmployee::earning()const
{
	if(hours<=40)
		return wage*hours;
	else 
		return (40*hours)+((hours-40)*wage*1.5);
}
void HourlyEmployee::print()const
{
	cout<<"hourle employee:";
	Employee::print();
	cout<<"hourle wage:"<<getWage()<<"\nhours worked:"<<getHours()<<endl;
}
ComissionEmployee::ComissionEmployee(const string& first,const string& last,const string& ssn,int gs,double cr)
	:Employee(first,last,ssn)
{
	setGrossSale(gs);
	setComissionRate(cr);
	cout<<"ComissionEmployee constructor called."<<endl;
}
ComissionEmployee::~ComissionEmployee()
{
	cout<<"ComissionEmployee destructor called."<<endl;
}
void ComissionEmployee::setComissionRate(double cr)
{
	comissionRate=cr;
}
double ComissionEmployee::getComissionRate()const
{
	return comissionRate;
}
void ComissionEmployee::setGrossSale(int gs)
{
	grossSale=gs;
}
double ComissionEmployee::getGrossSale()const
{
	return grossSale;
}
double ComissionEmployee::earning()const
{
	return getComissionRate()*getGrossSale();
}
void ComissionEmployee::print()const
{
	cout<<"ComissionEmployee:";
	Employee::print();
	cout<<"gross sale:"<<getGrossSale()<<"comissionRate:"<<getComissionRate()<<endl;
}
BasePluseComissionEmployee::BasePluseComissionEmployee(const string& first,const string& last,const string& ssn,double bs,double cr,int gs)
	:ComissionEmployee(first,last,ssn,gs,cr)
{
	setBaseSalary(bs);
	cout<<"BasePluseComissionEmployee constructor called."<<endl;
}
BasePluseComissionEmployee::~BasePluseComissionEmployee()
{
	cout<<"BasePluseComissionEmployee destructor called."<<endl;
}
void BasePluseComissionEmployee::setBaseSalary(double bs)
{
	baseSalary=(bs<0?0.0:bs);
}
double BasePluseComissionEmployee::getBaseSalary()const
{
	return baseSalary;
}
double BasePluseComissionEmployee::earniing()const
{
	return getBaseSalary()+ComissionEmployee::earning();
}
void BasePluseComissionEmployee::print()const
{
	cout<<"base salaried ";
	ComissionEmployee::print();
	cout<<"\nbase salary:"<<getBaseSalary()<<endl;
}