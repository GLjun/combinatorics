/*************************************************************************
    > File Name: toolfunc.h
    > Func: 
    > Created Time: 一 11/ 6 20:43:40 2017
 ************************************************************************/
#pragma once

#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>

typedef unsigned short PT;
typedef unsigned long long uint64;

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
