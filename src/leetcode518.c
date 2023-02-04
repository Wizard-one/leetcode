#include <test.h>
/*518. 零钱兑换 II
 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

假设每一种面额的硬币有无限个。 

题目数据保证结果符合 32 位带符号整数。 */


// #动态规划 #完整背包 #子集 [[416]]

/* 
从数组中可以无限制选择重复的子序列，采用背包问题的方式求解

状态有两个：前i个硬币，与金额j
选择有两个：第i个硬币，选择与不选择
dp[i][j]定义: 前i个硬币能恰好凑凑出金额为j组合数

状态转移就是
j<coins[i]: 金额不足 继承上一个状态 dp[i][j]=dp[i-1][j]

j>=coins[i]: 选择i dp[i][j-coins[i]] 不选择i dp[i-1][j] 两者状态时叠加的
dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]]

边界条件: 
dp[0][i]=0; 没有金币可选，却有金额，组合数=0
dp[i][0]=1; 金额要求=0，默认什么都不选即可
 */
int change(int amount, int* coins, int coinsSize){
	int dp[coinsSize+1][amount+1];
	// B.C
	for (size_t i = 0; i <=amount; i++)
	{
		dp[0][i]=0;
	}
	for (size_t i = 0; i <= coinsSize; i++)
	{
		dp[i][0]=1;
	}
	// coins idx 错一位
	for (size_t i = 1; i <=coinsSize; i++)
	{
		for (int j = 1; j <= amount; j++)
		{
			if (j-coins[i-1]<0)
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
			}
		}
	}
	return dp[coinsSize][amount];
}

int main(int argc, char const *argv[])
{
	int nums[]={1,2,5};
	int ans=change(5,nums,3);
	printf("%d",ans);
	return 0;
}
