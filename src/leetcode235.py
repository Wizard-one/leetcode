import collections
# Definition for a binary tree node.
class TreeNode:
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

# #BST [[653]] [[700]] [[701]] #栈 [[236 ]]

class Solution:
	""" 
	二叉搜索树的最近公共祖先

	给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

	百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
	"""
	def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
		""" 
		先搜索p 使用栈维护走过的路径，当搜到之后从栈顶开始回退，重新搜索q, 直到回到根节点

		问题的核心是对于返回的子树cur要经历2次遍历，因为p，q必然一个在cur.left 一个在cur.right

		如果都在 cur.left or cur.right 那么cur必然不是最深先祖。
		"""
		cur=root
		pque=collections.deque()#记录搜索p时走过的路径的栈
		
		while True:
			# 简单的BST搜索
			pque.append(cur)
			if cur.val==p.val:
				break
			elif cur.val>p.val:
				cur=cur.left
			else:
				cur=cur.right
		while pque:
			cur:TreeNode=pque.pop()#弹栈，回到上一个结点
			ccur=cur
			while ccur!=None:
				# 二次搜索q，因为q, p 之间深度可能相差较多
				if ccur.val==q.val:
					return cur
				elif ccur.val>q.val:
					ccur=ccur.left
				else:
					ccur=ccur.right
		

						

if __name__ == "__main__":
	s=Solution().lowestCommonAncestor
	T=TreeNode(2)
	T.left=TreeNode(1)
	# T.right=TreeNode(8)
	ans=s(T,TreeNode(2),TreeNode(1))
	print(ans.val)

