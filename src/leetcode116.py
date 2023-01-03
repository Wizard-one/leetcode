from typing import Optional
import collections
# Definition for a Node.
""" 116. 填充每个节点的下一个右侧节点指针

给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。
 """



class Node:
	def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
		self.val = val
		self.left = left
		self.right = right
		self.next = next

# #二叉树 #层序遍历 [[114]] [[102]] #广度优先搜索 [[117]]
class Solution:
	""" 层序遍历,到了结尾直接连通None """
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
					# 由于是完美二叉树,某一个分支无了那就是结束添加,但是还是要记录链接next
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