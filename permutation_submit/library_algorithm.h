/*************************************************************************
    > File Name: library_algorithm.h
    > Func: 
    > Created Time: 二 10/24 21:05:56 2017
 ************************************************************************/
#pragma once

#include "toolfunc.h"


void reverse(PT* array, int start, int end)
{
	PT tmp = 0;
	for(int i = start, j = end; i < j;i ++, j--)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}


bool caculate_lib_next_permutation(PT* array, int n)
{
	bool hasReversePair = false;
	for(int i = n-2; i >= 0; i --)
	{
		if(array[i] < array[i+1])
		{
			hasReversePair = true;
			PT switch_index = i+1;
			for(int j = i+2; j < n && array[j] > array[i]; j++)
				switch_index = j;
			swap(array, i, switch_index);
			reverse(array, i+1, n-1);
			break;
		}
	}
	return hasReversePair;
}

void generator_library(int n)
{
	if(n < 1)
		printf("error input, %d\n", n);
	
	//permutation array
	PT* array = new PT[n];		
	for(int i = 0;i < n; i++)
		array[i] = i + 1;
	//print the first permutation
#ifdef ARRAY_PRINT
	print_array(array, n);
#endif

	//=========counter
	int cnt = 0;
	while(caculate_lib_next_permutation(array, n))
	{
#ifdef ARRAY_PRINT
		print_array(array, n);
#endif
	}
	delete [] array;
}
