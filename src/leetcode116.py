from typing import Optional
import collections
# Definition for a Node.
class Node:
	def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
		self.val = val
		self.left = left
		self.right = right
		self.next = next

# #二叉树 #层序遍历 [[leetcode102]] #广度优先搜索
class Solution:
	def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
		if root==None:
			return None
		que=collections.deque([root])#千万注意 deque初始化时接受是iterizable 对象
		while que:
			qlen=len(que)
			for i in range(qlen):
				nodel:Node=que.popleft()
				if i==qlen-1:
					nodel.next=None
				else:
					nodel.next=que[0]
				if nodel.left==None:
					continue
				que.append(nodel.left)
				que.append(nodel.right)
		return root

if __name__ == "__main__":
	s=Solution().connect
	n=Node(1)
	n.left=Node(2)
	n.right=Node(2)
	s(n)