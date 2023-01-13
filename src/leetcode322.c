#include <test.h>

/*322. 零钱兑换

 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。 */

/*
分析可知每一个amount 唯一对应一个最少硬币个数，所以符合最优子结构，当前问题可以使用动态规划来求解

base case 就是 目标 amount=0 的情况，从而得出状态可以是每一个目标金额，那么状态之间转移就是从 coins 中选择一个数, 那么自然而然的 `dp` 数组维护的就是每一个 amount 最小 coins 数目，由此得到以下状态转移方程。
dp[i]=min(dp[i-coins[j]]+1,dp[i])

j in coinsSize
 */

// #动态规划  [[39]] #记忆化搜索
int coinChange(int* coins, int coinsSize, int amount){
	int *dp;
	dp=malloc(sizeof(int)*(amount+1));
	dp[0]=0;
	for (size_t i = 1; i <= amount; i++)
	{
		dp[i]=amount+1;
	}
	for (int i = 0; i <= amount; i++)
	{
		for (size_t j = 0; j < coinsSize; j++)
		{
			if (i-coins[j]<0)
			{
				continue;
			}
			
			dp[i]=fmin(dp[i],dp[i-coins[j]]+1);
		}
	}
	if (dp[amount]==amount+1)
	{
		return -1;
	}
	return dp[amount];
}


int main(int argc, char const *argv[])
{
	int l[]={186,419,83,408};
	int ans=coinChange(l,4,6249);
	printf("%d",ans);
	return 0;
}
