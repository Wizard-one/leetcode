from typing import Optional,List,Set
from lib.test import *

# #先序遍历 #递归 #DFS #二叉树 #回溯 time: O(n^2) space: O(n) 
class Solution:
	"""
	路径总和 II

	给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

	叶子节点 是指没有子节点的节点。

	问题比较简单，就是要么深度优先搜索，要么广度优先搜索 这边选择DFS

	难点在于如何维护结果列表,结果列表不能是在None 节点进行添加，因为一个叶子节点有2个空节点
	此时添加就会发生重复添加。
	"""
	def __init__(self):
		"""
		docstring
		"""
		self.walkpath:List[int]=[]
		self.result:List[List[int]]=[]
		self.csum=0

	def dfs(self,root:Optional[TreeNode],targetSum:int):
		"""
		docstring
		"""
		if root==None:
			return
		# 用先序遍历进行DFS
		self.csum+=root.val
		# 此时其实已经完成路径结果的计算
		self.walkpath.append(root.val)
		if  root.left==None and root.right==None and self.csum==targetSum:
			# 判断是否为叶子节点,同时是否满足路径总和条件
			self.result.append(self.walkpath.copy())
		self.dfs(root.left,targetSum)
		self.dfs(root.right,targetSum)
		# 遍历完成回溯状态
		val=self.walkpath.pop()
		self.csum-=val
		return


	def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
		self.dfs(root,targetSum)
		return self.result


if __name__ == "__main__":
	i=[-1]
	T=TreeInit([5,4,11,7,-1,-1,2,-1,-1,-1,8,13,-1,-1,4,5,-1,-1,1,-1,-1],i)
	s=Solution().pathSum
	ans=s(T,22)
	print(ans)