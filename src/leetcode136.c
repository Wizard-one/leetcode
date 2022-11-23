#include <stdio.h>
#include <stdlib.h>


// #位运算
int singleNumber(int* nums, int numsSize){
	int ans=nums[0];
	for (size_t i = 1; i < numsSize; i++)
	{
		ans=ans^nums[i];//找不同求异或即可
	}
	return ans;
}