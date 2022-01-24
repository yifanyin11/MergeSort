#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "SortableArray.h"

using namespace std;


SortableArray::SortableArray()
{
	entryNum=10;
	address=new double[entryNum];
	zeros();
}

SortableArray::SortableArray(unsigned int N)
{
	entryNum=N;
	address=new double[entryNum];
	zeros();
}

SortableArray::~SortableArray()
{
	delete address;
}

double * SortableArray::getAddress()
{
	return address;
}

unsigned int SortableArray::getNum()
{
	return entryNum;
}

void SortableArray::zeros()
{
	for (unsigned int i=0;i<entryNum;i++)
	{
		*(address+i)=0.0;
	}
}

void SortableArray::print(ofstream & outdata, bool sortedOrNot)
{
	if (sortedOrNot==false)
	{
		outdata << "ECE 0301 - Sorting Arrays\nUnsorted Array:\n";
		for (unsigned int i=0;i<entryNum;i++)
		{
			outdata << *(address+i) << endl;
		}
	}
	else
	{
		outdata << "Sorted Array:\n";
		for (unsigned int i=0;i<entryNum;i++)
		{
			outdata << *(address+i) << endl;
		}
	}
}


void SortableArray::merge(double *ptrPreArr,double *ptrPostArr,unsigned int begin, unsigned int mid, unsigned int end)
{
	double * incrPtr1=ptrPreArr+begin; //black
	double * incrPtr2=ptrPreArr+mid;//gray
	double * endPt1=ptrPreArr+mid;//red
	double * endPt2=ptrPreArr+end;//blue
	double * sortPtr=ptrPostArr+begin;//green
	
	//if both arrays contains unsorted entries
	while (incrPtr1<endPt1&&incrPtr2<endPt2)
	{
		if (*incrPtr1<*incrPtr2)
		{
			*sortPtr=*incrPtr1;
			incrPtr1++;
		}
		else
		{
			*sortPtr=*incrPtr2;
			incrPtr2++;
		}
		sortPtr++;
	}
	//if only the first sub array has unsorted entries
	while (incrPtr1<endPt1)
	{
		*sortPtr=*incrPtr1;
		sortPtr++;
		incrPtr1++;
	}
	//else
	while (incrPtr2<endPt2)
	{
		*sortPtr=*incrPtr2;
		sortPtr++;
		incrPtr2++;
	}
}

void SortableArray::split(double *ptrPreArr, double *ptrPostArr,unsigned int begin, unsigned int end)
{
	if (end==begin+1);
	else
	
	{
		unsigned int mid=(begin+end)/2;
		split(ptrPostArr,ptrPreArr,begin,mid);
		split(ptrPostArr,ptrPreArr,mid,end);
		merge(ptrPreArr,ptrPostArr,begin,mid,end);
	}
}

void SortableArray::merge2()
{
	double *ptr=getAddress();
	SortableArray arr(getNum());
	double *ptrW=arr.getAddress();
	for (unsigned int i=0;i<entryNum;i++)
	{
		*(ptrW+i)=*(ptr+i);
	}	
	split(ptrW,ptr,0,entryNum);
}

void SortableArray::ranFill()
{
	unsigned int seed=time(0);
	srand(seed);
	
	for (unsigned int i=0;i<entryNum;i++)
	{
		double rand_01 = static_cast<double>(rand()) / RAND_MAX;
		double rand_pm1 = 2*rand_01 - 1;
		*(getAddress()+i)=rand_pm1;
	}
	
	
}
