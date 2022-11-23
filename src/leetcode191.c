#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// #位运算 [[231]]
int hammingWeight(uint32_t n) {
    int c=0,sum=0;
	for (size_t i = 0; i < 32; i++)
	{
		if(n & 1<<i)
		{
			sum++;
		}
	}
	return sum;
}