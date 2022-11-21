import collections
from typing import List	

class Solution:
	# #广度优先搜索 [[leetcode542]] 

	""" 
	整体思路与 542 类似，不同点在于line:27 记录一次出队完成然后再更新状态t
	"""
	def orangesRotting(self, grid: List[List[int]]) -> int:
		m=len(grid)
		n=len(grid[0])
		roloc=[]
		for i in range(m):
			for j in range(n):
				if grid[i][j]==2:
					roloc.append((i,j))
		walked=set(roloc)
		for i in range(m):
			for j in range(n):
				if grid[i][j]==0:
					walked.add((i,j))
		t=-1#初始时间认为是超级源让t=0现有橙子从1->2, 也可以认为是搜索到最后一个节点没有可污染的节点，多出一个t++
		que=collections.deque(roloc)
		while que:
			curentrot=len(que)
			for _ in range(curentrot):
				(i,j)=que.popleft()
				for ni,nj in [(i+1,j),(i-1,j),(i,j+1),(i,j-1)]:
					if (ni>=0 and ni<m) and (nj>=0 and nj<n) and (ni,nj) not in walked:
						walked.add((ni,nj))
						que.append((ni,nj))
						grid[ni][nj]=2
			t+=1
		for i in range(m):
			for j in range(n):
				if grid[i][j]==1:
					return -1
		if len(roloc)==0:
			return 0
		else:
			return t

if __name__ == "__main__":
	ma=[[0]]
	s=Solution().orangesRotting
	ans=s(ma)
	print(ans)
