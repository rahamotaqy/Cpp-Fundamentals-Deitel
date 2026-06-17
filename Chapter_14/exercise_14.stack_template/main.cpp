// 14.stack template.test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#ifndef STACK_T
#define STACK_T
template<typename T>
class Stack
{
public:
	Stack(int=10);
	~Stack()
	{
		cout<<"destructor called.";
		delete[] stackPtr;
	}
	bool push(const T&);
	bool pop(T&);
	bool isEmpty()const
	{
		return top==-1;
	}
	bool isFull()const
	{
		return top==size-1;
	}
private:
	int size;
	T* stackPtr;
	int top;
};
#endif

// NOTE: _tmain/_TCHAR are Windows-specific. Use int main() for portability.
int _tmain(int argc, _TCHAR* argv[])
{
	Stack<double> doubleStack(5);
	double doubleValue=1.1;
	cout<<"pushing element onto double stack:\n";
	while(doubleStack.push(doubleValue))
		doubleValue+=1.1;
	cout<<"\nstack is full can not push "<<doubleValue<<"\n\npopping elements from double stack:\n";
	while(doubleStack.pop(doubleValue))
	{
	}
	cout<<"stack is empty .can not pop\n";
	Stack<int> intStack;
	int intValue=1;
	cout<<"pushing element onto double stack:\n";
	while(intStack.push(intValue))
		intValue++;
	cout<<"\nstack is full can not push "<<intValue<<"\n\npopping elements from int stack:\n";
	while(intStack.pop(intValue))
	{
	}
	cout<<"stack is empty .can not pop\n";
	return 0;
}
template<typename T>
// NOTE: Member initializer order should match declaration order (size, stackPtr, top).
Stack<T>::Stack(int s)
	:size(s>0?s:10),
	top(-1),
	stackPtr(new T[size])
{
}
template<typename T>
bool Stack<T>::push(const T& pushValue)
{
	if(!isFull())
	{
		stackPtr[++top]=pushValue;
		cout<<pushValue<<" .";
		return true;
	}
	return false;
}
template<typename T>
bool Stack<T>::pop(T& popValue)
{
	if(!isEmpty())
	{
		popValue=stackPtr[top--];
		cout<<popValue<<" ,";
		return true;
	}
	return false;
}