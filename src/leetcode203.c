#include <test.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// #链表 #递归
struct ListNode* removeElements(struct ListNode* head, int val){
	if (head==NULL)
	{
		return NULL;
	}
	head->next=removeElements(head->next,val);
	if (head->val==val)
	{
		return head->next;
	}
	else
	{
		return head;
	}
}

int main(){
	int a[]={1,2,6,3,4,5,6};
	struct ListNode *l,*ans;
	l=init(a,7);
	ans=removeElements(l,6);
	listprint(ans);
}