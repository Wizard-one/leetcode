#include <stdio.h>
#include <stdlib.h>


// #数组
/* 寻找数组的中心下标 */
int pivotIndex(int* nums, int numsSize){
	int sum=0,lsum=0;
	// 遍历一次求得数组总和,象征着获取数组所有信息
	for (size_t i = 0; i < numsSize; i++)
	{
		sum+=nums[i];
	}
	// 然后从左向右排除左边和,当左边和等于右边和时返回
	for (size_t i = 0; i < numsSize; i++)
	{
		if (lsum==sum-nums[i]-lsum)
		{
			return i;
		}
		lsum+=nums[i];
	}
	return -1;
}
