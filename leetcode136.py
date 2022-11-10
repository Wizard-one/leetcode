# hash table
from typing import List
import collections
class Solution:
	def singleNumber(self, nums: List[int]) -> int:
		m=collections.Counter(nums)
		for key in m:
			if m[key]==1:
				return key

if __name__ == "__main__":
	s=Solution()
	a=[2,2,1,2]
	s.singleNumber(a)