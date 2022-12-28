#include <test.h>

/*
162. 寻找峰值

 峰值元素是指其值严格大于左右相邻值的元素。

给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。

你必须实现时间复杂度为 O(log n) 的算法来解决此问题。 */

// [[33]] #二分法 #搜索

/* 核心是只搜索变小的方向 */
int findPeakElement(int* nums, int numsSize){
	int l=0,r=numsSize-1;
    int mid=(l+r)/2;
	// 单独处理左右越界的情况
	if (numsSize==2)
	{
		return nums[0]>nums[1]?0:1;
	}
	
    while (l<=r&&mid>0&&mid<numsSize-1)
    {
		if (nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1])
		{
			return mid;
		}
        // 左边是变小的方向
        if(nums[mid]>nums[mid+1])
        {
			// 将右边界改到mid左边
            r=mid;
            mid=(l+r)/2;
        }
        else
        {
            // 右边是变小的方向，将左边界改到右边
			l=mid+1;
            mid=(l+r)/2;
        }
    }
	return mid;
}
int main(){
	int l[]={3,4,3,2,1},ans;
	ans=findPeakElement(l,5);
	printf("%d",ans);
}