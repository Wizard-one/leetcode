#include <test.h>

/* 416. 分割等和子集

给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 */


// #动态规划 #数组 #子集
/* 经典NP问题，可以视为背包问题的变种
首先对整个数组求和，相当于求一个子集，和为 sum(nums)//2，使用动态规划来求解：
- 选择: nums[i] 选择 或者不选择
- 状态: i 个数，选择的和，即背包内重量 j
- dp[i][j]: 第i个放入时，重量恰好等于j 则True

B.C.
- dp[i][0]: 说明没有重量需要放所以直接true
- dp[0][j]: 说明没有物品可以满足重量j的要求，所以直接false

状态转移：
不选择就是继承 i-1 的状态，选择就是从上一个容许重量中去除i的重量
dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i]];
遍历范围：
i:[1,n] i=0 就是什么都不放
j:[1,target] j=0 就是没有任何重要需要满足
 */
bool canPartition(int* nums, int numsSize){
	int sum=0;
	for (size_t i = 0; i < numsSize; i++)
		sum+=nums[i];	
	if (sum%2==1)
		return false;
	int target=sum/2;
	int dp[numsSize+1][target+1];
	// 设置边界条件
	for (size_t i = 0; i <=numsSize; i++)
		dp[i][0]=true;
	for (size_t i = 0; i <=target; i++)
		dp[0][i]=false;
	for (size_t i = 1; i <= numsSize; i++)
	{
		for (int j = 1; j <=target; j++)
		{
			// 具体实现 nums index 要差一位
			// 当包内容量不足，就不能进行放入
			if (j-nums[i-1]<0)
				dp[i][j]=dp[i-1][j];
			// 容量充足方可进行选择
			else
				dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
		}
	}
	return dp[numsSize][target];
}

int main(int argc, char const *argv[])
{
	int l[]={1,5,11,5};
	printf("%d",canPartition(l,4));
	return 0;
}
