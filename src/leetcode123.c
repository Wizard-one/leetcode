#include <test.h>
/*123. 买卖股票的最佳时机 III

 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 */

// #动态规划 #数组 [[122]]
/* 
具体参考动态规划笔记
 */
#define IMAX(a,b) (a>b)?(a):(b)
int maxProfit(int* prices, int pricesSize){
	int dp[pricesSize+1][3][2];
	memset(dp,0,sizeof(dp));
	// 第0天不可能持有
	for (size_t i = 0; i < 3; i++)
		dp[0][i][1]=-100000;
	// 没有交易额度不可能持有
	for (size_t i = 0; i < pricesSize+1; i++)
		dp[i][0][1]=-100000;
	
	for (size_t i = 0; i < pricesSize; i++)
	{
		for (int k = 1; k <3; k++)
		{
			dp[i+1][k][1]=IMAX(dp[i][k][1],dp[i][k-1][0]-prices[i]);
			dp[i+1][k][0]=IMAX(dp[i][k][0],dp[i][k][1]+prices[i]);
		}
	}
	return dp[pricesSize][2][0];
}