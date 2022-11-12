class Solution:
	def twoSum(self, nums: List[int], target: int) -> List[int]:
		for i,vi in enumerate(nums):
			for j in range(i,len(nums)):
				vj=nums[j]
				if (target-vi)==vj:
					return [i,j]