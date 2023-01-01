from lib.test import *

"""438. 找到字符串中所有字母异位词
 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。 """

# #字符串 #hash

""" 异位词对应hash表来维护一个异位词，子串其实位置对应用滑动窗滑动 """
class Solution:
	def findAnagrams(self, s: str, p: str) -> List[int]:
		phash=collections.Counter(p)#偷懒直接调库建立hash表，为了性能可以使用手写hash表
		m=len(p)
		l=0
		ans=[]
		for l in range(len(s)-m+1):
			# 滑动窗滑动
			tmp=collections.Counter(s[l:l+m])
			if tmp==phash:
				ans.append(l)
		return ans
		