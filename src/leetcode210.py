from lib.test import *

""" 
210. 课程表 II

现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。

    例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。

返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。
 """

# #图 #拓扑排序 #深度优先搜索 [[207]]

""" 
相比207 增加了一步使用后序遍历记录节点顺序。 将 ai bi 之间的依赖关系理解为 
ai对 bi 有依赖: ai->bi 那么使用后序遍历进行记录图的遍历顺序就是从没有任何依赖关系的节点开始记录例如

1    0
^   /
| </
2

1的出度为0 就是没有依赖任何节点。

随后在后序遍历的回溯过程中会根据依赖关系进行存储

而将 ai,bi 理解为 ai被bi 依赖: ai<-bi 即从低依赖度的任务bi 指向 高依赖度的ai 则需要对后序遍历的结果进行翻转

这样的拓扑排序指向可以认为是从 起始节点 如何按照顺序到达终止节点的一个流
"""
class Solution:
	def __init__(self):
		# 全局维护是否访问
		self.visited=[]
		# 全局维护是否有环
		self.hasloop=False
		#全局维护依赖顺序
		self.dependency=[]


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
		self.dependency.append(loc)
		path[loc]=False

	def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
		# 制作邻接表
		nearby=collections.defaultdict(list)
		# 选择指向为 ai->bi 这样后序遍历不用翻转
		for edge in prerequisites:
			nearby[edge[0]].append(edge)
		
		self.visited=[False]*numCourses
		path=[False]*numCourses
		# 遍历所有节点
		for i in range(numCourses):
			self.travse(nearby,path,i)
		if self.hasloop:
			return []
		return self.dependency

if __name__ == "__main__":
	s=Solution().findOrder
	print(s(4,[[2,1],[0,2],[3,2]]))

