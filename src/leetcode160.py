from typing import Optional
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None
# #hash #链表 [[142]]
""" 
求链表相交位置
直接使用hash表暴力求解, 用hash表记录链表a的所有内存地址，然后遍历b，当内存地址发生重复则返回
"""
class Solution:
	def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
		a=set()
		cur=headB
		while(cur!=None):
			a.add(id(cur))
			cur=cur.next
		cur=headA
		while(cur!=None):
			if(id(cur) in a):
				return cur
			cur=cur.next
		return None

if __name__ == "__main__":
	headA=ListNode(4)
	headA.next=ListNode(1)
	headA.next.next=ListNode(8)
	headB=ListNode(5)
	headB.next=ListNode(6)
	headB.next.next=headA.next
	headB.next.next.next=headA.next.next
	s=Solution().getIntersectionNode
	ans=s(headA,headB)
	print(ans)