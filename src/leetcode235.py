import collections
# Definition for a binary tree node.
class TreeNode:
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

# #BST [[653]] [[700]] [[701]] #队列

class Solution:
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

