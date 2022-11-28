
# #hash #真值表

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