from lib.test import *

""" 516. 最长回文子序列

给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
"""

# #动态规划 #回文串 #字符串 #子序列
class Solution:
	""" 
	子序列问题采用动态规划求解，由于回文串需要两个指针分别标记头尾才能表征所以需要使用二维DP
	用 dp[i][j] 标记 j-i 内最长回文串长度，那么状态转移必然分为
	s[i]==s[j] dp[i-1][j+1]-> dp[i][j] 回文串扩展必然扩张2个字符
	
	难点在于回文串不扩展，需要继承哪些状态
	s[i]!=s[j] 说明 i，j 不能同时出现在 j-i 这个子序列区间中，所以是从  dp[i][j+1],dp[i-1][j] 大的那一个转移过去
	
	至此，边界条件就是 i==j 只有一个字符的情况，根据边界条件设置遍历顺序即可
	"""
	def longestPalindromeSubseq(self, s: str) -> int:
		n=len(s)
		dp=[]
		for i in range(n):
			dp.append([0]*n)
		for i in range(n):
			dp[i][i]=1
		# i 正序
		for i in range(n):			
			# j从i-1开始逆序向后退
			for j in range(i-1,-1,-1):
				if s[i]==s[j]:
					dp[i][j]=dp[i-1][j+1]+2
				if s[i]!=s[j]:
					dp[i][j]=max(dp[i][j+1],dp[i-1][j])
		return dp[n-1][0]

if __name__ == "__main__":
	s=Solution().longestPalindromeSubseq
	print(s("aa"))