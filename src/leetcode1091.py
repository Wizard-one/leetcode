from lib.test import *
""" 1091. 二进制矩阵中的最短路径

 给你一个 n x n 的二进制矩阵 grid 中，返回矩阵中最短 畅通路径 的长度。如果不存在这样的路径，返回 -1 。

二进制矩阵中的 畅通路径 是一条从 左上角 单元格（即，(0, 0)）到 右下角 单元格（即，(n - 1, n - 1)）的路径，该路径同时满足下述要求：

    路径途经的所有单元格都的值都是 0 。
    路径中所有相邻的单元格应当在 8 个方向之一 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。

畅通路径的长度 是该路径途经的单元格总数。 """

# #广度优先搜索 #matrix

""" 
由于是需要寻找全局最小，使用dfs会超时，这边选择使用bfs 

核心就是如何维护路径，以及如何证明当前路径是最小的。

对于广度优先搜索，由于选择时将走过的路径都标记为 visited ，同时在所有可选选择之后再进行路径++

这对应了
1. 不会出现搜索重复
2. 所有路径完成遍历，到达终点必然全局最小
"""
class Solution:
	def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
		if grid[0][0] or grid[-1][-1]:
			return -1
		n=len(grid)
		length=0
		grid[0][0]=1#入队前将节点标记为 visited
		que=collections.deque([(0,0)])
		while(que):
			# 当前选择清空再进行路径++
			for _ in range(len(que)):
				i,j=que.popleft()
				if i==n-1 and j==n-1:
					return length+1
				for im in [-1,0,1]:
					for jm in [-1,0,1]:
						# 节约入队出队成本，队列中只维护合法的选择
						if i+im<0 or i+im>=n or j+jm<0 or j+jm>=n or grid[i+im][j+jm]!=0:
							continue
						grid[i+im][j+jm]=1
						que.append((i+im,j+jm))
			length+=1
		return -1

if __name__ == "__main__":
	grid=[[0,0,0],[1,0,0],[1,1,0]]
	s=Solution().shortestPathBinaryMatrix
	print(s(grid))
