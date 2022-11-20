from typing import Optional
# #BST [[leetcode701]] [[leetcode700]] #hash #DFS #深度优先搜索

class TreeNode:
	def __init__(self, val=0, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right

class Solution:
	def __init__(self):
		"""
		docstring
		"""
		self.s=set()

	""" 
	对BST使用DFS 走过的加入hash表,如果k-root.val in hash tabel 则 True
	"""
	def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
		if root==None:
			return False
		if (k-root.val) in self.s:
			return True
		else:
			self.s.add(root.val)
		return self.findTarget(root.left,k) or self.findTarget(root.right,k)
