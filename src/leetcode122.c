#include <test.h>

/* 122. 买卖股票的最佳时机 II

给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。
 */
// #动态规划 #数组
#define IMAX(a,b) (a>b)?(a):(b)
/* 具体参考 obsidian://open?vault=Note&file=Technology%2FAlgorithm 状态与选择章节

主要明确有2个状态维度: 天数，持有状态 结束状态为最后一天不持有的状态
 */
int maxProfit(int* prices, int pricesSize){
	int dp[pricesSize+1][2];
	memset(dp,0,sizeof(dp));
	for (size_t i = 0; i < 2; i++)
		dp[0][1]=INT_MIN;
	for (size_t i = 0; i < pricesSize; i++)
	{
		dp[i+1][1]=IMAX(dp[i][1],dp[i][0]-prices[i]);
		dp[i+1][0]=IMAX(dp[i][0],dp[i][1]+prices[i]);
	}
	return dp[pricesSize][0];
}