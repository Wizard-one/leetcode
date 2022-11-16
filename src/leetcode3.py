# #hash #滑动窗
class Solution:
	def lengthOfLongestSubstring(self, s: str) -> int:
		if not s:return 0
		b = 0
		win = set()
		n = len(s)
		max_len = 0
		cur_len = 0
		for i in range(n):
			cur_len += 1
			while (s[i] in win):
				win.remove(s[b])
				b += 1
				cur_len -= 1
			if cur_len > max_len:
				max_len = cur_len
			win.add(s[i])
		return max_len
