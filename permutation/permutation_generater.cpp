/*************************************************************************
    > File Name: permutation_generater.cpp
    > Func: 
    > Created Time: 六 10/21 10:28:41 2017
 ************************************************************************/

#include <iostream>
#include <cstdio>

//#define DIFF_WATCH

// library argorithm
#include "library_algorithm.h"
#include "incremental_algorithm.h"
#include "degressive_algorithm.h"
#include "neighbour_algorithm.h"
#include "swap_incremental_algorithm.h"
#include "dswap_incremental_algorithm.h"

void test_algorithm()
{
	/*************************************************************
	 * generator_library 是字典序版本，支持任意长度的N
	 * generator_incremental_nolimit和generator_incremental 是递增进制版本，其中nolimit	版本直接对递增进制数组进行加1操作，因而支持任意序列长度N，而后者是先用uint64的数加1，然后计算出递增进制数，因而有上限
	 * generator_degressive_nolimit和generator_incremental 是递减进制版本，其中nolimit	版本直接对递减进制数组进行加1操作，因而支持任意序列长度N，而后者是先用uint64的数加1，然后计算出递减进制数，因而有上限
	 * generator_neighbour_nolimit和generator_neighbour 是邻位对换版本，其中nolimit 版本直接对递减进制数组进行加1操作，因而支持任意序列长度N，而后者是先用uint64的数加1，然后计算出递减进制数，因而有上限*/
	//generator_library(8);
	//generator_incremental(8);
	//generator_incremental_nolimit(4);
	//generator_degressive(4);
	//generator_degressive_nolimit(15);
	//generator_neighbour(4);
	//generator_neighbour_nolimit(4);
	//generator_swap_incremental_nolimit(4);
	generator_dswap_incremental_nolimit(4);
}

void test_performance()
{
	clock_t sc, ec, ec2;
	uint64 idiffcnt = 0, swdiffcnt = 0;
	for(int i = 4; i < 12; i ++)
	{
		sc = clock();
		//idiffcnt = generator_degressive_nolimit(i);
		//idiffcnt = generator_incremental_nolimit(i);
		idiffcnt = generator_dswap_incremental_nolimit(i);
		ec = clock();
		//swdiffcnt = generator_dswap_incremental_nolimit(i);
		ec2 = clock();
		printf("N: %d, incremental_time: %f, swap_incremental_time: %f, incremental_diff_cnt: %llu avg: %f, dswap_incremental_diff_cnt: %llu, avg: %f\n", i, (ec-sc)*1.0/(CLOCKS_PER_SEC/1000), (ec2-ec)*1.0 / (CLOCKS_PER_SEC/1000), idiffcnt, idiffcnt*1.0/factoral(i), swdiffcnt, swdiffcnt*1.0/factoral(i));
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


int main(int argc, char** argv)
{
	//test_algorithm();
	//test_performance();
	test_performanceALL();
	
	return 0;
}
