#include <stdlib.h>
#include <stdio.h>

// #动态规划 #数列 
int climbStairs(int n){
	// 找个递推关系罢了
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