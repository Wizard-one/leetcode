from lib.test import *

""" 997. 找到小镇的法官
小镇里有 n 个人，按从 1 到 n 的顺序编号。传言称，这些人中有一个暗地里是小镇法官。

如果小镇法官真的存在，那么：

	小镇法官不会信任任何人。
	每个人（除了小镇法官）都信任这位小镇法官。
	只有一个人同时满足属性 1 和属性 2 。

给你一个数组 trust ，其中 trust[i] = [ai, bi] 表示编号为 ai 的人信任编号为 bi 的人。

如果小镇法官存在并且可以确定他的身份，请返回该法官的编号；否则，返回 -1 。

"""

# #有向图 #hash #easy
class Solution:
	""" 
	这边做了一个hash表 分别记录数组的头尾 只要检查头为0 尾为n-1 即可

	这也可以视为一张有向图，头是入度，尾是出度
	"""
	def findJudge(self, n: int, trust: List[List[int]]) -> int:
		trustpeo=collections.defaultdict(int)
		betrustpeo=collections.defaultdict(int)
		for t in trust:
			trustpeo[t[0]]+=1
			betrustpeo[t[1]]+=1
		for i in range(1,n+1):
			if trustpeo[i]==0 and betrustpeo[i]==n-1:
				return i
		return -1
	
	def findJudge1(self, n: int, trust: List[List[int]]) -> int:
		# 采用出入度来计数
		inDegrees = collections.Counter(y for _, y in trust)
		outDegrees = collections.Counter(x for x, _ in trust)
		return next((i for i in range(1, n + 1) if inDegrees[i] == n - 1 and outDegrees[i] == 0), -1)

