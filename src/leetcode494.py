from lib.test import *
""" 494. 目标和

给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

    例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。

返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。 """

# #记忆化搜索 #回溯
class Solution:
	""" 这边给出一个记忆化搜索的回溯解法 """

	def travel(self,nums,idx,target,sum):
		"""
		docstring
		"""
		if idx==len(nums):
			if sum==target:
				return 1
			else:
				return 0
		# 画一下递归树可以发现 memo 保存的key 需要sum+idx 两个组成部分
		if (sum,idx) in self.memo:
			return self.memo[(sum,idx)]
		# 选择就是sum+nums[idx] or sum-nums[idx]
		self.memo[(sum,idx)]=self.travel(nums,idx+1,target,sum+nums[idx])
		self.memo[(sum,idx)]+=self.travel(nums,idx+1,target,sum-nums[idx])
		return self.memo[(sum,idx)]


	def findTargetSumWays(self, nums: List[int], target: int) -> int:
		self.memo=collections.defaultdict(int)
		return self.travel(nums,0,target,0)

if __name__ == "__main__":
	s=Solution().findTargetSumWays
	print(s([1,1,1,1,1],3))