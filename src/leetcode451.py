from lib.test import *

"""451. 根据字符出现频率排序

 给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的 频率 是它出现在字符串中的次数。

返回 已排序的字符串 。如果有多个答案，返回其中任何一个。 """

# #排序 #字符串 #统计 #hash表

class Solution:
	def frequencySort(self, s: str) -> str:
		c=collections.Counter(s)
		c=c.most_common()
		slist=[]
		for v,n in c:
			for i in range(n):
				slist.append(v)
		
		return "".join(slist)


if __name__ == "__main__":
	s=Solution().frequencySort
	s("tree")