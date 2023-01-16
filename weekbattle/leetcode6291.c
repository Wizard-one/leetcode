#include <test.h>

/* 给你一个正整数数组 nums 。

    元素和 是 nums 中的所有元素相加求和。
    数字和 是 nums 中每一个元素的每一数位（重复数位需多次求和）相加求和。

返回 元素和 与 数字和 的绝对差。

注意：两个整数 x 和 y 的绝对差定义为 |x - y| 。 */

int differenceOfSum(int* nums, int numsSize){
	int sum=0,numsum=0;
	for (size_t i = 0; i < numsSize; i++)
	{
		sum+=nums[i];
		while (nums[i]>0)
		{
			numsum+=nums[i]%10;
			nums[i]/=10;
		}
		
	}
	return abs(sum-numsum);
}

