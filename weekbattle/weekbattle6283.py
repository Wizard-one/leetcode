from lib.test import *
""" 
6283. 正整数和负整数的最大计数


给你一个按 非递减顺序 排列的数组 nums ，返回正整数数目和负整数数目中的最大值。

    换句话讲，如果 nums 中正整数的数目是 pos ，而负整数的数目是 neg ，返回 pos 和 neg二者中的最大值。

注意：0 既不是正整数也不是负整数。
 """
class Solution:
	def maximumCount(self, nums: List[int]) -> int:
		neg=0
		pos=0
		for i in nums:
			if i>0:
				pos+=1
			elif i<0:
				neg+=1
		return max(neg,pos)