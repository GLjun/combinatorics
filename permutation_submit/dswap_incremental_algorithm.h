/*************************************************************************
    > File Name: dswap_incremental_algorithm.h
    > Func: 
    > Created Time: 二 11/ 7 16:47:47 2017
 ************************************************************************/

#pragma once

#include "toolfunc.h"

uint64 generator_dswap_incremental_nolimit(int n)
{
	uint64 *diff_hash_array = new uint64[n+1];
	memset(diff_hash_array, 0, sizeof(uint64)*(n+1));
	
	//permutation_array
	PT *array = new PT[n];
#ifdef DIFF_WATCH
	PT *array_bak = new PT[n];
	uint64 localcnt = 0;
	uint64 diff_cnt = 0;
	int flag = 0;
#endif
	//incrmental carry number array
	PT *incre_array = new PT[n-2]; // length is n - 2, not n-1
	memset(incre_array, 0, sizeof(PT)*(n-2));
	
	int i = 0, j = 0, k = 0, cnt = 0, offset = 0;
	PT tmp = 0;

	//initialize array to 1,2,3,4……n
	for(int i = 0; i < n; i ++)
		array[i] = i + 1;
#ifdef ARRAY_PRINT
	print_array(array, n);
#endif

	while(true)
	{
#ifdef DIFF_WATCH
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
#endif
		if((array[0] != 1 && incre_array[n-3] == 1) || ( array[n-1] != 1 && incre_array[n-3] == 0 ) )
		{
			k = 0;
			while(array[k] != 1)
				k ++;
			if(incre_array[n-3] == 0)
			{
				array[k] = array[k+1];
				array[k+1] = 1;
			}
			else
			{
				array[k] = array[k-1];
				array[k-1] = 1;
			}
		}
		else
		{
			if(!increment(incre_array, n-2))
				break;
			offset = incre_array[n-3];
			memset(array, 0, sizeof(PT)*n);
			i = 0;
			while(!incre_array[i]) // incre_array[i] == 0
			{
				array[n-1-i-offset] = n-i;
				i ++;
			}

			for(j = i; j < n-2; j++)
			{
				cnt = 0;
				for(k = n-1-i-offset; k >= 0; k --)
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

			for(k = n-1-i-offset; k >= 1-offset; k--)
			{
				if(!array[k])
				{
					array[k] = 2;
					array[offset*(n-1)] = 1;
					break;
				}
			}

		}
#ifdef ARRAY_PRINT
		print_array(array, n);
#endif
	}
	delete [] incre_array;
	delete [] array;
#ifdef DIFF_WATCH
	for(int i = 0;i < n;i ++)
		printf("%d:%lld ", i+1, diff_hash_array[i]);
	printf("\n");
	return diff_cnt;
#else
	return 0;
#endif

}

