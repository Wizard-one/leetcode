from lib.test import *

"""
797. 所有可能的路径

 给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）

 graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。
 """
# #深度优先搜索 #图

""" 直接从0开始深度优先搜索， 通过栈来记录路径， """
class Solution:

	def __init__(self) -> None:
		self.ans=[]
		self.n=0

	def dfs(self, graph:List[List[int]],loc:int,path:List[int]):
		"""
		docstring
		"""
		if loc==self.n-1:
			# 到达终点停止
			path.append(loc)
			self.ans.append(path.copy())
			return
		# 记录路径
		path.append(loc)
		for i in graph[loc]:
			# 遍历当前节点可选路径
			self.dfs(graph,i,path)
			path.pop()#撤销选择
		

	def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
		self.n=len(graph)
		path=[]
		self.dfs(graph,0,path)
		return self.ans

if __name__ == "__main__":
	s=Solution().allPathsSourceTarget
	print(s([[1,2],[3],[3],[]]))