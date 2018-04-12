#pragma once
#include <iostream>

#define min(A,B) ((A)<(B)) ? (A) : (B)

void print(int Arr[], int num)
{
	for (int i = 0; i < num; ++i)
	{
		std::cout << Arr[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T1>
void swap(T1& lhs, T1& rhs)
{
	T1 temp = lhs;
	lhs = rhs;
	rhs = temp;
}