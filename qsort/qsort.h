#pragma once
#include "../commonFunc.h"

template<typename T1>
int partition(T1 A[],int p,int r)
{
	T1 x = A[r];
	int i = p-1;
	for(int j = p;j < r;++j){
		if(A[j] <= x){
			++i;
			swap(A[i], A[j]);
		}
	}

	swap(A[i+1],A[r]);
	return i + 1;
}

template<typename T1>
void qsort(T1 A[],int p,int r)
{	
	if(p < r){
		int q = partition(A,p,r);
		qsort(A,p,q-1);
		qsort(A,q,r);
	}
}

