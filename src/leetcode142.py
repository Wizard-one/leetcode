from typing import Optional
import collections

"""142. 环形链表 II

 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表
 """

# #链表 #hash #快慢指针 [[141]]
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

""" 
使用hash表实现,遇到已经添加到表中的元素就直接结束，那就是环的起始点。

也可以用快慢指针实现，只不过需要计算两个指针分别走过的路径并设计终止条件
"""
class Solution:
	def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
		d=collections.defaultdict(int)
		cur=head
		while(d[id(cur)]==0):
			if cur==None:
				return None
			d[id(cur)]=1
			cur=cur.next
		return cur