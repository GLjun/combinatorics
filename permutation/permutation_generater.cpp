/*************************************************************************
    > File Name: permutation_generater.cpp
    > Func: 
    > Created Time: 六 10/21 10:28:41 2017
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

typedef unsigned short PT;
typedef unsigned long long uint64;

using namespace std;


void print_array(PT* array, int n)
{
	for(int i = 0;i < n;i ++)
		printf("%d ", array[i]);
	printf("\n");
}

void swap(PT* array, int i, int j)
{
	PT tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

uint64 factoral(int n)
{
	uint64 fac = 1;
	while(n) fac *= n--;
	return fac;
}

//add 1 to increment carry number array
bool increment(PT* incre_array,int n)
{
	PT radix = 2;// the lowst radix is 2
	int i = 0;
	for(i = n-1; i >= 0; i--)
	{
		incre_array[i] ++;
		if(incre_array[i] >= radix)
			incre_array[i] -= radix;
		else
			break;
		radix ++;
	}

	return i >= 0;
}

//add 1 to degressive carry number array
bool degress(PT* degre_array, int n)
{
	PT radix = n+1; // the lowst radix is n+1
	int i = 0;
	for(i = n-1; i >= 0; i--)
	{
		degre_array[i] ++;
		if(degre_array[i] >= radix)
			degre_array[i] -= radix;
		else
			break;
		radix --;
	}

	return i >= 0;
}
// library argorithm
#include "library_algorithm.h"
#include "incremental_algorithm.h"
#include "degressive_algorithm.h"
#include "neighbour_algorithm.h"

void test_algorithm()
{
	/*************************************************************
	 * generator_library 是字典序版本，支持任意长度的N
	 * generator_incremental_nolimit和generator_incremental 是递增进制版本，其中nolimit	版本直接对递增进制数组进行加1操作，因而支持任意序列长度N，而后者是先用uint64的数加1，然后计算出递增进制数，因而有上限
	 * generator_degressive_nolimit和generator_incremental 是递减进制版本，其中nolimit	版本直接对递减进制数组进行加1操作，因而支持任意序列长度N，而后者是先用uint64的数加1，然后计算出递减进制数，因而有上限
	 * generator_neighbour_nolimit和generator_neighbour 是邻位对换版本，其中nolimit 版本直接对递减进制数组进行加1操作，因而支持任意序列长度N，而后者是先用uint64的数加1，然后计算出递减进制数，因而有上限*/
	//generator_library(8);
	//generator_incremental(8);
	generator_incremental_nolimit(4);
	//generator_degressive(4);
	//generator_degressive_nolimit(15);
	//generator_neighbour(4);
	//generator_neighbour_nolimit(4);
}



int main(int argc, char** argv)
{
	test_algorithm();
	
	return 0;
}
