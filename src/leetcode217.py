from typing import List


""" 217. 存在重复元素
给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。 
 """

# #hash #排序

""" 排序很显然，hash表也很显然，使用 collections.Counter 即可 """
def containsDuplicate(self, nums: List[int]) -> bool:
	nums=nums.sort()
	a=nums[0]
	for i in range(1,len(nums)):
		if a==nums[i]:
			return True
		else:
			a=nums[i]
	return False
            