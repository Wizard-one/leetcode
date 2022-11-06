from typing import List
def containsDuplicate(self, nums: List[int]) -> bool:
	nums=nums.sort()
	a=nums[0]
	for i in range(1,len(nums)):
		if a==nums[i]:
			return True
		else:
			a=nums[i]
	return False
            