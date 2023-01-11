from lib.test import *

""" 139. 单词拆分
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用 
"""

# #字符串 #动态规划 #前缀
""" 
不太一样的动态规划，首先使用两个指针来定义一个字符串的子串

dp[i] 标记 s[:i] 是否合法

核心问题是 如果一个字符串 s[:i], and s[i:j] 合法 那么 s[:j] 都合法，
所以能用dp[j] 来标记前缀串是否合法，只需要遍历所有子串即可

dp[0]: 边界条件,空字符串合法


"""
class Solution:
	def wordBreak(self, s: str, wordDict: List[str]) -> bool:
		dp=[False]*(len(s)+1)#j会遍历到字符串结尾
		dp[0]=True
		for i in range(len(s)):
			# slice 要遍历到结尾
			for j in range(i+1,len(s)+1):
				# 遍历所有子串 i:j
				if dp[i] and (s[i:j] in wordDict):
					dp[j]=True
		# 完成所有子串的遍历之后，只要最后一位为True 就说明整个字符串都合法
		return dp[-1]



if __name__ == "__main__":
	s=Solution().wordBreak
	print(s("aaaasaas",["aa","s"]))
		