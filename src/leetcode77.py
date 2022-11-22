from typing import List

# #组合数 #回溯 #递归

class Solution:

	def __init__(self):
		"""
		docstring
		"""
		self.ans=[]

	def combine(self, n: int, k: int) -> List[List[int]]:
		self.backtracker(n,k,1,[])
		return self.ans

	def backtracker(self,n:int,k:int,start:int,result:List[List[int]]):
		"""
		docstring
		"""
		if k==0:
			self.ans.append(result.copy())
			return
		for i in range(start,n-k+2):#选择 剪枝体现在当余下的选择数不足时就停止迭代
			result.append(i)
			self.backtracker(n,k-1,i+1,result)
			result.pop()
		
if __name__ == "__main__":
	s=Solution().combine
	ans=s(4,3)
	print(ans)