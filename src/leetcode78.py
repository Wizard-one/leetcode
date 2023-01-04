from lib.test import *

"""
78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
"""

# #回溯 #数组 [[46]]
class Solution:
	"""
	使用回溯记录当前遍历的所有路径，向下传递选择时只传递当前栈未选择过的元素
	  """

	def __init__(self) -> None:
		self.ans=[[]]

	def subsets(self, nums: List[int]) -> List[List[int]]:
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
			walk.append(wait[i])
			self.ans.append(walk.copy())
			nextwait=wait[i+1:].copy()#**核心**：向下搜索时对于已经选择过的元素不再重复选择
			self.backtrack(nextwait,walk)#向下搜索
			walk.pop()# 撤销选择

		

if __name__ == "__main__":
	s=Solution().subsets
	print(s([1,2,3]))