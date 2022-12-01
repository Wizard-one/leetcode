#include <test.h>
#include <stdio.h>
#include <stdlib.h>

//#链表

/* 返回链表中点 [[876]]
快慢指针实现 */
struct ListNode* middleNode(struct ListNode* head){
	int len;
	struct ListNode* fcur=head,*scur=head;
	while (fcur!=NULL && fcur->next!=NULL)
	{
		fcur=fcur->next->next;
		scur=scur->next;
	}
	return scur;
}

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

/* 数组的重新排序
核心是将任务拆分，然后重组过去已经实现过的功能
 */
void reorderList(struct ListNode* head){
	struct ListNode *mid;
	mid=middleNode(head);//找到链表中点
	// 前半用l1 维护 后半用l2 维护 tmp 作为临时变量
	struct ListNode *l1=head,*l2,*tmp;
	l2=reverseList(mid->next);//翻转后半链表
	mid->next=NULL;//将链表分为两段
	int i=0;//标记重新排序变量
	while (l1&&l2)
	{
		//放后半段节点
		if (i==0)
		{
			tmp=l1->next;//临时保存next节点
			l1->next=l2;//存放后半段节点
			l2=l2->next;//移动后半段节点指针向后
			l1=l1->next;//前半段指针向后
			l1->next=tmp;//重新link 前半段指针
			i=1;
		}
		else//前半段节点直接前进
		{
			l1=l1->next;
			i=0;
		}
	}
}


int main(){
	int l[]={1,2,3,4,5};
	struct ListNode *head;
	head=ListInit(l,5);
	reorderList(head);
	ListPrint(head);
}
