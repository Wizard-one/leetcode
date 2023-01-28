#include <test.h>
/* 188. 买卖股票的最佳时机 IV
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 */


// #动态规划 #数组 [[123]]
/* 具体参考动态规划笔记 */
#define IMAX(a,b) (a>b)?(a):(b)
int maxProfit(int k,int* prices, int pricesSize){
	int dp[pricesSize+1][k+1][2];
	memset(dp,0,sizeof(dp));
	// 第0天不可能持有
	for (size_t i = 0; i < k+1; i++)
		dp[0][i][1]=-100000;
	// 没有交易额度不可能持有
	for (size_t i = 0; i < pricesSize+1; i++)
		dp[i][0][1]=-100000;
	
	for (size_t i = 0; i < pricesSize; i++)
	{
		for (int j = 1; j <k+1; j++)
		{
			dp[i+1][j][1]=IMAX(dp[i][j][1],dp[i][j-1][0]-prices[i]);
			dp[i+1][j][0]=IMAX(dp[i][j][0],dp[i][j][1]+prices[i]);
		}
	}
	return dp[pricesSize][k][0];
}