""" 给你一个字符串 s ，它每一位都是 1 到 9 之间的数字组成，同时给你一个整数 k 。

如果一个字符串 s 的分割满足以下条件，我们称它是一个 好 分割：

    s 中每个数位 恰好 属于一个子字符串。
    每个子字符串的值都小于等于 k 。

请你返回 s 所有的 好 分割中，子字符串的 最少 数目。如果不存在 s 的 好 分割，返回 -1 。

注意：

    一个字符串的 值 是这个字符串对应的整数。比方说，"123" 的值为 123 ，"1" 的值是 1 。
    子字符串 是字符串中一段连续的字符序列。
 """

# #字符串 #子数组 #贪心

""" 贪心去做，统计k长度之后，按照k长度进行拆分，大于k回退一位 """
class Solution:
	def minimumPartition(self, s: str, k: int) -> int:
		diglen=0
		kt=k
		# 统计k长度
		while(kt>0):
			kt//=10
			diglen+=1
		# 1位单独处理
		if diglen==1:
			for i in s:
				if int(i)>k:
					return -1
			return len(s)
		split=[]
		i=0
		# 按照k长度进行拆分
		while(i<len(s)):
			stmp=s[i:i+diglen]
			if int(stmp)<=k:
				split.append(stmp)
				i+=diglen
			else:
				# 拆分结果大于k就回退一位
				split.append(s[i:i+diglen-1])
				i+=diglen-1
		return len(split)

if __name__ == "__main__":
	s=Solution().minimumPartition
	print(s("111111",1))

