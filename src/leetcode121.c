#include <math.h>
#include <stdlib.h>
#include <stdio.h>
/* 121. 买卖股票的最佳时机
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 */

// #动态规划 #谜语 [[53]] [[70]] [[198]]

/* 找最大值，这就可能适用动态规划求解
目标：数组内按序遍历的最大差价

简单来想按照顺序遍历到i，i处最大差价就是0-i 之间最小价格与最大价格之间的差值所以就得到以下关系

f(i): i处最大利润

g(i): i处最低价格

g(i)=min(p(i),g(i-1))

f(i)=min(p(i)-g(i),f(i-1))

目标: f(-1)

 */
int maxProfit(int* prices, int pricesSize){
	int ma=0,mi=prices[0];//最小价格
	for (size_t i = 0; i < pricesSize; i++)
	{
		mi=fmin(prices[i],mi);
		ma=fmax(prices[i]-mi,ma);//最大差价
	}
	return ma;
}

int main(){
	int a[6]={7,1,5,3,6,4},d;
	d=maxProfit(a,6);
	printf("%d\n",d);
	return 0;
}