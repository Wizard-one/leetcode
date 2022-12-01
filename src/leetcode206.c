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


// #链表
/* 链表翻转
实现过程如下:
head: 1->2->3->4->NULL

建立 anshead->NULL 
			   ^
			   |
			anstail
存储头的下一个节点 tmp=head->next: tmp=2

anshead指向head: anshead->head=1

切断当前head 与后序连接: anshead->head->anstail
								  ^
								  |
将tail前移: 					 anstail

head后移 head=tmp
 */
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

int main(){
	int a[]={1,2,3,4,5};
	struct ListNode *b,*ans;
	b=ListInit(a,5);
	ans=reverseList(b);
	ListPrint(ans);
}