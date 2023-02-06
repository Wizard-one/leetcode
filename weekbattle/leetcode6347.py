from lib.test import *
""" 给你一个下标从 0 开始的字符串数组 words 以及一个二维整数数组 queries 。

每个查询 queries[i] = [li, ri] 会要求我们统计在 words 中下标在 li 到 ri 范围内（包含 这两个值）并且以元音开头和结尾的字符串的数目。

返回一个整数数组，其中数组的第 i 个元素对应第 i 个查询的答案。

注意：元音字母是 'a'、'e'、'i'、'o' 和 'u' 。 """

# #前缀和
class Solution:
	""" 将符合条件的字符串设置为1 不符合为0
	问题就转换为计算某一段区间的和, 既然是区间求和就使用前缀和来解决
	查询结果= presum[r+1]-presum[l]
	"""
	def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
		n=len(words)
		vow=[0]*n
		ch={'a','e','i','o','u'}
		# 字符串转换
		for i in range(n):
			if words[i][0] in ch and words[i][-1] in ch:
				vow[i]=1
		presum=[0]*(n+1)
		# 计算前缀和
		for i in range(n):
			presum[i+1]=presum[i]+vow[i]
		m=len(queries)
		ans=[0]*m
		# 通过前缀和计算查询结果
		for i in range(m):
			l=queries[i][0]
			r=queries[i][1]+1
			ans[i]=presum[r]-presum[l]
		return ans

if __name__ == "__main__":
	s=Solution().vowelStrings
	print(s(["aba","bcb","ece","aa","e"],[[0,2],[1,4],[1,1]]))