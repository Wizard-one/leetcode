#include <test.h>
/* 209. 长度最小的子数组

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。 */

// #连续子数组 #数组 #滑动窗

/* 使用一个滑动窗，维护2个变量
- 窗长len
- 窗内数和winsum

 */
int minSubArrayLen(int target, int* nums, int numsSize){
	int minlen=numsSize+1,l=0,r=0,winsum=0;
	while (r<numsSize)
	{		
		// 当winsum小于target 持续的移动右边界
		winsum+=nums[r++];
		while (winsum>=target)
		{
			// 当winsum 大于等于target 持续的移动左边界
			minlen=(r-l)>minlen?(minlen):(r-l);
			winsum-=nums[l++];
		}
	}
	// 当结果未经过修改说明没有符合条件直接返回0
	if (minlen==numsSize+1)
	{
		return 0;
	}
	return minlen;
}

int main(){
	int l[]={2,3,1,2,4,3};
	int ans=minSubArrayLen(7,l,6);
	printf("%d",ans);
}