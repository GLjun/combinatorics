
代码包含以下几部分(环境为macos):
permutation_generator.cpp为主文件:
	test_algorithm()调用四种排列生成算法
	test_performanceALL()为性能测试
	test_diffALL()，为文章中的实验使用的相邻排列差别计算版本，需要打开DIFF_WATCH宏定义，关闭ARRAY_PRINT宏定义

toolfunc.h为全局宏定义以及部分工具函数
library_algorithm.h 为字典序算法
incremental_algorithm.h为递增进位制算法
degressive_algorithm.h为递减进位制算法
neighbour_algorithm.h为邻位对换进位制算法
dswap_incremental_algorithm为文章中的交换进位制算法


程序运行方法:
	1. 可以直接./a.out n 运行，其中n为大于等于1的整数(如果超过unsigned char的大小，请修改toolfunc.h中的PT 的 typedef语句)
	2. 或者修改permutation_generator.cpp中的test_algorithm函数，有详细的注释说明,然后编译该文件,再运行

	3. 默认没有输出文章中的交换递增进位制算法，可以在test_algorithm函数里修改
	4. 默认打开宏定义ARRAY_PRINT，注释该宏定义则不打印排列输出



