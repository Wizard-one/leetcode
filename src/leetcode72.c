#include <test.h>
/* 
72. 编辑距离

给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

    插入一个字符
    删除一个字符
    替换一个字符

 */

/* 
每个单词可以进行3种操作，那么一共有6种操作，但其中一半是等价的

例如

- 对 word1 插入 等价于 word2 删除
- 对 word2 插入 等价于 word1 删除
- 对 word1 替换 等价于 word2 替换

再进一步分析，参考 [[1143]] 这题一定是一个二维的动态规划来求解。 

令dp[i][j] 为word1[:i] 同word2[:j] 进行相互转换所需要操作数，目标就是求 dp[m][n]


边界条件 即空字符串的情况为 删除i/j 次即可

dp[i][0]=i
dp[0][j]=j

状态转移方程就考虑
word1[i]==word2[j] 与 word1[i]!=word2[j] 的两种情况

具体分析可以发现，

当要将dp[i][j-1] 向 dp[i][j] 转换时 是在 word2 结尾增加一个字符 由于word1 不变，那不论增加这个字符是什么，都可以通过一次操作回退到上一个状态

即 dp[i][j]=dp[i][j-1]+1 

dp[i-1][j] -> dp[i][j] 同理

但是 dp[i-1][j-1] 向 dp[i][j] 转换就需要考虑添加的最后 word1[i]==word2[j]时 就无需回退

即 dp[i][j]=dp[i-1][j-1]

综上所述

if word1[i]==word2[j]:
	dp[i][j]=min(dp[i-1][j-1]-1,dp[i-1][j],dp[i][j-1])+1
else:
	dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1
 */
int minDistance(char * word1, char * word2){
	int m=strlen(word1),n=strlen(word2);
	int dp[m+1][n+1];
	memset(dp,0,sizeof(dp));
	// 设置边界条件
	for (size_t i = 0; i <=m; i++)
	{
		dp[i][0]=i;
	}
	for (size_t i = 0; i <=n; i++)
	{
		dp[0][i]=i;
	}
	

	for (size_t i = 1; i <= m; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			// 动态转移条件
			if (word1[i-1]==word2[j-1])
			{
				dp[i][j]=fmin(dp[i][j-1],dp[i-1][j]);
				dp[i][j]=fmin(dp[i][j],dp[i-1][j-1]-1);
				dp[i][j]++;
			}
			else
			{
				dp[i][j]=fmin(dp[i][j-1],dp[i-1][j]);
				dp[i][j]=fmin(dp[i][j],dp[i-1][j-1]);
				dp[i][j]++;
			}
			
		}
	}
	return dp[m][n];
	
}