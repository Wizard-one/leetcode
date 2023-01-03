from lib.test import *
""" 547. 省份数量

有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。 """ 

# #广度优先搜索

""" 
给了一个图的邻接矩阵，使用广搜来查找没有遍历过的节点。

具体就是当连通节点都遍历完，队列为空，说明一个岛完成
"""
class Solution:
	def findCircleNum(self, isConnected: List[List[int]]) -> int:
		# 使用队列来维护广搜
		q=collections.deque([])
		# 标记节点的遍历情况 hash table
		walked=[0 for i in range(len(isConnected))]
		count=0
		for i in range(len(isConnected)):
			if walked[i]!=1:
				# 当没有遍历过，入队开始广搜
				q.append(i)
				while(q):
					k=q.popleft()
					walked[k]=1
					for j in range(len(isConnected)):
						# 遍历k 行的联通情况
						if walked[j]!=1 and isConnected[k][j]==1:
							# 存在节点没有遍历过以及联通则入队
							q.append(j)
				# 当连通节点都遍历完，队列为空，说明一个岛完成 ，搜索下一个节点
				count+=1
		return count

if __name__ == "__main__":
	s=Solution().findCircleNum
	print(s([[1,1,0],[1,1,0],[0,0,1]]))
				
