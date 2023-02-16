#include <test.h>
#include <stdio.h>
#include <stdlib.h>

/* 翻转链表[[206]] #哑节点 #链表 #hard*/
struct ListNode* reverseList(struct ListNode* head){
	struct ListNode *anshead,*anstail,*tmp;
	anshead=malloc(sizeof(struct ListNode));//结果链表的哑节点
	anshead->next=NULL;
	anstail=anshead->next;
	while (head!=NULL)
	{
		tmp=head->next;
		anshead->next=head;//节点倒退，将头存在结尾
		anshead->next->next=anstail;//link 此时的头与尾巴
		anstail=anshead->next;//尾巴前移
		head=tmp;//原来的头后移
	}
	return anshead->next;
}
/* 
翻转长度为k的链表

给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。


分成几个子问题
- 长度为k的子链表翻转
- 子链表链接
- 判断长度不足
 */
struct ListNode* reverseKGroup1(struct ListNode* head, int k){
	struct ListNode *prev,*cur=head,*rear,*dummy;
	dummy=malloc(sizeof(struct ListNode));
	dummy->next=head;//构建dummy node 方便处理头节点
	prev=dummy;
	while (cur)
	{
		for (size_t i = 0; i < k-1; i++)//移动到末尾节点而非NULL节点
		{	
			cur=cur->next;
			if (!cur)//链表余下的节点不足以翻转,直接返回
			{
				return dummy->next;
			}
		}
		rear=cur->next;//记录后继节点地址
		cur->next=NULL;//中断后继用于翻转
		head=reverseList(head);//翻转
		prev->next=head;//翻转后链表与前面完成处理的link
		for (size_t i = 0; i < k-1; i++)
		{
			head=head->next;
		}
		prev=head;//更新前置节点位置
		head->next=rear;//重新link 后继节点
		cur=head->next;//移动指针到后继节点
	}
	return dummy->next;
}

/* 递归方法求解
	先做 a-b 之间的链表翻转
 */
struct ListNode* reverse(struct ListNode * head,struct ListNode *end)
{
	if (!head||(head==end))
	{
		return head;
	}
	struct ListNode *node=reverse(head->next,end);
	head->next->next=head;
	head->next=NULL;
	return node;
}

/* 再递归的翻转链表
	
	每次给定k个节点的头尾，随后递归翻转后续链表last，随后将翻转之后的last链表与当前段链接
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k){
	// base case 如果head==NULL 返回NULL
	if (!head)
	{
		return NULL;
	}
	struct ListNode *cur=head;
	for (size_t i = 0; i < k-1; i++)
	{
		cur=cur->next;
		// base case 如果链表长度不足，返回head
		if (!cur)
		{
			return head;
		}
	}
	struct ListNode *last=cur->next,*group;
	// printf("%d,%d\n",head->val,cur->val);
	// 翻转head-cur 段的链表，返回的是反转后链表的头
	group=reverse(head,cur);
	// 此时head 为反转后链表的尾部，直接链接后续链表
	head->next=reverseKGroup(last,k);
	return group;
}

int main(){
	int l[]={1,2,3,4,5};
	struct ListNode* head;
	head=ListInit(l,5);
	head=reverseKGroup(head,2);
	ListPrint(head);
}