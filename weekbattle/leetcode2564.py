from lib.test import *
""" 给你一个 二进制字符串 s 和一个整数数组 queries ，其中 queries[i] = [firsti, secondi] 。

对于第 i 个查询，找到 s 的 最短子字符串 ，它对应的 十进制值 val 与 firsti 按位异或 得到 secondi ，换言之，val ^ firsti == secondi 。

第 i 个查询的答案是子字符串 [lefti, righti] 的两个端点（下标从 0 开始），如果不存在这样的子字符串，则答案为 [-1, -1] 。如果有多个答案，请你选择 lefti 最小的一个。

请你返回一个数组 ans ，其中 ans[i] = [lefti, righti] 是第 i 个查询的答案。

子字符串 是一个字符串中一段连续非空的字符序列。 """


# #位运算
class Solution:
	""" 
	val ^ first = second -> val ^ first ^ first = second ^ first -> val = second ^ first

	即 s 在int 范围内的数处理为  int 然后与 queries 进行查询
	 
	查询过程使用hash表实现
	"""
	def substringXorQueries(self, s: str, queries: List[List[int]]) -> List[List[int]]:
		n=len(s)
		tab=dict()
		for l in range(n):
			val=0
			# 根据给定的数据范围得知，数据长度不超过 2^30  
			for r in range(l,min(l+30,n)):
				# 数据一位一位进入，例如 110 右侧进入一位1 实现过程为 110<<1=1100 | 0001 =1101
				val=(val<<1) | (ord(s[r])-ord("0"))
				# 当val不在tab or val 对应长度更加长时进行数据update
				if val not in tab or  r-l < tab[val][1]-tab[val][0]:
					tab[val]=(l,r)
		ans=[]
		for q in queries:
			tmp=q[1]^q[0]#直接查询结果
			ans.append(tab.get(tmp,(-1,-1)))
		return ans


		

if __name__ == "__main__":
	s=Solution().substringXorQueries
	print(s("0101",[[12,8]]))
	