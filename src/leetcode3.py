# #hash #滑动窗 #字符串 #子串

""" 
无重复字符的最长子串

给一个字符串s 给出最长无重复子串
"""
class Solution:
	def lengthOfLongestSubstring(self, s: str) -> int:
		if not s:return 0
		win=set()#滑动窗为hash表
		winlenmax=0
		left=0#窗从左向右滑动，出队发生在左侧
		for i in range(len(s)):
			# 先将当前字符从滑动窗内向左出队
			while s[i] in win:
				winlenmax=max([winlenmax,len(win)])
				win.remove(s[left])
				left+=1
			# 然后从右侧入队
			win.add(s[i])
		while s[i] in win:
			winlenmax=max([winlenmax,len(win)])
			win.remove(s[left])
			left+=1
		return winlenmax

if __name__ == "__main__":
	s=Solution().lengthOfLongestSubstring
	print(s("pwwkew"))