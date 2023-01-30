# #hash
from typing import List
import collections
""" 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
 """
class Solution:
	""" 直接hash表 """
	def singleNumber(self, nums: List[int]) -> int:
		m=collections.Counter(nums)
		for key in m:
			if m[key]==1:
				return key

if __name__ == "__main__":
	s=Solution()
	a=[2,2,1,2]
	s.singleNumber(a)