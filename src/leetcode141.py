# hash 表，链表
from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
""" 环检测，直接hash表 """
class Solution:
	def hasCycle(self, head: Optional[ListNode]) -> bool:
		a=[]
		while(head!=None and head.next!=None ):
			if id(head) in a:
				return True
			else:
				a.append(id(head))
				head=head.next
		
		return False

if __name__ == "__main__":
	s=Solution()
	s.hasCycle(None)