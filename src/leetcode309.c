#include <test.h>

/*
309. 最佳买卖股票时机含冷冻期

 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

    卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 */

// #动态规划 
/* 冷静期就是卖出时需要间隔一天，同时调整第0，1天的边界条件 */
#define IMAX(a,b) (a>b)?(a):(b)
int maxProfit(int* prices, int pricesSize){
	if (pricesSize==1)
	{
		return 0;
	}
	
	int dp[pricesSize][2];
	memset(dp,0,sizeof(dp));

	dp[0][1]=-prices[0];
	dp[1][1]=IMAX(dp[0][1],dp[0][0]-prices[1]);
	dp[1][0]=IMAX(dp[0][0],dp[0][1]+prices[1]);
	for (size_t i = 2; i < pricesSize; i++)
	{
		dp[i][1]=IMAX(dp[i-1][1],dp[i-2][0]-prices[i]);
		dp[i][0]=IMAX(dp[i-1][0],dp[i][1]+prices[i]);
	}
	return dp[pricesSize-1][0];
}


int main(int argc, char const *argv[])
{
	int l[]={1,2,3,0,2};
	maxProfit(l,5);
	return 0;
}
