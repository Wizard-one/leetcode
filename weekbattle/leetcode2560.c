#include <test.h>
/* 沿街有一排连续的房屋。每间房屋内都藏有一定的现金。现在有一位小偷计划从这些房屋中窃取现金。

由于相邻的房屋装有相互连通的防盗系统，所以小偷 不会窃取相邻的房屋 。

小偷的 窃取能力 定义为他在窃取过程中能从单间房屋中窃取的 最大金额 。

给你一个整数数组 nums 表示每间房屋存放的现金金额。形式上，从左起第 i 间房屋中放有 nums[i] 美元。

另给你一个整数数组 k ，表示窃贼将会窃取的 最少 房屋数。小偷总能窃取至少 k 间房屋。

返回小偷的 最小 窃取能力。 */

// #动态规划 #最大最小 #二分法 [[198]]
/* 
这是一个求解最小化最大值的问题，应该使用二分法求解。

我们先假定能窃取最大金额为 mx, 然后遍历nums 看是否能够满足偷窃至少k次的条件。

如果不能满足，则说明mx 太小 需要放大， 如果能够满足，因为我们求解的是最小的最大值（最大金额的左边界），那么缩小mx。这样的一个过程就可以通过二分法进行求解。单调的区间就是 [min(nums),max(nums)]

至于偷窃次数的求解是一个动态规划问题
dp[i]: i 处偷窃次数
if nums[i]<=mx
	dp[i]=max(dp[i-2]+1,dp[i-1])
B.C
dp[0]= (nums[0]<=mx ? 1:0)
dp[1]=(max(nums[1],nums[0])<=mx ? 1:0)

使用空间压缩
dp[i]=f
dp[i]=f_1
dp[i-2]=f_2

B.C 也可以简化为
f_1=0,f_2=0
i in [0,numsSize)
 */
int minCapability(int* nums, int numsSize, int k){
	int right=0,left=INT_MAX,mid;
	if(numsSize==1)
	{
		return nums[0];
	}
	// 找出最大最小值作为二分法的左右区间
	for (size_t i = 0; i < numsSize; i++)
	{
		right=fmax(nums[i],right);
		left=fmin(nums[i],left);
	}
	
	int f,f_2,f_1;
	// 搜索区间 [left,right)
	while (left<right)
	{
		mid=left+(right-left)/2;
		// 经过空间压缩的动态规划，边界条件可以直接涵盖在求解过程中
		f_2=0,f_1=0;
		for (size_t i = 0; i < numsSize; i++)
		{
			
			if (nums[i]<=mid)
			{
				// 满足条件才能偷
				f=fmax(f_2+1,f_1);
				f_2=f_1;
				f_1=f;
			}
			else
			{
				// 大于当前可偷窃最大值，直接继承状态
				f=f_1;
				f_2=f_1;
			}
				
		}
		// printf("f:%d;%d,%d,%d\n",f,left,mid,right);
		// 搜索的是最大值的左边界，所以f>=k 都要更新right
		if (f>=k)
			right=mid;
		else
			left=mid+1;
	}
	return left;
}

int main(int argc, char const *argv[])
{
	int l[]={7,3,9,5};
	printf("%d",minCapability(l,4,2));
	return 0;
}
