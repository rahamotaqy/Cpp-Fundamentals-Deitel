// 21.test listnode.cpp : Defines the entry point for the console application.
//listnode.h & list.h & listnode.cpp & list.cpp & another .. & main

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
template<typename NODETYPE>class List;
template<typename NODETYPE>
class ListNode{
	friend class List<NODETYPE>;//make list a friend.
public:
	ListNode(const NODETYPE&);
	NODETYPE getData()const;
private:
	NODETYPE data;
	ListNode<NODETYPE>* nextPtr;};

	template<typename NODETYPE>
	ListNode<NODETYPE>::ListNode(const NODETYPE& info)
		:data(info),nextPtr(0)
	{/*empty body*/};
	template<typename NODETYPE>
	NODETYPE ListNode<NODETYPE>::getData()const
	{return data;}

	template<typename NODETYPE>
	class List{
	public:
		List();
		~List();
		void insertAtFront(const NODETYPE&);
		void insertAtBack(const NODETYPE&);
		bool removeFromFront(NODETYPE&);
		bool removeFromBack(NODETYPE&);
		bool isEmpty()const;
		void print()const;
	private:
		ListNode<NODETYPE>* firstPtr;
		ListNode<NODETYPE>* lastPtr;
		ListNode<NODETYPE>* getNewNode(const NODETYPE&);};//utility function to allocate new node.

		template<typename NODETYPE>
		List<NODETYPE>::List()
			:firstPtr(0),lastPtr(0)
		{/*empty body*/}
		template<typename NODETYPE>
		List<NODETYPE>::~List(){
			if(!isEmpty()){//list in not empty
				cout<<"Destroying nodes...\n";
				ListNode<NODETYPE>* currentPtr=firstPtr;
				ListNode<NODETYPE>* tempPtr;
				while(currentPtr!=0){
					tempPtr=currentPtr;
					cout<<tempPtr->data<<'\n';
					currentPtr=currentPtr->nextPtr;
					delete tempPtr;}}
			cout<<"all nodes desroyed.\n\n";}//end list destructor
		template<typename NODETYPE>
		void List<NODETYPE>::insertAtFront(const NODETYPE& value){
			ListNode<NODETYPE>* newPtr=getNewNode(value);
			if(isEmpty())
				firstPtr=lastPtr=newPtr;
			else{newPtr->nextPtr=firstPtr;
			firstPtr=newPtr;}}
		template<typename NODETYPE>
		void List<NODETYPE>::insertAtBack(const NODETYPE& value){
			ListNode<NODETYPE>* newPtr=getNewNode(value);
			if(isEmpty())
				firstPtr=lastPtr=newPtr;
			else{lastPtr->nextPtr=newPtr;
			lastPtr=newPtr;}}
		template<typename NODETYPE>
		bool List<NODETYPE>::removeFromFront(NODETYPE& value){
			if(isEmpty())
				return false;//delete unsuccessfl.
			else{ListNode<NODETYPE>* tempPtr=firstPtr;
			if(firstPtr==lastPtr)
				firstPtr=lastPtr=0;
			else firstPtr=firstPtr->nextPtr;
			value=tempPtr->data;
			delete tempPtr;
			return true;/*delete successful*/}}//end function.
		template<typename NODETYPE>
		// NOTE: All code paths in this non-void function must return a value.
bool List<NODETYPE>::removeFromBack(NODETYPE& value){
			if(isEmpty())
				return false;//delete unsuccessfl.
			else{ListNode<NODETYPE>* tempPtr=lastPtr;
				if(firstPtr==lastPtr)
					firstPtr=lastPtr=0;
				else{ListNode<NODETYPE>* currentPtr=firstPtr;
					while(currentPtr->nextPtr!=lastPtr)
						currentPtr=currentPtr->nextPtr;
					lastPtr=currentPtr;
					currentPtr->nextPtr=0;
					value=tempPtr->data;
					delete tempPtr;
					return true;}}}//end function.
		template<typename NODETYPE>
		bool List<NODETYPE>::isEmpty()const
		{return firstPtr==0;}
		template<typename NODETYPE>
		ListNode<NODETYPE>* List<NODETYPE>::getNewNode(const NODETYPE& value)
		{return new ListNode<NODETYPE>(value);}
		template<typename NODETYPE>
		void List<NODETYPE>::print()const
		{if(isEmpty()){
		cout<<"the list is empty\n\n";
		return;}
		ListNode<NODETYPE>* currentPtr=firstPtr;
		cout<<"the list is:\n";
		while(currentPtr!=0){
			cout<<currentPtr->data<<' ';
			currentPtr=currentPtr->nextPtr;}//end while.
		cout<<"\n\n";}//end function

		// NOTE: instruction() is called inside a template function before it is declared.
//       Add a forward declaration: void instruction(); before this function.
template<typename T>
		void testList(List<T>& listObject,const string& typeName)
		{cout<<"testing a list of "<<typeName<<" values\n";
		instruction();
		int choice;
		T value;
		do{cout<<"?";
		cin>>choice;
		switch(choice){
		case 1://insert at beginning.
			cout<<"enter "<<typeName<<" :";
			cin>>value;
			listObject.insertAtFront(value);
			listObject.print();
			break;
		case 2://insert at end
			cout<<"enter "<<typeName<<" :";
			cin>>value;
			listObject.insertAtBack(value);
			listObject.print();
			break;
		case 3://remove from beginning
			if(listObject.removeFromFront(value))
				cout<<value<<"removes from list.\n";
			listObject.print();
			break;
		case 4://remove from end
			if(listObject.removeFromBack(value))
				cout<<value<<"removes from list.\n";
			listObject.print();
			break;
		}/*end switch*/}while(choice!=5);
		cout<<"End list test.\n\n";}//end function test list.
		void instruction()
		{cout<<"Enter one of the following:\n"
			<<"1 to insert at beginning of list\n"
			<<"2 to insert at end of list"
			<<"3 to delete from beginning of list\n"
			<<"4 to delete from end of list\n"
			<<"5 to end list proccessing";}

int _tmain(int argc, _TCHAR* argv[])
{//test list of int values
	List<int> integerList;
	testList(integerList,"integer");
	//test list of double values
	List<double> doubleList;
	testList(doubleList,"double");
	return 0;
}