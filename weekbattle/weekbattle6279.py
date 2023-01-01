from lib.test import *

""" 6279. 数组乘积中的不同质因数数目

给你一个正整数数组 nums ，对 nums 所有元素求积之后，找出并返回乘积中 不同质因数 的数目。

注意：

    质数 是指大于 1 且仅能被 1 及自身整除的数字。
    如果 val2 / val1 是一个整数，则整数 val1 是另一个整数 val2 的一个因数。
 """

# #数学 #质数
class Solution:

	def __init__(self):
		"""
		docstring
		"""
		self.ans=set()

	# 检查是否为质因数
	def prime(self,num):
		while(num%2==0):
			self.ans.add(2)
			num=num//2
		i=3
		while(i<num):
			if num%i==0:
				self.ans.add(i)
				num//=i
			else:
				i+=2
		if num!=1:
			self.ans.add(num)
			
	# 对数组中每一个元素检查质因数
	def distinctPrimeFactors(self, nums: List[int]) -> int:
		for n in nums:
			self.prime(n)

		print(self.ans)
		return len(self.ans)


if __name__ == "__main__":
	s=Solution().distinctPrimeFactors
	print(s([2,4,8,16]))
	