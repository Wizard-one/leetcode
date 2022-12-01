#include <stdio.h>
#include <test.h>
#include <stdlib.h>

// #链表 #哑节点
/* 
交换两个节点的值。需要注意要在交换前先记录交换终点的下一个值例如cur->next->next->next; 不然会产生环
 */

struct ListNode* swapPairs(struct ListNode* head){
	struct ListNode *dummy=malloc(sizeof(struct ListNode)),*cur,*t,*aft;
	dummy->next=head;
	cur=dummy;
	while (cur->next&&cur->next->next)
	{
		t=cur->next;
		aft=cur->next->next->next;
		cur->next=cur->next->next;
		cur->next->next=t;
		cur->next->next->next=aft;
		cur=cur->next->next;
	}
	return dummy->next;
}

int main(){
	int l[]={1,2,3,4};
	struct ListNode *head;
	head=ListInit(l,4);
	head=swapPairs(head);
	ListPrint(head);
}