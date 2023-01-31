
from lib.test import *
""" 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。

下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。
 """

# #动态规划 #matrix
class Solution:

	""" 没有进行空间压缩的动态规划，相对来说动态转移方程非常的明显，只要处理好边界条件即可 """
	def minFallingPathSum_BigSpace(self, matrix: List[List[int]]) -> int:
		n=len(matrix)
		# 边界条件不包含n=1 所以单独处理
		if n==1:
			return matrix[0][0]
		dp=[]
		# 创建dp table 数组
		for i in range(n):
			dp.append([0]*(n))
		# 初始条件
		for i in range(n):
			dp[0][i]=matrix[0][i]
		for i in range(1,n):
			# 左边界只能有2个路径
			dp[i][0]=min(dp[i-1][0],dp[i-1][1])+matrix[i][0]
			for j in range(1,n-1):
				dp[i][j]=min(dp[i-1][j],dp[i-1][j+1],dp[i-1][j-1])+matrix[i][j]
			# 右边界只能有2个路径
			dp[i][n-1]=min(dp[i-1][n-1],dp[i-1][n-2])+matrix[i][n-1]
		mi=10000
		# 返回最小值
		for i in range(n):
			mi=min(mi,dp[n-1][i])
		return mi

	""" 使用空间压缩将二维dp投影为1D dp"""
	def minFallingPathSum(self, matrix: List[List[int]]) -> int:
		n=len(matrix)
		if n==1:
			return matrix[0][0]
		# 创建dp table 数组
		# 初始条件
		dp=matrix[0].copy()
		for i in range(1,n):
			# 从左向右赋值，所以保存上一个为左边的val
			last=dp[0]
			dp[0]=min(dp[0],dp[1])+matrix[i][0]
			for j in range(1,n-1):
				cur=dp[j]
				dp[j]=min(dp[j],dp[j+1],last)+matrix[i][j]
				last=cur
			# 右边界只能有2个路径
			dp[n-1]=min(dp[n-1],last)+matrix[i][n-1]
		# 返回最小值
		return min(dp)