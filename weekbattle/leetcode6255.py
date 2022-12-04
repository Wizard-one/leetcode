from typing import List
import collections
# #图 #hash #队列  #排序

""" 两个城市间路径的最小分数

给你一个正整数 n ，表示总共有 n 个城市，城市从 1 到 n 编号。给你一个二维数组 roads ，其中 roads[i] = [ai, bi, distancei] 表示城市 ai 和 bi 之间有一条 双向 道路，道路距离为 distancei 。城市构成的图不一定是连通的。

两个城市之间一条路径的 分数 定义为这条路径中道路的 最小 距离。

城市 1 和城市 n 之间的所有路径的 最小 分数。

注意：

    一条路径指的是两个城市之间的道路序列。
    一条路径可以 多次 包含同一条道路，你也可以沿着路径多次到达城市 1 和城市 n 。
    测试数据保证城市 1 和城市n 之间 至少 有一条路径。


 """

class Solution:
	def minScore(self, n: int, roads: List[List[int]]) -> int:
		roads.sort(key=lambda e: e[2])#按照road distance 排序 O(nlog(n))
		nodemap=collections.defaultdict(set)
		# 使用hash表维护每个节点可以到达的节点
		for p in roads:
			nodemap[p[0]].add(p[1])
			nodemap[p[1]].add(p[0])
		# print(nodemap)
		# 使用hash表维护从1开始能到达的节点
		gotomap=collections.defaultdict(int)
		gotomap[1]=1
		q=collections.deque([1])
		while q:
			# 队列为空则1开始能到达的路径遍历完成
			node=q.popleft()
			# 对当前节点能到达的路径进行一次遍历
			for i in nodemap[node]:
				# 当前节点还未到达过，入队
				if gotomap[i]==0:
					gotomap[i]=1
					q.append(i)
		# print(gotomap)
		# 从最小值开始遍历，判断最小路径的两个端点是否能从1开始到达
		for p in roads:
			if gotomap[p[1]]==1 or gotomap[p[0]]==1:
				return p[2]

if __name__ == "__main__":
	s=Solution().minScore
	ans=s(9,[[1,7,1785],[7,4,1631],[3,8,5356],[4,2,9794],[5,6,7223],[8,9,1128],[2,3,8248]])	
	print(ans)
