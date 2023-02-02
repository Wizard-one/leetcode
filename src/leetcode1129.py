from lib.test import *
""" 在一个有向图中，节点分别标记为 0, 1, ..., n-1。图中每条边为红色或者蓝色，且存在自环或平行边。

red_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的红色有向边。类似地，blue_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的蓝色有向边。

返回长度为 n 的数组 answer，其中 answer[X] 是从节点 0 到节点 X 的红色边和蓝色边交替出现的最短路径的长度。如果不存在这样的路径，那么 answer[x] = -1。 """


# #广度优先搜索 #图 #最短路
class Solution:
	""" 
	图的最短路问题就是使用BFS， 而BFS每走一步到达一个节点本身就是最短路，无需使用min进行比较。

	问题的难点在于 visit 维护的是edge 而不是 node

	将edge 分颜色构成一个出度表之后对edge进行BFS搜索

	和当前到达路径edge 颜色不一致，且没有访问过的edge的才能加入BFS搜索之中
	"""
	def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
		ans=[-1]*n
		level=0
		# 做出度表
		outdegree=collections.defaultdict(list)
		# 标记红边为1
		for edge in redEdges:
			outdegree[edge[0]].append((edge[1],1))
		# 标记蓝边为0
		for edge in blueEdges:
			outdegree[edge[0]].append((edge[1],0))
		q=collections.deque(outdegree[0])
		ans[0]=0
		# 标记记录edge是否访问过
		visit=set()
		for edge in outdegree[0]:
			visit.add(edge)
		while q:
			qlen=len(q)
			level+=1
			for _ in range(qlen):
				node,color=q.popleft()
				visit.add((node,color))
				# 记录当前节点路径
				if ans[node]==-1:
					ans[node]=level
				for edge in outdegree[node]:
					# 只有当edge未到达，且颜色和当前颜色不一致才添加edge
					if edge not in visit and edge[1]!=color:
						q.append(edge)
		return ans

if __name__ == "__main__":
	s=Solution().shortestAlternatingPaths
	print(s(5,[[0,1],[1,2],[2,3],[3,4]],[[1,2],[2,3],[3,1]]))


		




			

