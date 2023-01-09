from lib.test import *

import math

""" 2530. 执行 K 次操作后的最大分数


给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。你的 起始分数 为 0 。

在一步 操作 中：

    选出一个满足 0 <= i < nums.length 的下标 i ，
    将你的 分数 增加 nums[i] ，并且
    将 nums[i] 替换为 ceil(nums[i] / 3) 。

返回在 恰好 执行 k 次操作后，你可能获得的最大分数。

向上取整函数 ceil(val) 的结果是大于或等于 val 的最小整数。
 """

# #累计和 #数组


def HeapAdjust(nums:List[int],start:int,end:int):
	""" 大顶堆的调整 """
	parent=start
	child=start*2+1
	while(child<=end):
		if child<end and nums[child]<nums[child+1]:
			child+=1
		if nums[parent]>nums[child]:
			return
		else:
			temp=nums[child]
			nums[child]=nums[parent]
			nums[parent]=temp
			parent=child
			child=child*2+1
			 
class Solution:

	""" 
	直接将数组维护为一个大顶堆，每次摘取完成后重新调整堆成为一个大顶堆
	 """
	def maxKelements(self, nums: List[int], k: int) -> int:
		su=0
		# 预先排序，去除长度超出部分
		nums.sort(reverse=True)
		nums=nums[:k]

		# 二分优化
		for i in range(k):
			su+=nums[0]
			# 摘取
			nums[0]=math.ceil(nums[0]/3)
			# 从堆顶开始向下调整一次
			HeapAdjust(nums,0,len(nums)-1)
		return su


if __name__ == "__main__":
	s=Solution().maxKelements
	print(s([1,10,3,3,3],6))