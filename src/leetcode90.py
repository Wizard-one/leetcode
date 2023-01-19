from lib.test import *

"""
90. 子集 II

给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
"""

# #回溯 #数组 [[78]]
class Solution:
	"""
	相比78多了重复元素，为了避免记录顺序需要先对给定数组排序，然后不记录已经在集合中的数组
	
	，使用回溯记录当前遍历的所有路径，向下传递选择时只传递当前栈未选择过的元素
	  """

	def __init__(self) -> None:
		self.ans=[[]]

	def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
		nums.sort()# 多一步排序
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
			return

		for i in range(len(wait)):
			# 由于已经预先排序，遇到相等的不记录已经在列表中的组合
			if i>0 and wait[i]==wait[i-1]:
				continue
			walk.append(wait[i])
			self.ans.append(walk.copy())
			nextwait=wait[i+1:].copy()#**子集问题核心**：向下搜索时对于已经选择过的元素不再重复选择
			self.backtrack(nextwait,walk)#向下搜索
			walk.pop()# 撤销选择

		

if __name__ == "__main__":
	s=Solution().subsetsWithDup
	print(s([1,2,2]))