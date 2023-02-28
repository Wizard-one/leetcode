#include <test.h>
/* 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 */

// #快慢指针 #回文串 #链表

/* 快慢指针+翻转链表
回文串问题就是找出回文中心然后向左右扩散对比

首先利用快慢指针找到回文中心，然后将后半部分翻转与前半进行对比即可

 */
/* 翻转 */
struct ListNode* reverse(struct ListNode* head)
{
	if (!head|| !(head->next))
	{
		return head;
	}
	
	struct ListNode *node=reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return node;
}


bool isPalindrome(struct ListNode* head){
	struct ListNode *fast=head,*slow=head,*cur=head;
	// 快慢指针找中心
	while (fast && fast->next)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	if (fast)
	{
		slow=slow->next;
	}
	slow=reverse(slow);
	while (slow)
	{
		if (slow->val!=cur->val)
		{
			return false;
		}
		slow=slow->next;
		cur=cur->next;
	}
	return true;
}