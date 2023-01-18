from lib.test import *

"""
51. N 皇后

 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
"""
# #回溯
class Solution:
	
	def __init__(self) -> None:
		self.ans=[]
		self.n=0
		self.tempans=[]
		

	def IsVaid(self,row:int,col:int,walk:List[Set[int]]):
		"""
		docstring
		"""
		for loc in walk:
			# 同一行
			if loc[0]==row:
				return False
			# 同一列
			if loc[1]==col:
				return False
			# 同左下到右上对角线
			if loc[1]+loc[0]==row+col:
				return False
			# 同左上到右下对角线
			if loc[1]-loc[0]==col-row:
				return False
		return True

	def backtrace(self,wait:List[Set[int]],walk:List[Set[int]]):
		"""
		docstring
		"""
		if len(walk)==self.n:
			for loc in walk:
				self.tempans[loc[0]][loc[1]]="Q"
			temp=[]
			for row in self.tempans:
				temp.append("".join(row))
			self.ans.append(temp.copy())
			# 撤销答案保存
			for loc in walk:
				self.tempans[loc[0]][loc[1]]="."

		for i in range(len(wait)):
			if not self.IsVaid(wait[i][0],wait[i][1],walk):
				continue
			walk.append(wait[i])
			nextwait=wait[i+1:].copy()
			self.backtrace(nextwait,walk)
			walk.pop()

	def solveNQueens(self, n: int) -> List[List[str]]:
		self.n=n
		
		wait=[]
		for i in range(n):
			temp=[]
			for j in range(n):
				temp.append('.')
				wait.append((i,j))
			self.tempans.append(temp.copy())

		walk=[]
		self.backtrace(wait,walk)
		return self.ans

if __name__ == "__main__":
	print(Solution().solveNQueens(4))