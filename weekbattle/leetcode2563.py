from lib.test import *
"""给你一个下标从 0 开始、长度为 n 的整数数组 nums ，和两个整数 lower 和 upper ，返回 公平数对的数目 。

如果 (i, j) 数对满足以下情况，则认为它是一个 公平数对 ：

    0 <= i < j < n，且
    lower <= nums[i] + nums[j] <= upper
"""
# #二分法
class Solution:
	""" 排序不影响计数，可以视为两数之和，搜索合法范围的上下界，即
	lower-nums[i]<=nums[j]<=upper-nums[i]
	搜索的是上下界在数组中插入位置，然后对范围相减进行计数"""
	def countFairPairs1(self, nums: List[int], lower: int, upper: int) -> int:
		nums.sort()
		cnt=0
		n=len(nums)
		for i in range(n-1):
			left=bisect.bisect_left(nums,lower-nums[i],i+1,n)
			right=bisect.bisect_right(nums,upper-nums[i],i+1,n)
			cnt+=right-left
		return cnt

	def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
		nums.sort()
		cnt=0
		n=len(nums)
		# 搜索合法的下边界
		# 使用区间[left,right)
		def bisect_l(target,lo,hi):
			while(lo<hi):
				mid=lo+(hi-lo)//2
				if nums[mid]<target:
					lo=mid+1
				elif nums[mid]==target:
					hi=mid
				else:
					hi=mid
			return lo
		# 搜索目标的上边界
		def bisect_r(target,lo,hi):
			while(lo<hi):
				mid=lo+(hi-lo)//2
				if nums[mid]<target:
					lo=mid+1
				elif nums[mid]==target:
					lo=mid+1
				else:
					hi=mid
			return lo
		# print("nums l r")
		for i in range(n-1):
			# 由于区间是[left,right), 所以要包含n
			le=bisect_l(lower-nums[i],i+1,n)
			ri=bisect_r(upper-nums[i],i+1,n)
			# print(nums[i],le,ri)
			cnt+=ri-le
		return cnt

if __name__ == "__main__":
	s=Solution().countFairPairs
	print(s([0,1,7,4,4,5],3,6))