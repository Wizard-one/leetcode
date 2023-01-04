from lib.test import *
# [[77]] #回溯 [[46]] [[78]] [[90]]
""" 47. 全排列II
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
"""
class Solution:

	"""
	同46一样，但是多了重复原则，那么先进行一次排序，然后针对重复元素只选择一次

	对于回溯的问题而言排序的时间消耗可以忽略不记
	"""
	def __init__(self) -> None:
		self.ans=[]

	def permuteUnique(self, nums: List[int]) -> List[List[int]]:
		nums.sort()#存在重复元素先进行排序，防止重复元素乱序出现
		
		wait=nums
		walk=[]
		self.backtrack(wait,walk)
		return self.ans

	def backtrack(self,wait:List[int],walk:List[int]):
		""" 
		walk : 记录走过的路径
		"""
		if not wait:
			# 回溯的终止条件, 所有路径都走完了
			self.ans.append(walk.copy())
			return
		for i in range(len(wait)):
			# 重复元素只在出现的第一次进行选择，其余都跳过
			if i>0 and wait[i-1]==wait[i]:
				continue
			walk.append(wait[i])
			nextwait=wait.copy()#选择
			nextwait.remove(wait[i])
			self.backtrack(nextwait,walk)#向下搜索
			walk.pop()# 撤销选择


if __name__ == "__main__":
	s=Solution().permuteUnique
	print(s([1,2,2]))