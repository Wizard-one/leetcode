from lib.test import *

""" 具体解释看C 这边给出另一种实现方式 

原问题是求解一颗树的最大深度，根据问题的定义可以知道最大深度等于左右子树中最大深度+1

由此问题被拆分为一个子问题：求解左右子树的最大深度

那么子问题的结束就是节点为NULL

"""

class Solution:
	def maxDepth(self, root: Optional[TreeNode]) -> int:
		if not root:
			return 0

		leftdepth=self.maxDepth(root.left)
		rightdepth=self.maxDepth(root.right)
		# 在后序位置进行最大深度的维护
		maxdepth=max(leftdepth,rightdepth)+1
		return maxdepth