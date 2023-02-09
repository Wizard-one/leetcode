#include <test.h>

/* 2439. 最小化数组中的最大值
 给你一个下标从 0 开始的数组 nums ，它含有 n 个非负整数。

每一步操作中，你需要：

    选择一个满足 1 <= i < n 的整数 i ，且 nums[i] > 0 。
    将 nums[i] 减 1 。
    将 nums[i - 1] 加 1 。

你可以对数组执行 任意 次上述操作，请你返回可以得到的 nums 数组中 最大值 最小 为多少。
 */

// #最大最小 #二分法

/* 
最大值最小化, 假定答案为 lim 按照变化规则可以发现nums[0]的值只会不断变大,其他值只会越加趋近lim。
那么从后向前模拟当nums[i]>lim 则 nums[i]=lim, nums[i-1]+nums[i]-lim 

模拟到nums[0]时 nums[0]>lim 说明 lim小了 要右移 否则 左移
 */
int minimizeArrayValue(int* nums, int numsSize){
	int left=INT_MAX,right=0;
	for (size_t i = 0; i < numsSize; i++)
	{
		left=fmin(nums[i],left);
		right=fmax(nums[i],right);
	}
	if (right==nums[0])
	{
		return right;
	}
	
	int mid;
	long tmp=0;
	while (left<right)
	{
		tmp=0;
		mid=left+(right-left)/2;
		// 从后向前模拟值转换的过程
		for (int i = numsSize-1; i >0 ; i--)
		{
			// 模拟 if nums[i]>mid: nums[i]=mid nums[i-1]+nums[i]-mid 
			// 令tmp=nums[i]-mid，根据转移条件 则tmp>=0
			// 当转移过程等价于 nums[i]+tmp
			// new tmp=nums[i]+old tmp-mid
			tmp=fmax(nums[i]+tmp-mid,0);
		}
		// lim 大了要左移，所以右边界左移
		if (nums[0]+tmp<=mid)
			right=mid;
		else
		// lim 小了，要右移，左移左边界右移
			left=mid+1;
	}	
	return left;
}

int main(int argc, char const *argv[])
{
	int l[]={6,9,3,8,14};
	printf("%d",minimizeArrayValue(l,5));
	return 0;
}
