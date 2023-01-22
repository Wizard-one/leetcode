from lib.test import *
""" 
2546. 执行逐位运算使字符串相等

给你两个下标从 0 开始的 二元 字符串 s 和 target ，两个字符串的长度均为 n 。你可以对 s 执行下述操作 任意 次：

    选择两个 不同 的下标 i 和 j ，其中 0 <= i, j < n 。
    同时，将 s[i] 替换为 (s[i] OR s[j]) ，s[j] 替换为 (s[i] XOR s[j]) 。

例如，如果 s = "0110" ，你可以选择 i = 0 和 j = 2，然后同时将 s[0] 替换为 (s[0] OR s[2] = 0 OR 1 = 1)，并将 s[2] 替换为 (s[0] XOR s[2] = 0 XOR 1 = 1)，最终得到 s = "1110" 。

如果可以使 s 等于 target ，返回 true ，否则，返回 false 。 """

# #位运算
class Solution:
	""" 做一下00 01 10 11 的状态转化图可以发现 00 只能转换为 00, 01 10 11 都可以相互转化，
	所以 target 中全0 s 有1 则不能相互转化 同理 s全零 target 有1不可以相互转化
	  """
	def makeStringsEqual(self, s: str, target: str) -> bool:
		tcnt=collections.Counter(target)
		scnt=collections.Counter(s)
		if (tcnt["1"]==0 and scnt["1"]!=0) or tcnt["1"]!=0 and scnt["1"]==0 :
			return False 
		return True

if __name__ == "__main__":
	s=Solution().makeStringsEqual
	print(s("0010101010","0000000000"))