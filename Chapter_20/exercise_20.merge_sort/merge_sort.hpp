#include<vector>//for vector
using namespace std;
class MergeSort
{
public:
	MergeSort(int);
	void sort();
	void displayElemnts()const;
private:
	void displaySubVector(int,int)const;
	void sortSubVector(int,int);
	void merge(int,int,int,int);
	vector<int>data;
	int size;
};