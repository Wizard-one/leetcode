
# #hash #真值表

""" 290. 单词规律
给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
 """

"""
构建一个pattern->s 的map 这样必然是hash table问题

如此一来要处理的要点有
- value 不能对应多个key
- 什么情况下扩展key
"""
class Solution:
	def wordPattern(self, pattern: str, s: str) -> bool:
		d=dict()
		s=s.split()
		if len(pattern)!=len(s):
			return False
		for i in range(len(pattern)):
			# pattern in d.key, s[i] in d.values 列出真值表就能分清楚情况
			if pattern[i] not in d and s[i] not in d.values():
				d.update({pattern[i]:s[i]})
			elif pattern[i] in d and d[pattern[i]]==s[i]:
				continue
			else:
				return False
		
		return True
	
if __name__ == "__main__":
	s=Solution().wordPattern
	ans=s("abba","dog cay cay dog")
	print(ans)