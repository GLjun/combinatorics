/*************************************************************************
    > File Name: swap_incremental_algorithm.h
    > Func: 
    > Created Time: 一 11/ 6 13:05:01 2017
 ************************************************************************/
#pragma once

#include "toolfunc.h"

uint64 generator_swap_incremental_nolimit(int n)
{
	uint64 *diff_hash_array = new uint64[n+1];
	memset(diff_hash_array, 0, sizeof(uint64)*(n+1));
	uint64 localcnt = 0;
	
	uint64 diff_cnt = 0;
	int flag = 0;
	//permutation_array
	PT *array = new PT[n];
	PT *array_bak = new PT[n];
	//incrmental carry number array
	PT *incre_array = new PT[n-2]; // length is n - 2, not n-1
	memset(incre_array, 0, sizeof(PT)*(n-2));
	
	int i = 0, j = 0, k = 0, cnt = 0;
	PT tmp = 0;

	//initialize array to 1,2,3,4……n
	for(int i = 0; i < n; i ++)
		array[i] = i + 1;
	//print_array(array, n);

	while(true)
	{
		if(flag > 1)
		{
			//compare aray and array_bak
			localcnt = 0;
			for(k = 0; k < n; k++ )
				if(array[k] != array_bak[k])
				{
					diff_cnt ++;
					localcnt ++;
				}
			diff_hash_array[localcnt-1] ++;
		}
		else 
			flag ++;
		memcpy(array_bak, array, sizeof(PT)*n);
		if(array[n-1] != 1)
		{
			k = 0;
			while(array[k] != 1)
				k ++;
			array[k] = array[k+1];
			array[k+1] = 1;
		}
		else
		{
			if(!increment(incre_array, n-2))
				break;
			memset(array, 0, sizeof(PT)*n);
			i = 0;
			while(!incre_array[i]) // incre_array[i] == 0
			{
				array[n-1-i] = n-i;
				i ++;
			}

			for(j = i; j < n-2; j++)
			{
				cnt = 0;
				for(k = n-1-i; k >= 0; k --)
				{
					if(cnt == incre_array[j])
					{
						while(array[k])
							k --;
						array[k] = n - j;
						break;
					}
					if(!array[k])
						cnt ++;
				}
			}

			for(k = n-1-i; k >= 1; k--)
			{
				if(!array[k])
				{
					array[k] = 2;
					array[0] = 1;
					break;
				}
			}

		}
		//print_array(array, n);
	}
	delete [] incre_array;
	delete [] array;
	for(int i = 0;i < n;i ++)
		printf("%d:%lld ", i+1, diff_hash_array[i]);
	printf("\n");

	return diff_cnt;

}
