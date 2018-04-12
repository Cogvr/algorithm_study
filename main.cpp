#include "qsort/qsort.h"
#include "selectSort/heapSort.h"
#include "mergeSort/mergeSort.h"

int main()
{
	int A[10] = { 100,89,50,66,32,24,72,8,13,34 };
	//qsort(A, 0, 9);
	//maxHeapSort(A,10);
	int* p = new int[10];
	//merge_sort(A,0,9,p);
	mergesortBU(A, 0, 9,p);
	print(A, 10);
	return 0;
}