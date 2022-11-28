#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// #数组 #前缀和 
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