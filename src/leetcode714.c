#include <test.h>
/*
714. 买卖股票的最佳时机含手续费
 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。 */

// #动态规划 #数组 [[122]]
/* 具体参考 obsidian://open?vault=Note&file=Technology%2FAlgorithm 状态与选择章节

主要明确有2个状态维度: 天数，持有状态 结束状态为最后一天不持有的状态

相比122在买入的时候添加付费即可
 */
#define IMAX(a,b) (a>b)?(a):(b)
int maxProfit(int* prices, int pricesSize,int fee){
	int dp[pricesSize+1][2];
	memset(dp,0,sizeof(dp));
	for (size_t i = 0; i < 2; i++)
		dp[0][1]=INT_MIN;
	for (size_t i = 0; i < pricesSize; i++)
	{
		dp[i+1][1]=IMAX(dp[i][1],dp[i][0]-prices[i]-fee);
		dp[i+1][0]=IMAX(dp[i][0],dp[i][1]+prices[i]);
	}
	return dp[pricesSize][0];
}