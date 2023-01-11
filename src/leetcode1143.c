#include <test.h>

/* 1143. 最长公共子序列

给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

    例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。

两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。 */


// #子序列 #字符串 #动态规划 #matrix

/* 标准的二维动态规划问题，将边界设置为空字符串，建立m*n 的动态规划矩阵

i in text1 (m), j in text2 (n)

dp(i,j): 以i,j 结尾的字符串

dp(i,0),dp(j,0)=0 空字符不存在公共子串

w1[i]==w2[j] dp(i,j)=dp(i-1,j-1)+1 相等就是公共字符直接从 i-1,j-1 +1转移即可

w1[i]!=w2[j] dp(i,j)=max(dp(i-1,j),dp(i,j-1)) 不相等就是选择一个大的进行状态继承

综上所述复杂一些的动态规划问题都会使用附带条件的动态转移关系
 */
int longestCommonSubsequence(char * text1, char * text2){
	int m=strlen(text1),n=strlen(text2);
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
			if (text1[i-1]==text2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=fmax(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
		
}