from lib.test import *
"""14. 最长公共前缀

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
"""

# #字符串 time: O(mn) space: O(1)
class Solution:

	""" 直接纵向扫描，不相等的时候弹出 """
	def Getlen(self,minlen,strs):
		i=-1#为空就是先pad一下
		for i in range(minlen):
			for j in range(len(strs)):
				if strs[j][i]!=strs[0][i]:
					# 不相等的时候弹出
					return i
		return i+1#全部相等就返回全部

	def longestCommonPrefix(self, strs: List[str]) -> str:
		minlen=len(strs[0])
		for s in strs:
			minlen=min(len(s),minlen)
		i=self.Getlen(minlen,strs)
		return strs[0][:i]

if __name__ == "__main__":
	s=Solution().longestCommonPrefix
	ans=s(["do","flower","flower"])
	print(ans)