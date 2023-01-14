#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <test.h>
// #链表 #哑节点
/* 21. 合并两个有序链表

将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 */
/* 
虽然可以用递归来解决,但毕竟递归需要O(n) 的空间复杂度,所以还是使用迭代

使用哑节点规避了处理头节点的问题,将list1 作为被插入序列,将List2作为插入序列
使用额外的一个指针cur 方便插入操作


- list1.val>list2.val -> list2 
- list1.val<list2.val -> list1 
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
	struct ListNode *dum;
	struct ListNode *cur;
	dum=malloc(sizeof(struct ListNode));
	dum->next=list1;
	cur=dum;//维护返回的指针,有了这个指针可以将问题简化为l1 l2 不断向前移动即可
	while (list1!=NULL && list2!=NULL)
	{

		if (list1->val>list2->val)
		{
			// 当l2中节点小于l1当前节点 将L2节点插入cur
			cur->next=list2;
			list2=list2->next;
		}
		else
		{
			// 当l2中节点大于l1当前节点 将L1节点插入cur
			cur->next=list1;
			list1=list1->next; 
		}
		cur=cur->next;//cur 不断前移
	}
	if (list1)
	{
		cur->next=list1;
	}
	if (list2)
	{
		cur->next=list2;
	}
	return dum->next;
}


int main(){
	int l1[3]={1,2,4},l2[3]={1,3,4};
	struct ListNode *ll1,*ll2,*ans;
	ll1=ListInit(l1,1);
	ll2=ListInit(l2,0);
	ans=mergeTwoLists(ll1,NULL);
	ListPrint(ans);
}