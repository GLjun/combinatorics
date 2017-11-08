/*************************************************************************
    > File Name: degressive_algorithm.h
    > Func: 
    > Created Time: 一 10/30 17:27:25 2017
 ************************************************************************/
#pragma once

#include "toolfunc.h"


uint64 generator_degressive_nolimit(int n)
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
	//degressive carry number array
	PT *degre_array = new PT[n-1];
	memset(degre_array, 0, sizeof(PT)*(n-1));


	int i = 0, j = 0, k = 0, cnt = 0;

	do{

#ifdef DIFF_WATCH
		if(flag > 1)
		{
			//compare array and array_bak;
			localcnt = 0;
			for(i = 0; i < n; i++)
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
		while(!degre_array[i] && i < n-1) 
			i ++;
		for(j = n-2; j >= i; j --)
		{
			cnt = 0;
			for(k = n-1; k >= 0; k--)
			{
				if(cnt == degre_array[j])
				{
					while(array[k])
						k --;
					array[k] = j + 2;
					break;
				}
				if(!array[k])
					cnt ++;
			}
		}
		k = n-1;
		for(j = i-1; j >= 0; j--)
		{
			while(array[k])
				k --;
			array[k--] = j + 2;

		}
		k = 0;
		while(array[k])
			k ++;
		array[k] = 1;
		//print_array(array, n);
	}while(degress(degre_array, n-1));

	delete [] array;
	delete [] degre_array;

#ifdef DIFF_WATCH
	for(i = 0;i < n;i ++)
		printf("%d:%lld ", i+1, diff_hash_array[i]);
	printf("\n");
	return diff_cnt;
#else
	return 0;
#endif
}

void generator_degressive(int n)
{
	
	uint64 fac_n = factoral(n);
	//permutation_array
	PT *array = new PT[n];
	//degressive carry number
	PT *degre_array = new PT[n-1];
	uint64 quotient = 0, tmp = 0;
	int cnt = 0, i = 0,j = 0, k = 0,  mod = 0;
	
	//traveral from 0 to n!-1
	for(int index = 0; index < fac_n; index ++)
	{
		//calculate degressive carry number
		quotient = index;
		i = n-2;
		mod = n;
		while(quotient)
		{
			tmp = quotient / mod;
			degre_array[i] = quotient - tmp * mod;
			quotient = tmp;
			mod --;
			i --;
		}
		//transfer degre_array to array(permutation array)
		memset(array, 0, sizeof(PT)*n);
		for(j = n-2; j > i; j --)
		{
			cnt = 0;
			for(k = n-1; k >= 0; k--)
			{
				if(cnt == degre_array[j])
				{
					while(array[k])
						k --;
					array[k] = j + 2;
					break;
				}
				if(!array[k])
					cnt ++;
			}
		}

		k = n-1;
		for(j = i; j >= 0; j--)
		{
			while(array[k])
				k --;
			array[k--] = j + 2;
		}
		for(j = 0; j < n; j++)
		{
			if(!array[j])
			{
				array[j] = 1;
				break;
			}
		}
		print_array(array, n);
		
	}

	delete [] degre_array;
	delete [] array;
}
