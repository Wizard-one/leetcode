#include <test.h>
/* 92. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 */

// #递归 #链表 


/* 先做一个简单的问题，如何翻转整个链表，然后考虑如何翻转前N个节点
翻转前N个节点就是通过后序遍历到了尾巴链接上不需要翻转的节点，

最后就是，如果left=1 那么等价于翻转前right 个节点 否则向下递归同时在后序过程中回收节点
 */
struct ListNode* last=NULL;
struct ListNode* reverseN(struct ListNode* head,int N)
{
	if (N==1)
	{
		last=head->next;
		return head;
	}
	
	struct ListNode *node=reverseN(head->next,N-1);
	head->next->next=head;
	head->next=last;
	return node;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
	if (left==1)
	{
		return reverseN(head,right);
	}
	// 通过后序回收节点，即 head之后的都实现了翻转，head 直接链接翻转之后的结果即可
	head->next=reverseBetween(head->next,left-1,right-1);
	return head;
}

int main(int argc, char const *argv[])
{
	int l[]={1,2,3,4,5};
	struct ListNode* head=ListInit(l,5);
	struct ListNode* node;
	node=reverseBetween(head,2,4);
	ListPrint(node);
	return 0;
}
