from typing import List
import collections

""" 169. 多数元素
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。
"""


# #hash #计数 time: O(n) space: O(n)
class Solution:
	""" 简单就是hash表 """
	def majorityElement(self, nums: List[int]) -> int:
		a=collections.Counter(nums)
		for i in a:
			if a[i]>len(nums)//2:
				return i
			

if __name__ == "__main__":
	s=Solution().majorityElement
	a=s([3,2,3,3,1])
	print(a)