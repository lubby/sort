//============================================================================
// Name        : sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Sort in C++, Ansi-style
//============================================================================

#include "sort.h"
using namespace std;
int Sort::s[] = { 3, 2, 5, 4, 7, 6, 9, 8, 1, 0, 15, 11, 13, 14, 12 };
Sort::Sort(int a[], int length) :
		l(length) {
	array = new int[length];
	for (int i = 0; i < l; i++)
		array[i] = a[i];
}
Sort::~Sort() {
	delete[] array;
	delete[] carray;
}
int Sort::get_length() {
	return l;
}
int Sort::printarray() {
	if (!this->array) {
		cout << "error!" << endl;
		return -1;
	} else {
		for (int i = 0; i < this->l; i++) {
			cout << this->array[i] << " ";
		}
		cout << endl;
		return 0;
	}

}
void Sort::insertion_sort() {
	for (int j = 1; j < l; j++) {
		int i, key;
		key = array[j];
		i = j - 1;
		while (i >= 0 && array[i] > key) {
			array[i + 1] = array[i];
			i--;
		}
		array[i + 1] = key;
	}
}
void Sort::m_sort() {
	Sort::merge_sort(this->array, 0, this->l - 1);
}
void Sort::merge_sort(int a[], int p, int r) {
	int q;
//	cout << "p: " << p << " r: " << r << endl;
	if (p < r) {
		q = (p + r) / 2;
		this->merge_sort(a, p, q);
		this->merge_sort(a, q + 1, r);

		this->merge(a, p, q, r);
	}
}
void Sort::merge(int a[], int p, int q, int r) {

	if (p < r) {
		int *e1 = new int[q - p + 1 + 1];
		for (int i = 0; i < q - p + 1; i++) {
			e1[i] = a[p + i];
		}
		int *e2 = new int[r - q + 1];
		for (int j = 0; j < r - q; j++) {
			e2[j] = a[q + 1 + j];
		}
		e1[q - p + 1] = INT_MAX;
		e2[r - q] = INT_MAX;
		int d1 = 0;
		int d2 = 0;
		for (int k = p; k <= r; k++) {
			if (e1[d1] <= e2[d2]) {
				a[k] = e1[d1];
				d1++;
			} else {
				a[k] = e2[d2];
				d2++;
			}
		}
		delete e1;
		delete e2;
	}
}
void Sort::q_sort() {
	this->quick_sort(this->array, 0, this->l - 1);
}
void Sort::quick_sort(int a[], int p, int r) {
	int q;
	if (p < r) {
		q = this->partion(a, p, r);
//		cout << q << " " << endl;
		this->quick_sort(a, p, q - 1);
		this->quick_sort(a, q + 1, r);
	}
}
int Sort::partion(int a[], int p, int r) {
	int j;
	j = p - 1;
	for (int i = p; i < r; i++) {
		if (a[i] <= a[r]) {
			j++;
			this->swap(&a[j], &a[i]);
		}
	}
	this->swap(&a[j + 1], &a[r]);
	return j + 1;
}
void Sort::swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
void Sort::c_sort(int k) {
	this->counting_sort(this->array, this->l, k);
}
void Sort::counting_sort(int a[], int l, int k) {
	this->carray = new int[k];
	int *b = new int[l];
	for (int i = 0; i < k; i++)
		this->carray[i] = 0;
	for (int i = 0; i < l; i++)
		this->carray[a[i]]++;
	for (int i = 1; i < k; i++)
		this->carray[i] += this->carray[i - 1];
	for (int i = 0; i < k; i++)
		cout << this->carray[i] << " ";
	cout << endl;
	for (int i = 0; i < l; i++) {
		b[(this->carray[a[i]]) - 1] = a[i];
		this->carray[a[i]]--;
	}
	for (int i = 0; i < l; i++)
		cout << b[i] << " ";
	cout << endl;
	delete[] b;
}
