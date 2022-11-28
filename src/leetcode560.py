from typing import List
""" 和为k的子数组 """

# #子数组 [[56]] #hash #前缀和
# 子数组使用和的大小来建立hash表, 
class Solution:
	def subarraySum(self, nums: List[int], k: int) -> int:
		mp={0:1}# 子数组使用和的大小来建立hash表
		count=0
		pre=0
		for i in range(len(nums)):
			pre+=nums[i]
			# 满足条件的就是pre[i]-pre[j-1]=k, j<i pre为前缀和
			if(mp.get(pre-k)):
				count+=mp.get(pre-k)
			if mp.get(pre):
				mp[pre]+=1
			else:
				mp.update({pre:1})

		return count

if __name__ == "__main__":
	s=Solution().subarraySum
	ans=s([1,1,1,2,1,2,5,3,2],5)
	print(ans)