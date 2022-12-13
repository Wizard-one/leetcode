#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/* 191. 位1的个数

编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
 */
// #位运算 [[231]] [[190]]
int hammingWeight(uint32_t n) {
    int c=0,sum=0;
	for (size_t i = 0; i < 32; i++)
	{
		if(n & 1<<i)//用一个1不断左移扫描
		{
			sum++;
		}
	}
	return sum;
}