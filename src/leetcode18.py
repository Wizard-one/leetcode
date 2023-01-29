from lib.test import *

""" 18. 四数之和
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

    0 <= a, b, c, d < n
    a、b、c 和 d 互不相同
    nums[a] + nums[b] + nums[c] + nums[d] == target

你可以按 任意顺序 返回答案 。 """

# [[15]] #数组 #双指针

class Solution:
	""" 解法类似3sum
	需要注意的是2每一层循环不能有重复数字，性能优化就是剪枝
	"""
	def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
		if len(nums)<4:
			return []
		nums.sort()
		ans=list()
		for i in range(len(nums)-3):
			# 每个重复数字只循环一次
			if i>0 and nums[i]==nums[i-1]:
				continue
			for j in range(i+1,len(nums)-2):
				# 每个重复数字只循环一次
				if j>i+1 and nums[j]==nums[j-1]:
					continue
				res=target-nums[i]-nums[j]
				left=j+1
				right=len(nums)-1
				# 双指针搜索
				while(left<right):
					if nums[left]+nums[right]==res:
						ans.append([nums[i],nums[j],nums[left],nums[right]])
						# 每个重复数字只循环一次
						while left < right and nums[left] == nums[left + 1]:
							left += 1
						left += 1
						while left < right and nums[right] == nums[right - 1]:
							right -= 1
						right -= 1
					elif nums[left]+nums[right]>res:
						right-=1
					else:
						left+=1
		return ans
