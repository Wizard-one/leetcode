#include <stdlib.h>
#include <stdio.h>
/* 70. 爬楼梯

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 */
// #动态规划 #数列 [[198]] #谜语
int climbStairs(int n){
	// 找个递推关系罢了
	// s[i]=s[i-1]+s[i-2]
	if (n==1)
	{
		return 1;
	}
	else if (n==2)
	{
		return 2;
	}
	int x1=1,x2=2,s=0;
	for (size_t i = 0; i < n-2; i++)
	{
		s=x1+x2;
		x1=x2;
		x2=s;
	}
	return s;
}

int main()
{
	int a=climbStairs(6);
	printf("%d",a);
}