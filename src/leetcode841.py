from lib.test import *
""" 
841. 钥匙和房间

有 n 个房间，房间按从 0 到 n - 1 编号。最初，除 0 号房间外的其余所有房间都被锁住。你的目标是进入所有的房间。然而，你不能在没有获得钥匙的时候进入锁住的房间。

当你进入一个房间，你可能会在里面找到一套不同的钥匙，每把钥匙上都有对应的房间号，即表示钥匙可以打开的房间。你可以拿上所有钥匙去解锁其他房间。

给你一个数组 rooms 其中 rooms[i] 是你进入 i 号房间可以获得的钥匙集合。如果能进入 所有 房间返回 true，否则返回 false。

"""

# #有向图 #队列 #广度优先搜索 #hash #深度优先搜索
class Solution:
	""" 
	题目给的列表去除自身之后就是每个节点的出度列表，那么问题转化为是否能从0开始遍历整张图

	这边采用广度优先搜索来对每个节点的出度进行搜索, 通过一张hash表来维护该节点是否到达

	最后只需要遍历整张hash表来检查是否有节点没有到达过即可
	"""
	def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
		# 使用hash表维护从0开始能到达的节点
		gotomap=collections.defaultdict(int)
		gotomap[0]=1
		q=collections.deque([0])
		while q:
			# 队列为空则1开始能到达的路径遍历完成
			node=q.popleft()# 加入一个节点所有能到达的节点那就是广度优先搜索
			# 对当前节点能到达的路径进行一次遍历
			for i in rooms[node]:
				# 当前节点还未到达过，入队
				if gotomap[i]==0:
					gotomap[i]=1
					q.append(i)
		for i in range(len(rooms)):
			if gotomap[i]==0:
				return False
		return True

	def canVisitAllRoomsDFS(self, rooms: List[List[int]]) -> bool:
		""" 
		当然问题也能用DFS来搜索
		"""
		def dfs(x:int):
			"""
			docstring
			"""
			nonlocal count
			vis.add(x)#当前节点加入已到达过节点
			count+=1
			for i in rooms[x]:
				# 对出度列表进行遍历
				if i not in vis:
					#如果遍历的当前节点还没有到达,则用DFS遍历他
					dfs(i) 
		
		vis=set()#走过的节点
		count=0#记录走过的节点数目
		dfs(0)
		return count==len(rooms)