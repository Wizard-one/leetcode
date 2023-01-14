#include <test.h>
#include <stdlib.h>
#include <stdio.h>
// #链表 [[82]] [[26]] #双指针

/* 83. 删除排序链表中的重复元素
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。 */

/* cur 不断前进比较head 直到有不同 head 前进 */
struct ListNode* deleteDuplicates(struct ListNode* head){
	struct ListNode *ans=head,*cur=head;
	if (head==NULL)
	{
		return ans;
	}
	
	head=head->next;
	while (head!=NULL)
	{
		if (head->val==cur->val)//遇到相同就删掉
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