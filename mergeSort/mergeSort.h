#pragma once
#include "../commonFunc.h"

template<typename T1>
void merge(T1* arr,int low,int mid,int high, T1* tmp)
{
	int i, j, k;

	for (i= mid+1; i > low; i--) {
		tmp[i-1] = arr[i-1];
	}
	for (j = mid; j < high; j++) {
		tmp[high+mid-j] = arr[j+1];
	}

	for (k = low; k <= high; k++) {
		if (tmp[j] < tmp[i]) {
			arr[k] = tmp[j--];
		}
		else {
			arr[k] = tmp[i++];
		}
	}
}

//二路归并（递归实现）
template<typename T1>
void merge_sort(T1* arr, int low, int high,T1* tmp)
{
	if (low >= high)
		return;

	int mid = (low + high) / 2;
	merge_sort(arr, low, mid, tmp);		//左边有序
	merge_sort(arr, mid + 1, high, tmp);//右边有序
	merge(arr, low, mid, high, tmp);	//再将两个有序序列合并
	print(arr, 10);
}

//自底向上排序
template<typename T>
void mergesortBU(T* arr,int low,int high,T* tmp)
{
	int i, m;
	for (m = 1; m <= high - low;m=m+m) {
		for (i = low; i <= high - m; i += m + m) {
			merge(arr, i, i + m - 1, min(i+m+m-1,high), tmp);
		}
	}
}
