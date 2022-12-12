from typing import List

# #组合数 #回溯 #递归
""" 
77. 组合

给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。
"""
class Solution:

	def __init__(self):
		self.ans=[]

	def combine(self, n: int, k: int) -> List[List[int]]:
		self.backtracker(n,k,1,[])
		return self.ans

	def backtracker(self,n:int,k:int,start:int,result:List[List[int]]):
		"""	标准回溯，使用回溯的最大原因是要记录走过的所有路径

		Parameters
		----------
		n : int
			给定的范围
		k : int
			将要选择k个数
		start : int
			从start开始进行选择
		result : List[List[int]]
			当前选择的结果序列
		"""		
		if k==0:
			# 当要选择数没有则终止同时返回
			self.ans.append(result.copy())
			return
		for i in range(start,n-k+2):#选择 剪枝体现在当余下的选择数不足时就停止迭代
			result.append(i)#路径选择并保存
			self.backtracker(n,k-1,i+1,result)#向下回溯，需要选择的数k-1 从下一个数i+1 开始选择
			result.pop()#撤销选择，进入另一个决策分支
		
if __name__ == "__main__":
	s=Solution().combine
	ans=s(4,3)
	print(ans)