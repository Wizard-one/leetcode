#include <stdio.h>
#include <stdlib.h>

/*
136. 只出现一次的数字

 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。 
*/

// #位运算
int singleNumber(int* nums, int numsSize){
	int ans=nums[0];
	for (size_t i = 1; i < numsSize; i++)
	{
		ans=ans^nums[i];//找不同求异或即可,相同的异或都为0留下来的异或就是不为不相同的结果
	}
	return ans;
}