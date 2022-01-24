#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "SortableArray.cpp"

using namespace std;
const unsigned int LENGTH=256;

SortableArray dataRead(ifstream &);


int main()
{
	SortableArray arr(LENGTH);
	arr.ranFill();
	ofstream outdata("ece0301_merge_sort_results.txt");
	arr.print(outdata,false);
	arr.merge2();
	arr.print(outdata,true);
	outdata.close();
	
	return 0;
}


SortableArray dataRead(ifstream & indata)
{
	string line1;
	getline(indata,line1);
	if (line1.substr(0,9)!="LENGTH = ")
	{
		cout << "ERROR! Invalid input file header.";
		exit(0);
	}
	string numInStr=line1.substr(9);
	unsigned int num=(unsigned int)stoi(numInStr);
	SortableArray ret(num);
	ret.zeros();
	string lines;
	double * ptr=ret.getAddress();
	
	for (unsigned int i=0;i<num;i++)
	{
		getline(indata,lines);
		*(ptr+i)=stod(lines);
	}
	
	return ret;
	
}

