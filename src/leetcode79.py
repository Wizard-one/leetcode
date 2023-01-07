from lib.test import *
""" 
79. Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
"""

# #深度优先搜索 #回溯 #字符串 #搜索 

class Solution:
	"""
	首先要搜索一个连续的字符串就意味着需要维护走过的路径，进一步联系到使用回溯来解决这个问题

	一个节点有2种情况:
	1. 与word[k] 不匹配 直接返回false
	2. word[k] 匹配，将当前位置加入walk然后向3个方向搜索

	总体的时间复杂度还是非常高
	"""
	def exist(self, board: List[List[str]], word: str) -> bool:
		m=len(board)
		n=len(board[0])
		move=[(0,1),(1,0),(-1,0),(0,-1)]
		visit=[]#存放遍历过的节点

		def dfs(i:int,j:int,k:int):
			""" 
			loc: i,j,k
			i: row
			j: column
			k: index in word
			"""
			if board[i][j]!=word[k]:
				return False
			if k==len(word)-1:# 字符串匹配到结尾了
				return True
			ans=False

			visit.append((i,j))# 加入选择
			for x,y in move:
				ni,nj=i+x,j+y
				if ni<m and ni>=0 and nj<n and nj>=0 and ((ni,nj) not in visit):
					ans=dfs(ni,nj,k+1)
				if ans:
					return True
			visit.pop()#没有搜到就撤销选择
			return ans

		# 排除字符串长度大于矩阵长度的情况
		if m*n < len(word):
			return False
		for i in range(m):
			for j in range(n):
				# 其实不需要对每一个遍历一次，但是偷懒。还是可以继续剪枝来优化
				ans=dfs(i,j,0)
				if ans:
					return True
		return False

if __name__ == "__main__":
	from time import perf_counter
	s=Solution().exist
	print(s([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],"ABCC"))
	t0=perf_counter()
	print(s([["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"]],"AAAAAAAAAAAAAAa"))
	print(perf_counter()-t0)
	# print(s([["A"]],"C"))