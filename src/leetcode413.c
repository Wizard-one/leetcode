#include <test.h>

/*
413. 等差数列划分


 如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。

    例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。

给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。

子数组 是数组中的一个连续序列。 
*/

// #子数组 #动态规划 #计数

/* 
观察发现等差数组长度增加一位，对应计数增加 len-2 例如

1,2,3,4

1,2,3 为第一个等差数组
1,2,3,4 等差数组增加1 count+=4-2

所以我们只需要维护等差数组的长度即可
 */
int numberOfArithmeticSlices(int* nums, int numsSize){
	if (numsSize<3)
	{
		return 0;
	}
	int diff1=0,diff2=0,len=2,count=0;
	for (int i=2; i < numsSize; i++)
	{
		diff2=nums[i]-nums[i-1];
		diff1=nums[i-1]-nums[i-2];
		// 差不变
		if (diff1==diff2 )
		{
			// 长度++ count更新
			len++;
			count+=len-2;
		}
		else
		{
			// 重新开始维护长度
			while (i<numsSize-1 && diff1!=diff2 )
			{
				i++;
				diff2=nums[i]-nums[i-1];
				diff1=nums[i-1]-nums[i-2];
			}
			len=3;
			if (diff1==diff2)
			{
				count++;
			}
			
		}
	}
	return count;
}

int main(){
	int l[]={1,2,3,5,7,23,1,2,3,4};
	int ans=numberOfArithmeticSlices(l,10);
	printf("%d",ans);
}