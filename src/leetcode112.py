import collections
from typing import Optional

# #广度优先搜索 #二叉树
class TreeNode:
	def __init__(self, val=0, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right
class Solution:
	def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
		if root==None:
			return False
		q_node=collections.deque([root])
		q_val=collections.deque([root.val])
		while (q_node):
			node=q_node.popleft()
			sum=q_val.popleft()
			if node.left==None and node.right==None:
				if sum==targetSum:
					return True
				else:
					continue
			if node.left:
				q_node.append(node.left)
				q_val.append(sum+node.left.val)
			if node.right:
				q_node.append(node.right)
				q_val.append(sum+node.right.val)
		return False


if __name__ == "__main__":
	s=Solution().hasPathSum
	t=TreeNode(-2)
	t.right=TreeNode(-3)
	s(t,-2)