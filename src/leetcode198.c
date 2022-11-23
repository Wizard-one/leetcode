#include <stdlib.h>
#include <stdio.h>

#define IMAX(a,b) ((a)>(b)?(a):(b))

// #动态规划 [[70]] [[53]]
int rob(int* nums, int numsSize){
	// 边界条件:
	if (numsSize==1)
	{
		return nums[0];
	}
	else if (numsSize==2)
	{
		return IMAX(nums[0],nums[1]);
	}
	int sum=0,sprev1=IMAX(nums[0],nums[1]),sprev2=nums[0];
	// 递推关系: $f(x)=\max[f(x-1),f(x-2)+n(x)]$
	
	for (size_t i = 2; i < numsSize; i++)
	{
		sum=IMAX(sprev1,sprev2+nums[i]);
		sprev2=sprev1;
		sprev1=sum;
	}
	return sum;
}