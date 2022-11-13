/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <test.h>
#include <stdlib.h>
#include <stdio.h>

struct ListNode* reverseList(struct ListNode* head){
	struct ListNode *anshead,*anstail,*tmp;
	anshead=malloc(sizeof(struct ListNode));
	anshead->next=NULL;
	anstail=anshead->next;
	while (head!=NULL)
	{
		tmp=head->next;
		anshead->next=head;
		anshead->next->next=anstail;
		anstail=anshead->next;
		head=tmp;
	}
	return anshead->next;
}

int main(){
	int a[]={1,2,3,4,5};
	struct ListNode *b,*ans;
	b=init(a,5);
	ans=reverseList(b);
	listprint(ans);
}