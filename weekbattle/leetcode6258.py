"""6258. 数组中最长的方波
给你一个整数数组 nums 。如果 nums 的子序列满足下述条件，则认为该子序列是一个 方波 ：

    子序列的长度至少为 2 ，并且
    将子序列从小到大排序 之后 ，除第一个元素外，每个元素都是前一个元素的 平方 。

返回 nums 中 最长方波 的长度，如果不存在 方波 则返回 -1 。

子序列 也是一个数组，可以由另一个数组删除一些或不删除元素且不改变剩余元素的顺序得到。
"""
# #搜索 #递归 #子数组 #子序列
from lib.test import *

def dfs(x:int,nums:Set[int])->int:
	""" 直接平方去搜索，由于int 最大 2^32 也就是说平方次数k必然小于
	2^(2^(k-1)), 对应循环次数不超过 (loglog(len(nums)))
	"""
	if x not in nums:
		# hash 表搜索始终只用O(1)
		return 0
	else:
		return 1+dfs(x*x,nums)#递归深度不超过(loglog(len(nums)))

class Solution:
	""" 本质上不需要维护子数组本身，只需要记录子数组长度，这其中就减少了变量的维护 
	
	"""
	def longestSquareStreak(self, nums: List[int]) -> int:
		s=set(nums)#先用hash表清除相同元素，显然相同元素不影响结果，然后hash表搜索元素也是O(1) 的
		# 子序列+排序=子集
		maxcount=0
		for x in s:
			maxcount=max(maxcount,dfs(x,s))
		if maxcount==1:
			maxcount=-1
		return maxcount



if __name__ == "__main__":
	s=Solution().longestSquareStreak
	# ans=s([4,3,6,16,8,2])
	# print(ans)
	# ans=s([2,4,16])
	# print(ans)
	# ans=s([2,3,4,5,6,8,9,27,16,81,6561])
	ans=s([5,12,3,10,4,11,4,16,11])
	print(ans)