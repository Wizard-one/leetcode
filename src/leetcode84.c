#include <test.h>
#include <stdlib.h>
#include <stdio.h>

// #哑节点 #链表
/*
删除排序链表中的重复元素，包括重复元素本身例如
1-1-1-2-3 ->2-3

这是一个需要将头节点单独处理的链表问题，那么使用哑节点是必然。理清楚这一点之后，就可以较为方便的处理删除过程
*/
struct ListNode* deleteDuplicates(struct ListNode* head){

	struct ListNode *pa,*dummy;
	dummy=malloc(sizeof(struct ListNode));
	dummy->next=head;
	pa=dummy;
	while ((pa->next)&&(pa->next->next))
	{
		// 对比next 与 next->next 因为pa本身要用于移动
		if (pa->next->val==pa->next->next->val)
		{
			int temp=pa->next->val;
			while (pa->next&&pa->next->val==temp)
			{
				pa->next=pa->next->next;
			}
		}
		else
			pa=pa->next;
	}

	return dummy->next;
}

int main(){
	int l[]={1,2,3,3,4,4,5};
	struct ListNode *head;
	head=ListInit(l,7);
	head=deleteDuplicates(head);
	ListPrint(head);
}