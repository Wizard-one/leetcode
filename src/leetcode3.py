# #hash #滑动窗
class Solution:
	def lengthOfLongestSubstring(self, s: str) -> int:
		if not s:return 0
		win=set()
		winlenmax=0
		left=0
		for i in range(len(s)):
			while s[i] in win:
				winlenmax=max([winlenmax,len(win)])
				win.remove(s[left])
				left+=1
			win.add(s[i])
		while s[i] in win:
			winlenmax=max([winlenmax,len(win)])
			win.remove(s[left])
			left+=1
		return winlenmax

if __name__ == "__main__":
	s=Solution().lengthOfLongestSubstring
	print(s("pwwkew"))