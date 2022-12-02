#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <test.h>
// #链表 #递归
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
	struct ListNode *ans,*rans;
	if (list1==NULL)
	{
		ans=list2;
		return ans;
	}
	else if(list2==NULL)
	{
		ans=list1;
		return ans;
	}
	else if (list1->val>list2->val)
	{
		ans=list2;
		list2=list2->next; 
	}
	else
	{
		ans=list1;
		list1=list1->next; 
	}
	rans=ans;
	while (list1!=NULL || list2!=NULL)
	{
		if (list1==NULL)
		{
			ans->next=list2;
			return rans;
		}
		else if (list2==NULL)
		{
			ans->next=list1;
			return rans;
		}
		else if (list1->val>list2->val)
		{
			ans->next=list2;
			list2=list2->next;
		}
		else
		{
			ans->next=list1;
			list1=list1->next; 
		}
		ans=ans->next;
	}
	return rans;
	
}


int main(){
	int l1[3]={1,2,4},l2[3]={1,3};
	struct ListNode *ll1,*ll2,*ans;
	ll1=ListInit(l1,3);
	ll2=ListInit(l2,2);
	ans=mergeTwoLists(ll1,ll2);
	ListPrint(ans);
}