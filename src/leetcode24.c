#include <stdio.h>
#include <test.h>
#include <stdlib.h>

// #链表 #哑节点 
/* 24. 两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

实现方式就是交换两个节点的值。用哑节点来处理头节点
需要注意要在交换前先记录交换终点的下一个值例如cur->next->next->next; 不然会产生环
 */

struct ListNode* swapPairs(struct ListNode* head){
	struct ListNode *dummy=malloc(sizeof(struct ListNode)),*cur,*t,*aft;
	dummy->next=head;
	cur=dummy;
	// 因为要获取cur.next 与cur.next.next 的数据 所以结束条件必然是这个
	while (cur->next&&cur->next->next)
	{
		// 交换 1->2->4
		t=cur->next;
		aft=cur->next->next->next;//临时存储交换终点的值 如4
		cur->next=cur->next->next;//实际交换必然是当前指针的下一个节点与下下个节点
		cur->next->next=t;
		cur->next->next->next=aft;//重新link 之后的节点
		cur=cur->next->next;//一次性跳到之后节点
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