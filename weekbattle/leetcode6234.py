from typing import List
class Solution:
	def subcount(self,l:int,r:int,nums:List[int],k:int):
		for maxidx in range(l,r+1):
			if nums[maxidx]==max(nums[l:r+1]):
				break
		
		if max(nums[l:r+1])==k:
			return maxidx-l+r-maxidx+2
		else:
			for Rmaxidx in range(maxidx+1,r+1):
				if nums[Rmaxidx]==max(nums[maxidx+1:r+1]):
					break
			RsubCount=r-Rmaxidx+1
			for Lmaxidx in range(l,maxidx):
				if nums[Lmaxidx]==max(nums[l:maxidx]):
					break
			LsubCount=Lmaxidx-r+1
			return RsubCount+LsubCount

	def mod0(self,num:int,k:int):
		if num<=k and k%num==0:
			return True
		else:
			return False

	def subarrayLCM(self, nums: List[int], k: int) -> int:
		count=0
		l=0
		r=0
		for i in range(1,len(nums)):
			if (not self.mod0(nums[i],k)) and self.mod0(nums[i-1],k):
				r=i-1
				count+=self.subcount(l,r,nums,k)
			elif (not self.mod0(nums[i-1],k)) and self.mod0(nums[i],k):
				l=i
		return count

if __name__ == "__main__":
	nums = [1,2,3,6,2,7,1]
	s=Solution()
	c=s.subarrayLCM(nums,6)
	print(c)