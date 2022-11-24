from typing import List
import collections

# #hash #计数
class Solution:
	def majorityElement(self, nums: List[int]) -> int:
		a=collections.Counter(nums)
		for i in a:
			if a[i]>len(nums)//2:
				return i
			

if __name__ == "__main__":
	s=Solution().majorityElement
	a=s([3,2,3,3,1])
	print(a)