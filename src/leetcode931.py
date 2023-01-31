
from lib.test import *
""" 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。

下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。
 """

class Solution:
	def minFallingPathSum(self, matrix: List[List[int]]) -> int:
		n=len(matrix)
		if n==1:
			return matrix[0][0]
		dp=[]
		for i in range(n):
			dp.append([0]*(n))
		for i in range(n):
			dp[0][i]=matrix[0][i]
		for i in range(1,n):
			dp[i][0]=min(dp[i-1][0],dp[i-1][1])+matrix[i][0]
			for j in range(1,n-1):
				dp[i][j]=min(dp[i-1][j],dp[i-1][j+1],dp[i-1][j-1])+matrix[i][j]
			dp[i][n-1]=min(dp[i-1][n-1],dp[i-1][n-2])+matrix[i][n-1]
		mi=10000
		for i in range(n):
			mi=min(mi,dp[n-1][i])
		return mi