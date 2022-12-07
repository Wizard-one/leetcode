from lib.test import *
""" 1557. 可以到达所有点的最少点数目
给你一个 有向无环图 ， n 个节点编号为 0 到 n-1 ，以及一个边数组 edges ，其中 edges[i] = [fromi, toi] 表示一条从点  fromi 到点 toi 的有向边。

找到最小的点集使得从这些点出发能到达图中所有点。题目保证解存在且唯一。

你可以以任意顺序返回这些节点编号
 """

# #图
class Solution:
	""" 
	通过观察之后尝试统计每个节点的出入度，随后就发现入度为0的节点就是最小点集，证明如下:

	假设node x $D_{in}=0$ 且x不属于目标点集

	显然，因为x入度为0 没有其他节点可以到达x 只能从x出发

	假设node x $D_{in}!=0$ 且x属于目标点集

	可以发现 由于x 入度不为0 说明其他节点可以到达x 在叠加上述条件，所有 入度为0的节点都属于目标点集。
	也就是说必然存在从某一个入度为0的node开始 可以到达x 由此证明了x不属于目标点点集。
	
	"""
	def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
		inDegrees = collections.Counter(y for _, y in edges)
		startnode:List[int]=[]
		for i in range(n):
			if inDegrees[i]==0:
				startnode.append(i)
		return startnode