from lib.test import *

"""
51. N 皇后

 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
"""
# #回溯
""" 
经典的回溯问题，性能的关键在于如何定义每一次的选择。如果将选择定义为 (i,j) 那回溯计算复杂度是 O(!(n^2))

但是定义为按照行放置Q 然后遍历列 这样就缩减到 O(!n)

这两者的区别在于如何定义枚举

子集枚举：可以把问题转化成「从 n^2 个格子中选一个子集，使得子集中恰好有 n 个格子，且任意选出两个都不在同行、同列或者同对角线」，这里枚举的规模是 2^{n^2}；
组合枚举：可以把问题转化成「从 n^2 个格子中选择 n 个，且任意选出两个都不在同行、同列或者同对角线」，这里的枚举规模是 {n^2} \choose {n}；
排列枚举：因为这里每行只能放置一个皇后，而所有行中皇后的列号正好构成一个 1 到 n 的排列，所以我们可以把问题转化为一个排列枚举，规模是 n!。

"""
class Solution:
	
	def __init__(self) -> None:
		self.ans=[]
		

	def IsVaid(self,row:int,col:int,board:List[Set[int]]):
		"""
		检测皇后放置是否合法
		"""
		# 后面还没放，就不需要检查
		for i in range(row):
			if board[i][col] == 'Q':
				return False
		# 判断左上角是否冲突
		i = row - 1
		j = col - 1
		while i >= 0 and j >= 0:
			if board[i][j] == 'Q':
				return False
			i -= 1
			j -= 1
		# 判断右上角是否冲突
		i = row - 1
		j = col + 1
		while i >= 0 and j < len(board):
			if board[i][j] == 'Q':
				return False
			i -= 1
			j += 1
		return True


	def backtrace(self,row:int,board:List[List[str]]):
		"""
		docstring
		"""
		if row==len(board):
			# 最后一行放完就结束
			temp=[]
			for rows in board:
				temp.append("".join(rows))
			self.ans.append(temp.copy())

		for c in range(len(board)):
			# 合法就放否则就不放
			if not self.IsVaid(row,c,board):
				continue
			board[row][c]="Q"
			self.backtrace(row+1,board)
			board[row][c]="."

	def solveNQueens(self, n: int) -> List[List[str]]:
		board=[]
		for i in range(n):
			temp=[]
			for j in range(n):
				temp.append('.')
			board.append(temp.copy())

		self.backtrace(0,board)
		return self.ans

if __name__ == "__main__":
	print(Solution().solveNQueens(4))