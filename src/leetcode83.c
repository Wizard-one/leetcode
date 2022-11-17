#include <test.h>
#include <stdlib.h>
#include <stdio.h>
// #链表
struct ListNode* deleteDuplicates(struct ListNode* head){
	struct ListNode *ans=head,*cur=head;
	if (head==NULL)
	{
		return ans;
	}
	
	head=head->next;
	while (head!=NULL)
	{
		if (head->val==cur->val)
		{
			cur->next=head->next;
		}
		else
		{
			cur=head;
		}
		head=head->next;
	}
	return ans;
}


int main(){
	int a[]={1,1,2,2};
	int b[]={1,1,2,3,3,4};
	int c[]={1,2,2,3};
	struct ListNode *ans;
	ans=ListInit(a,4);
	ans=deleteDuplicates(ans);
	ListPrint(ans);
	ans=ListInit(b,6);
	ans=deleteDuplicates(ans);
	ListPrint(ans);
	ans=ListInit(c,4);
	ans=deleteDuplicates(ans);
	ListPrint(ans);
	
}