from lib.test import *

""" 给你一个整数数组 nums 和一个整数 k ，请你返回 nums 中 好 子数组的数目。

一个子数组 arr 如果有 至少 k 对下标 (i, j) 满足 i < j 且 arr[i] == arr[j] ，那么称它是一个 好 子数组。

子数组 是原数组中一段连续 非空 的元素序列。 """

class Solution:

	def __init__(self):
		"""
		docstring
		"""
		self.goodcnt=0

	def select(self,nums:List[int],k:int,r:int,l:int,cnt:int,hashtable:collections.Counter):
		"""
		docstring
		"""
		if len(nums)==1:
			return
		hashtable.update([nums[r]])
		if hashtable[nums[r]]>=2:
			cnt+=hashtable[nums[r]]-1
		if cnt>=k:
			self.goodcnt+=1
		self.select(nums,k,r+1,l,cnt,hashtable)
		self.select(nums,k,r,l+1,cnt,hashtable)


	def countGood(self, nums: List[int], k: int) -> int:
		hashtable=collections.Counter()
		r,l=0,0
		cnt=0
		goodcnt=0


		while(r<len(nums)):
			hashtable.update([nums[r]])
			if hashtable[nums[r]]>=2:
				cnt+=hashtable[nums[r]]-1
			while(cnt>=k):
				goodcnt+=1
				if hashtable[nums[l]]>=2:
					cnt-=hashtable[nums[l]]-1
				hashtable.subtract([nums[l]])
				l+=1
			r+=1
		return cnt

if __name__ == "__main__":
	s=Solution().countGood
	print(s([3,1,4,3,2,2,4],2))


