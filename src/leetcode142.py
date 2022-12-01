from typing import Optional
import collections
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

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