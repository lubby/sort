/*
 * sort.h
 *
 *  Created on: 2012-7-23
 *      Author: hp
 */

#ifndef SORT_H_
#define SORT_H_
#include <iostream>
class Sort {
private:
	int *array;
	int *carray;
	int l;
	static int s[];
	void merge(int a[], int p, int q, int r);
	void merge_sort(int a[], int p, int r);
	int partion(int a[], int p, int r);
	void quick_sort(int a[], int p, int r);
	void counting_sort(int a[], int l, int k);
public:
	Sort(int a[] = s, int length = 15);
	~Sort();
	int get_length();
	int printarray();
	void insertion_sort();
	void m_sort();
	void q_sort();
	void swap(int *a, int*b);
	void c_sort(int k);
};

#endif /* SORT_H_ */
