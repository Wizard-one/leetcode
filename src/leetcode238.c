#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// #数组 #前缀和 
/* 238. 除自身以外数组的乘积
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请不要使用除法，且在 O(n) 时间复杂度内完成此题。 */


/* 
将区间拆分为左区间与右区间，分别存储左区间乘积与右区间乘积，然后将左右区间乘积相乘即得到 除自身以外数组的乘积

 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
	int *ans;
	*returnSize=numsSize;
	ans=malloc(sizeof(int)*numsSize);
	ans[0]=1;
	for (size_t i = 1; i < numsSize; i++)
	{
		ans[i]=ans[i-1]*nums[i-1];
	}
	int R=1;
	for (int i = numsSize-1; i >=0; i--)
	{
		ans[i]=ans[i]*R;
		R=R*nums[i];
	}
	
	return ans;
}

int main()
{
	int l[]={1,2,3,4},rets,*ans;
	ans=productExceptSelf(l,4,&rets);
}