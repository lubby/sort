/*
 * main.cpp
 *
 *  Created on: 2012-7-23
 *      Author: hp
 */


#include "sort.h"
int main() {
	int a[] = { 45, 67, 3, 2, 7, 8, 14 };
	Sort *sort1 = new Sort(a, sizeof(a) / sizeof(a[0]));
	Sort *sort2 = new Sort;
//	sort1->insertion_sort();
//	sort1->m_sort();
	sort1->q_sort();
	sort1->printarray();
//	sort2->insertion_sort();
	sort2->c_sort(20);
//	sort2->printarray();
	delete sort1;
	delete sort2;
	return 0;
}

