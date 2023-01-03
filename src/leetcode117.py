from lib.test import *
class Node:
	def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
		self.val = val
		self.left = left
		self.right = right
		self.next = next

# #二叉树 #层序遍历 [[114]] [[102]] #广度优先搜索 [[116]]

class Solution:
	""" 层序遍历,节点多了next就可以将每一层看成链表。
	使用一个指针维护本层，一个指针维护下一层的链接关系，当本层结束进入下一层即可
	 """
	def connect(self, root: 'Node') -> 'Node':
		if root==None:
			return None
		cur=root#当前层指针
		while cur!=None:
			dummy=Node()#下一层的链表
			pre=dummy#记录下一层上一个节点的指针
			while(cur!=None):
				if cur.left!=None:
					# 当前指针左不为空，则将上一个节点链接到左节点
					pre.next=cur.left
					# 然后pre指针前进
					pre=pre.next
				if cur.right!=None:
					# 同理
					pre.next=cur.right
					pre=pre.next
				cur=cur.next#移动指针
			#当前层遍历完，进入下一层		
			cur=dummy.next

		return root

if __name__ == "__main__":
	T=Node(1)
	T.left=Node(2)
	T.right=Node(3)
	T.left.left=Node(4)
	T.left.right=Node(5)
	T.right.right=Node(7)
	s=Solution().connect
	s(T)