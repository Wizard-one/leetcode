#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/* 
给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。
 */


//#双指针，#快慢指针 #链表 [[142]]

/* 检查有环只需要用快慢指针检测指针是否相遇即可，或者使用hash表 */
bool hasCycle(struct ListNode *head) {
	if (head==NULL || head->next==NULL)
	{
		return false;
	}
	
    struct ListNode *fast=head->next,*slow=head;
	while (fast!=slow)
	{
		if (fast==NULL||slow==NULL)
		{
			return false;
		}
		
		fast=fast->next->next;
		slow=slow->next;

	}
	return true;
}