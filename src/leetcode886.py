from lib.test import * 

"""
 给定一组 n 人（编号为 1, 2, ..., n）， 我们想把每个人分进任意大小的两组。每个人都可能不喜欢其他人，那么他们不应该属于同一组。

给定整数 n 和数组 dislikes ，其中 dislikes[i] = [ai, bi] ，表示不允许将编号为 ai 和  bi的人归入同一组。当可以用这种方法将所有人分进两组时，返回 true；否则返回 false。
 """

# #二分图 #无向图 #图 [[785]]

class Solution:

	""" 
	同785 完全一致，除了开头要建立无向图的邻接表之外
	 """
	def __init__(self):
		"""
		docstring
		"""
		# 全局记录是否为二分图
		self.isbi=True

	def travse(self, graph:List[List[int]],loc:int,visited:List[bool],group:List[bool]):
		"""

		loc: 当前节点
		group: 代表所述二分图中哪一个集合

		对图进行遍历
		"""
		# 如果已经不是二分图就不需要继续遍历 
		if not self.isbi:
			return
		# 记录当前节点已经访问
		visited[loc]=True
		for nearby in graph[loc]:
			# 如果邻接节点已经访问
			if visited[nearby]:
				# 那么检查邻接节点是否属于同一个集合
				if group[nearby]==group[loc]:
					# 如果是，则不是二分图
					self.isbi=False
					return
			else:
				# 如果邻接节点没有访问，则尝试给邻接节点赋值上不同的组，然后遍历邻接节点
				group[nearby]=(not group[loc])
				self.travse(graph,nearby,visited,group)

	def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
		graph=collections.defaultdict(list)
		# 相比 207 的有向图，无向图 需要构建双向链接关系
		for edge in dislikes:
			graph[edge[0]-1].append(edge[1]-1)
			graph[edge[1]-1].append(edge[0]-1)
		visited=[False]*n
		group=[False]*n
		# 由于图不一定连通，所以需要对所有节点进行遍历
		for i in range(n):
			self.travse(graph,i,visited,group)
		
		return self.isbi

if __name__ == "__main__":
	Solution().possibleBipartition(4,[[1,2],[1,3],[2,4]])