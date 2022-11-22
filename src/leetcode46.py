from typing import List
# [[77]] #回溯

class Solution:

	def __init__(self) -> None:
		self.ans=[]

	def permute(self, nums: List[int]) -> List[List[int]]:
		wait=nums
		walk=[]
		self.backtrack(wait,walk)
		return self.ans

	def backtrack(self,wait:List[int],walk:List[int]):
		if not wait:
			self.ans.append(walk.copy())
			return
		for i in range(len(wait)):
			walk.append(wait[i])
			nextwait=wait.copy()
			nextwait.remove(wait[i])
			self.backtrack(nextwait,walk)
			walk.pop()

if __name__ == "__main__":
	s=Solution().permute
	print(s([1,2,3]))