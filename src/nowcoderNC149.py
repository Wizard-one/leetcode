from lib.test import *

""" 描述
给你一个文本串 T ，一个非空模板串 S ，问 S 在 T 中出现了多少次

数据范围：1≤len(S)≤500000,1≤len(T)≤10000001≤len(S)≤500000,1≤len(T)≤1000000
要求：空间复杂度 O(len(S))O(len(S))，时间复杂度 O(len(S)+len(T))O(len(S)+len(T)) """
# #KMP
class Solution:
	""" 做一个最大公共前缀后缀串表
	next[i]  存储 s[:i] 的最大公共前缀后缀长度
	"""
	def build(self,s:str):
		n=len(s)
		nxt=[0]*n
		nxt[0]=-1
		l=-1
		r=0
		while r<n-1:
			if l<0 or s[l]==s[r]:
				l+=1
				r+=1
				nxt[r]=l
			else:
				l=nxt[l]
		return nxt

	def kmp(self , S: str, T: str) -> int:
		# write code here
		nxt=self.build(S)
		n=len(S)
		m=len(T)
		i,j=0,0
		cnt=0#记录出现次数
		while j<m:
			if i<0 or S[i]==T[j]:
				i+=1
				j+=1
			else:
				i=nxt[i]
			if i==n:
				# 当S匹配到结尾，当前匹配完成
				cnt+=1
				i=nxt[i-1]+1#模式串回退到上一个位置，+1是因为要匹配下一个字母
		return cnt
		

if __name__ == "__main__":
	s=Solution().kmp
	print(s("ababab","abababab"))