#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

/* 334. 递增的三元子序列

给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。 */

// #贪心 
// 核心是维护i,j,k 中 i 为 0-j min k 为 j-numsSize max
bool increasingTriplet(int* nums, int numsSize){
	if (numsSize<3)
	{
		return false;
	}
	int l=nums[0],m=INT_MAX;
	for (size_t i = 1; i < numsSize; i++)
	{
		if (nums[i]>m)
		{
			// 必须优先终止,一旦先判断nums[i]>l并不代表不满足nums[i]>m, 但这种情况已经将m更新了就不会return了
			// 考虑清楚 nums[i]>m 是 nums[i]>l 的子集
			return true;
		}
		else if(nums[i]>l)
		{
			m=nums[i];
		}
		else
		{
			l=nums[i];
		}
	}
	return false;
}



int main(){
	int l[]={20,100,10,12,5,11,13};
	bool ans;
	ans=increasingTriplet(l,6);
	printf("%d",ans);
}