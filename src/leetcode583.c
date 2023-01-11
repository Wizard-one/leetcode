#include <test.h>

/* 
583. 两个字符串的删除操作

给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

每步 可以删除任意一个字符串中的一个字符。 */

//  [[1143]] #字符串 #子序列 #动态规划

/* 和1143 最大子序列一模一样，这边不在赘述 */
int minDistance(char * word1, char * word2){
	int m=strlen(word1),n=strlen(word2);
	int **dp;
	dp=malloc(sizeof(int*)*(m+1));
	for (size_t i = 0; i <= m; i++)
	{
		dp[i]=malloc(sizeof(int)*(n+1));
		for (size_t j = 0; j <=n; j++)
		{
			dp[i][j]=0;
		}
	}
	for (size_t i = 1; i <=m; i++)
	{
		for (size_t j = 1; j <=n; j++)
		{
			if (word1[i-1]==word2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=fmax(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	// 返回的是每个字符串距离公共最大子串删除的字符数
	return m+n-2*dp[m][n];
		
}