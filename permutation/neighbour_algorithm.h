/*************************************************************************
    > File Name: neighbour_algorithm.h
    > Func: 
    > Created Time: 一 10/30 19:28:40 2017
 ************************************************************************/
#pragma once

#include "toolfunc.h"

void generator_neighbour_nolimit(int n)
{
	//permutation array
	PT *array = new PT[n];
	//degressive carry number array
	PT *degre_array_with_offset = new PT[n+1]; // from -2, -1, 0, 1....n
	memset(degre_array_with_offset, 0, sizeof(PT)*(n+1));
	PT *degre_array = degre_array_with_offset + 2;
	int i = 0, j = 0, k = 0, cnt = 0, isOdd = 0;

	do {
		memset(array, 0, sizeof(PT)*n);
		
		i = 0;
		while(!degre_array[i] && i < n-1)
			i ++;
		for(j = n-2; j >= i; j--)
		{
			if(j & 0x1)
				isOdd = degre_array[j-1] & 0x1;
			else
				isOdd = (degre_array[j-1] + degre_array[j-2]) & 0x1;
			if(isOdd) // equals to (j + 2) % 2, odd means right direction
			{
				cnt = 0;
				for(k = 0; k < n; k ++)
				{
					if(cnt == degre_array[j])
					{
						while(array[k])
							k ++;
						array[k] = j + 2;
						break;
					}
					if(!array[k])
						cnt ++;
				}
			}
			else // even means left direction 
			{
				cnt = 0;
				for(k = n-1; k >= 0; k --)
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
		}
		k = n-1;
		// degre_array's value of index from 0 to i-1 equals to zero, so the direction is always left
		for(j = i-1; j >= 0; j --)
		{
			while(array[k])
				k --;
			array[k--] = j+2;
		}
		k = n-1;
		while(array[k])
			k --;
		array[k] = 1;
		//print_array(array, n);


	}while(degress(degre_array, n-1));

	delete [] degre_array_with_offset;
	delete [] array;
	
}

void generator_neighbour(int n)
{
	uint64 fac_n = factoral(n);
	//permutation array
	PT *array = new PT[n];
	//degressive carry number from -2, -1, 0, 1, --- n
	PT *pro_degre_array = new PT[n+1];
	memset(pro_degre_array, 0, sizeof(PT)*(n+1));
	//degressive carry number
	PT *degre_array = pro_degre_array + 2;
	uint64 quotient = 0, tmp = 0;
	int cnt = 0, i = 0, j = 0, k = 0, mod = 0, odd = 0;

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
		for(j = n-2; j > i; j--)
		{
			if(j & 0x1)
				odd = degre_array[j-1] & 0x1;
			else
				odd = (degre_array[j-1] + degre_array[j-2]) & 0x1;
			if(odd) // equals to (j + 2) % 2
			{
				cnt = 0;
				for(k = 0; k < n; k ++)
				{
					if(cnt == degre_array[j])
					{
						while(array[k])
							k ++;
						array[k] = j + 2;
						break;
					}
					if(!array[k])
						cnt ++;
				}
			}
			else
			{
				cnt = 0;
				for(k = n-1; k >= 0; k --)
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
		}

		k = n-1;
		for(j = i; j >= 0; j --)
		{
			while(array[k])
				k --;
			array[k--] = j+2;
		}
		for(k = 0; k < n; k ++)
		{
			if(!array[k])
			{
				array[k] = 1;
				break;
			}

		}

		print_array(array, n);
	}
	delete [] degre_array;
	delete [] array;
}
