#include <iostream>
#ifndef SORTABLEARRAY_H
#define SORTABLEARRAY_H

using namespace std;

class SortableArray
{
	private:
		double * address;
		unsigned int entryNum;
		void merge(double *,double *,unsigned int, unsigned int, unsigned int);
		void split(double *, double *,unsigned int, unsigned int);
	public:
		SortableArray();
		SortableArray(unsigned int);
		~SortableArray();
		double * getAddress();
		unsigned int getNum();
		void zeros();
		void print(ofstream &, bool);
		void merge2();
		void ranFill();
};

#endif
