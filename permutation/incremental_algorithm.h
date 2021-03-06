/*************************************************************************
    > File Name: incremental_algorithm.h
    > Func: 
    > Created Time: 二 10/24 21:19:01 2017
 ************************************************************************/
#pragma once

#include "toolfunc.h"


uint64 generator_incremental_nolimit(int n)
{


	//permutation array
	PT *array = new PT[n];
#ifdef DIFF_WATCH
	uint64 *diff_hash_array = new uint64[n+1];
	memset(diff_hash_array, 0, sizeof(uint64)*(n+1));
	PT *array_bak = new PT[n];
	uint64 localcnt = 0;
	uint64 diff_cnt = 0;
	int flag = 0;
#endif
	//incremental carry number array
	PT *incre_array = new PT[n-1];
	memset(incre_array, 0, sizeof(PT)*(n-1));

	int i = 0, j = 0, k = 0, cnt = 0;

	do{
#ifdef DIFF_WATCH
		if(flag > 1)
		{
			//compare array and array_bak
			localcnt = 0;
			for(i = 0;i < n; i ++)
				if(array[i] != array_bak[i])
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
		memset(array, 0, sizeof(PT)*n);
		
		i = 0;
		while(!incre_array[i] && i < n-1) // incre_array[i] == 0
		{
			array[n-1-i] = n-i;
			i ++;
		}

		for(j = i; j < n-1; j++)
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
		for(k = n-1-i; k >= 0; k--)
		{
			if(!array[k])
			{
				array[k] = 1;
				break;
			}
		}
		//print_array(array, n);
		
	}while(increment(incre_array, n-1));


	delete [] incre_array;
	delete [] array;
#ifdef DIFF_WATCH
	for(i = 0;i < n;i ++)
		printf("%d:%lld ", i+1, diff_hash_array[i]);
	printf("\n");
	return diff_cnt;
#else
	return 0;
#endif
}



void generator_incremental(int n)
{
	//factoral
	uint64 *fac_array = new uint64[n];
	for(int i = 0; i < n; i ++)
		fac_array[i] = factoral(i+1);

	//permutation array
	PT *array = new PT[n];
	//the first permutation
	for(int i = 0;i < n;i ++)
		array[i] = i + 1;
	print_array(array, n);

	//incremental carry numnber
	PT *incre_array = new PT[n-1];
	uint64 remainder = 0;
	int cnt = 0;

	//traveral from 1! to n!-1, parted by factoral
	for(int i = 0; i < n-1; i ++)
	{
		//memset incre_array to 0
		memset(incre_array, 0, sizeof(PT)*(n-1));
		//traveral from i! to (i+1)!-1
		for(int index = fac_array[i]; index < fac_array[i+1]; index ++)
		{

			//initialize remainder to index 
			remainder = index;
			//calculate incre_array
			for(int j = i; j >= 0; j --)
			{
				incre_array[j] = remainder / fac_array[j];
				remainder = remainder - fac_array[j] * incre_array[j];
			}

			//transfer incre_array to array(permutation_array)
			for(int j = n-2; j > i; j --)
				array[j + 1] = j + 2;
			memset(array, 0, sizeof(PT)*(i+2));

			for(int j = i; j >= 0; j --)
			{
				cnt = 0;
				for(int k = i+1; k >= 0; k --)
				{
					if(cnt == incre_array[j])
					{
						while(array[k])
							k --;
						array[k] = j+2;
						break;
					}
					if(!array[k])
						cnt ++;
				}
			}
			for(int k = 0; k <= i+1; k++)
			{
				if(!array[k])
				{
					array[k] = 1;
					break;
				}
			}
			print_array(array, n);

		}
	}
	delete [] incre_array;
	delete [] array;

}
