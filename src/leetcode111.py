from lib.test import *

""" 111. 二叉树的最小深度

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。
 """

# #广度优先搜索 #二叉树 [[1091]]
"""  
因为要求最短路,所以使用标准的广度优先搜索,可以剪去多余的深度遍历
""" 
class Solution:
	def minDepth(self, root: Optional[TreeNode]) -> int:
		if root==None:
			return 0
		q=collections.deque([root])
		depth=0
		while(q):
			depth+=1
			sz=len(q)
			for i in range(sz):
				cur=q.popleft()
				if cur.left==None and cur.right==None:
					return depth
				if cur.right!=None:
					q.append(cur.right)
				if cur.left!=None:
					q.append(cur.left)
		

