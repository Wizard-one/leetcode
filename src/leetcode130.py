from lib.test import *


# [[733]] #深度优先搜索
"""130. 被围绕的区域
 
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。 
 """

""" 由于所有与边界连通的区域都不会被设置X，

所以先单独处理边界，而后对没有访问过的内部空间全部置X即可 """
class Solution:
	def solve(self, board: List[List[str]]) -> None:
		m=len(board)
		n=len(board[0])
		# 最小围绕3x3
		if m<3 or n<3:
			return 
		visited=[]
		for i in range(m):
			temp=[]
			for j in range(n):
				temp.append(0)
			visited.append(temp)

		for i in range(m):
			self.floodboundary(visited,board,i,0)
			self.floodboundary(visited,board,i,n-1)
		for j in range(n):
			self.floodboundary(visited,board,0,j)
			self.floodboundary(visited,board,m-1,j)
		
		for i in range(1,m-1):
			for j in range(1,n-1):
				self.floodinside(visited,board,i,j)



	def floodboundary(self,visited:List[List[int]],board:List[List[str]],r:int,c:int):
		m=len(board)
		n=len(board[0])
		if (r>=m or r<0) or c>=n or c<0 or board[r][c]=="X" or visited[r][c]==1:
			return 
		else:
			visited[r][c]=1
			
		# 这一步体现为深度优先，先遇到边界再开始回朔
		self.floodboundary(visited,board,r-1,c)
		self.floodboundary(visited,board,r+1,c)
		self.floodboundary(visited,board,r,c-1)
		self.floodboundary(visited,board,r,c+1)
	
	def floodinside(self,visited:List[List[int]],board:List[List[str]],r:int,c:int):
		m=len(board)
		n=len(board[0])
		if (r>=m-1 or r<1) or c>=n-1 or c<1 or board[r][c]=="X" or visited[r][c]==1:
			visited[r][c]=1
			return 

		visited[r][c]=1
		board[r][c]="X"
		# 这一步体现为深度优先，先遇到边界再开始回朔
		self.floodinside(visited,board,r-1,c)
		self.floodinside(visited,board,r+1,c)
		self.floodinside(visited,board,r,c-1)
		self.floodinside(visited,board,r,c+1)

if __name__ == "__main__":
	s=Solution().solve
	board=[["X","O","X","X"],["O","X","O","X"],["X","O","X","O"],["O","X","O","X"],["X","O","X","O"],["O","X","O","X"]]
	s(board)
	print(board)