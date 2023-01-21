from lib.test import *
""" 207. 课程表

你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

    例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。

请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

"""
# #图 #深度优先搜索 #环检测

class Solution:

	""" 问题可以转化为图依赖是否成环，这边采用DFS 对每一个节点进行遍历，额外维护路径与访问过的节点
	同时图可能并不连通，所以需要对所有节点进行遍历
	 """
	def __init__(self):
		# 全局维护是否访问
		self.visited=[]
		# 全局维护是否有环
		self.hasloop=False


	def travse(self,nearby:collections.defaultdict,path:List[bool],loc:int):
		# 如果当前loc 在当前路径当中说明成环
		if path[loc]:
			self.hasloop=True
			return
		# 如果当前节点访问过了就结束访问
		if self.hasloop or self.visited[loc]:
			return 


		path[loc]=True
		self.visited[loc]=True
		# 遍历当前节点的邻接表
		for edge in nearby[loc]:
			self.travse(nearby,path,edge[1])
		path[loc]=False

	def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
		# 制作邻接表
		nearby=collections.defaultdict(list)
		for edge in prerequisites:
			nearby[edge[0]].append(edge)
		
		self.visited=[False]*numCourses
		path=[False]*numCourses
		# 遍历所有节点
		for i in range(numCourses):
			self.travse(nearby,path,i)

		return (not self.hasloop)


if __name__ == "__main__":
	s=Solution().canFinish
	print(s(2,[[1,0],[0,1]]))
