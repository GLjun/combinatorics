/*************************************************************************
    > File Name: permutation_generater.cpp
    > Func: 
    > Created Time: 六 10/21 10:28:41 2017
 ************************************************************************/

#include <iostream>
#include <cstdio>

//#define DIFF_WATCH
#define ARRAY_PRINT

// library argorithm
#include "library_algorithm.h"
#include "incremental_algorithm.h"
#include "degressive_algorithm.h"
#include "neighbour_algorithm.h"
#include "dswap_incremental_algorithm.h"



void test_diffAll()
{
	uint64 diffcnt = 0;
	for(int i = 4;i < 13; i ++)
	{
		printf("=====N:%d====\n", i);
		diffcnt = generator_incremental_nolimit(i);
		printf("incre:cnt : %llu, avg: %f\n", diffcnt, diffcnt*1.0/factoral(i));
		diffcnt = generator_degressive_nolimit(i);
		printf("degre:cnt : %llu, avg: %f\n  ", diffcnt, diffcnt*1.0/factoral(i));
		//diffcnt = generator_neighbour_nolimit(i);
		//printf("neigh:cnt : %llu, avg: %f   ", diffcnt, diffcnt*1.0/factoral(i));
		diffcnt = generator_dswap_incremental_nolimit(i);
		printf("dswap:cnt : %llu, avg: %f\n", diffcnt, diffcnt*1.0/factoral(i));
		
	}

}

void test_performanceALL()
{
	clock_t sc, ec;
	for(int i = 4;i < 13; i ++)
	{
		printf("N: %d, ", i);
		sc = clock();
		generator_incremental_nolimit(i);
		ec = clock();
		printf("incre: %f, ", (ec-sc)*1.0/(CLOCKS_PER_SEC/1000));
		sc = clock();
		generator_degressive_nolimit(i);
		ec = clock();
		printf("degre: %f, ", (ec-sc)*1.0/(CLOCKS_PER_SEC/1000));
		sc = clock();
		generator_library(i);
		ec = clock();
		printf("libra: %f, ", (ec-sc)*1.0/(CLOCKS_PER_SEC/1000));
		sc = clock();
		generator_neighbour_nolimit(i);
		ec = clock();
		printf("neigh: %f, ", (ec-sc)*1.0/(CLOCKS_PER_SEC/1000));
		sc = clock();
		generator_dswap_incremental_nolimit(i);
		ec = clock();
		printf("dswap: %f\n", (ec-sc)*1.0/(CLOCKS_PER_SEC/1000));
	}
}

/*************************************
 * 测试各个算法
 * ***********************************/
void test_algorithm(int n = 4)
{
	/*************************************************************
	 * generator_library 是字典序版本，支持任意长度的N
	 * generator_incremental_nolimit和generator_incremental 是递增进制版本，其中nolimit	版本直接对递增进制数组进行加1操作，因而支持任意序列长度N，而后者是先用uint64的数加1，然后计算出递增进制数，因而有上限
	 * generator_degressive_nolimit和generator_incremental 是递减进制版本，其中nolimit	版本直接对递减进制数组进行加1操作，因而支持任意序列长度N，而后者是先用uint64的数加1，然后计算出递减进制数，因而有上限
	 * generator_neighbour_nolimit和generator_neighbour 是邻位对换版本，其中nolimit 版本直接对递减进制数组进行加1操作，因而支持任意序列长度N，而后者是先用uint64的数加1，然后计算出递减进制数，因而有上限
	 * generator_dswap_incremental_nolimit 是交换进位制法版本，使用与递增进位制法相同的递增进位数算法
	 * */
	printf("============字典序算法开始=============\n");
	generator_library(n);
	printf("============字典序算法结束=============\n");
	printf("============递增进制法开始=============\n");
	generator_incremental_nolimit(n);
	printf("============递增进制法结束=============\n");
	printf("============递减进制法开始=============\n");
	generator_degressive_nolimit(n);
	printf("============递减进制法结束=============\n");
	printf("============邻位对换法开始=============\n");
	generator_neighbour_nolimit(n);
	printf("============邻位对换法结束=============\n");
	//generator_dswap_incremental_nolimit(8);
	//generator_incremental(8);
	//generator_degressive(8);
	//generator_neighbour(8);
}

int main(int argc, char** argv)
{
	if(argc > 1)
	{
		int k = 0, n = 0;
		while(argv[1][k])
		{
			n = n*10 + (argv[1][k] - '0');
			k ++;
		}

		if(n > 0)
		{
			test_algorithm(n);
		}
		else
		{
			printf("input error! [./a.out 8]\n");
		}
	}
	else
	{
		//defalut n is 4
		test_algorithm();
	}
	//test_performance();
	//test_performanceALL();
	//test_diffAll();
	
	return 0;
}
