// creat random access file with 100 blankrecord.cpp
#include "stdafx.h"
#include"../client_data.hpp"
#include<iostream>//for cerr,endl,ios
#include<fstream>//for ofstream
#include<cstdlib>////for exit
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	ofstream outCredit("creditFile.dat",ios::binary);
	if(!outCredit){
		cerr<<"file could not be opened to write."<<endl;
		exit(1);}
	ClientData blankClient;//create a sample blanket record
	for(int i=0;i<100;i++)
		outCredit.write(reinterpret_cast<const char*>(&blankClient),sizeof(ClientData));
	//in ghesmat 100 ta recorde khali ro minevise
	return 0;
}

