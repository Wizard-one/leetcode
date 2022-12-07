from typing import List
# [[77]] #回溯
""" 46. 全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
"""
class Solution:

	"""
	经典的回溯题目
	"""
	def __init__(self) -> None:
		self.ans=[]

	def permute(self, nums: List[int]) -> List[List[int]]:
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
			walk.append(wait[i])
			nextwait=wait.copy()#选择
			nextwait.remove(wait[i])
			self.backtrack(nextwait,walk)#向下搜索
			walk.pop()# 撤销选择

if __name__ == "__main__":
	s=Solution().permute
	print(s([1,2,3]))