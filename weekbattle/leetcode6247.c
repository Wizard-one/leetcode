#include <test.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// #链表 #mid  超时，
struct ListNode* removeNodes(struct ListNode* head){
	struct ListNode* cur=head;
	if (head==NULL|| head->next==NULL)
	{
		return head;
	}
	int max=head->val;
	int lastmax=max;
	
	while (cur!=NULL)
	{
		if (max<cur->val)
		{
			max=cur->val;
			head=cur;
			break;
		}
		cur=cur->next;
	}
	if (lastmax==max)
	{
		cur=removeNodes(head->next);
	}
	else
		cur=removeNodes(head);
	head->next=cur;
	return head;
}

int main(){
	int l[]={5,2,13,3,8};
	struct ListNode *head;
	head=ListInit(l,5);
	head=removeNodes(head);
	ListPrint(head);
}