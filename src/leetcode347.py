from lib.test import *

# #排序 #hash


class Solution:
	""" 直接用API解决 """
	def topKFrequent(self, nums: List[int], k: int) -> List[int]:
		c=collections.Counter(nums)
		
		return [i[0] for i in c.most_common(k)]

if __name__ == "__main__":
	s=Solution().topKFrequent
	ans=s([1,1,1,2,2,3],2)
	print(ans)
