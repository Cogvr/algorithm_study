#pragma once
#include "../commonFunc.h"

#define PARENT(i) ((i)/2)
#define LEFT(i) (2*(i)+1)
#define RIGHT(i) (2*(i)+2)

template<typename T1>
void minHeapfiy(T1 A[],int len,int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int minIndex;
	if ((r < len) && (A[r] < A[i])){
		minIndex = r;
	}
	else {
		minIndex = i;
	}

	if ((l < len) && (A[l] < A[minIndex])){
		minIndex = l;
	}

	if (minIndex != i){
		swap(A[i],A[minIndex]);
		minHeapfiy(A,len,minIndex);
	}
}

template<typename T1>
void maxHeapfiy(T1 A[], int len, int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int maxIndex;
	if ((l < len) && (A[l] > A[i])) {
		maxIndex = l;
	}
	else {
		maxIndex = i;
	}

	if ((r < len) && (A[r] > A[maxIndex])) {
		maxIndex = r;
	}

	if (maxIndex != i) {
		swap(A[i], A[maxIndex]);
		maxHeapfiy(A, len, maxIndex);
	}
}

template<typename T1>
void buildMinHeap(T1 A[], int len)
{
	int beg = (len-1) / 2;
	for (int i = beg; i >= 0; --i) {
		minHeapfiy(A,len,i);
	}
}

template<typename T1>
void buildMaxHeap(T1 A[], int len)
{
	int beg = (len - 1) / 2;
	for (int i = beg; i >= 0; --i) {
		maxHeapfiy(A, len, i);
	}
}

template<typename T1>
void minHeapSort(T1 A[], int len)
{
	buildMinHeap(A,len);
	//print(A, len);
	int locLen = len;
	for (int i = locLen -1; i >= 0; --i)
	{
		std::cout << A[0] << std::endl;
		swap(A[0], A[i]);
		--len;
		minHeapfiy(A,len,0);
	}
}

template<typename T1>
void maxHeapSort(T1 A[], int len)
{
	buildMaxHeap(A, len);
	//print(A, len);
	int locLen = len;
	for (int i = locLen - 1; i >= 0; --i)
	{
		std::cout << A[0] << std::endl;
		swap(A[0], A[i]);
		--len;
		maxHeapfiy(A, len, 0);
	}
}