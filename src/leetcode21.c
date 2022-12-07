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
- list1.val>list2.val -> list2 
- list1.val<list2.val -> list1 
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
	struct ListNode *temp;
	struct ListNode *dum1,*dum2;
	dum1=malloc(sizeof(struct ListNode));
	dum1->next=list1;
	dum2=malloc(sizeof(struct ListNode));
	dum2->next=list2;
	list1=dum1;//被插入序列
	list2=dum2;//插入序列
	while (list1->next!=NULL || list2->next!=NULL)
	{

		if (list1->next==NULL)
		{
			list1->next=list2->next;
			break;
		}
		else if (list2->next==NULL)
		{
			break;
		}
		else if (list1->next->val>list2->next->val)
		{
			// 当l2中节点小于l1当前节点 将L2节点插入l1
			temp=list1->next;
			list1->next=list2->next;//插入元素
			list2->next=list2->next->next;//待插入序列删除已经插入的元素
			list1=list1->next;//l1 前移
			list1->next=temp;//重新link l1后继
		}
		else
		{
			// 当l2中节点大于l1当前节点 l1 直接前移
			list1=list1->next; 
		}
	}
	return dum1->next;
	
}


int main(){
	int l1[3]={1,2,4},l2[3]={1,3,4};
	struct ListNode *ll1,*ll2,*ans;
	ll1=ListInit(l1,1);
	ll2=ListInit(l2,0);
	ans=mergeTwoLists(ll1,NULL);
	ListPrint(ans);
}