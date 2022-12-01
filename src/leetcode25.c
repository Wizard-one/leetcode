#include <test.h>
#include <stdio.h>
#include <stdlib.h>

/* 翻转链表[[206]] */
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

分成几个子问题
- 长度为k的子链表翻转
- 子链表链接
- 判断长度不足
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k){
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

int main(){
	int l[]={1,2,3,4,5};
	struct ListNode* head;
	head=ListInit(l,5);
	head=reverseKGroup(head,5);
	ListPrint(head);
}