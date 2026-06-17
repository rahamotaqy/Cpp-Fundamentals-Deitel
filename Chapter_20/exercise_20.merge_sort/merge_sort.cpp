#include<cstdlib>//for rand ,srand
#include<ctime>//for time
#include<iostream>//for cout,endl,
#include<vector>//for vector
#include<iomanip>//for setw
#include"merge_sort.hpp"
using namespace std;
MergeSort::MergeSort(int vectorSize){
	size=(vectorSize>0?vectorSize:0);
	srand(time(0));
	for(int i=0;i<size;i++)
		data.push_back(0+rand()%90);}
void MergeSort::sort(){
	sortSubVector(0,size-1);}
void MergeSort::sortSubVector(int low,int high){
	if(high-low>=1)//test base case: size of vector equal1.
	{int middle1=(high+low)/2;
	int middle2=middle1+1;

	cout<<"split:		";//output splitting
	displaySubVector(low,high);
	cout<<endl;
	displaySubVector(low,middle1);
	cout<<endl<<"		";
	displaySubVector(middle2,high);
	cout<<endl<<endl;
	//recursive call.
	sortSubVector(low,middle1);
	sortSubVector(middle2,high);
	merge(low,middle1,middle2,high);}}
void MergeSort::merge(int left,int middle1,int middle2,int right){
	int leftIndex=left;
	int rightIndex=middle2;
	int combinedIndex=left;
	vector<int>combined(size);
	//output merging.
	cout<<"merge:		";
	displaySubVector(left,middle1);
	cout<<endl<<"		";
	displaySubVector(middle2,right);
	cout<<endl<<endl;

	while(leftIndex<=middle1&&rightIndex<=right){
		if(data[leftIndex]<=data[rightIndex])
		combined[combinedIndex++]=data[leftIndex++];
		else //right index< left index
			combined[combinedIndex++]=data[rightIndex++];}
	if(leftIndex==middle2){//
		while(rightIndex<=right)
			combined[combinedIndex++]=data[rightIndex++];}
	else//when rightIndex=right+1
		while(leftIndex<=middle1)
			combined[combinedIndex++]=data[leftIndex++];
	for(int i=left;i<right;i++)
		data[i]=combined[i];
	cout<<"		";
	displaySubVector(left,right);
	cout<<endl<<endl;}
void MergeSort::displaySubVector(int low,int high)const{
	for(int i=0;i<low;i++)
		cout<<" ";
	for(int i=low;i<high;i++)
		cout<<" "<<data[i];}