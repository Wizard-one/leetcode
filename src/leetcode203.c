#include <test.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/* 203. 移除链表元素

给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。  */


// #链表 #递归
struct ListNode* removeElements(struct ListNode* head, int val){
	if (head==NULL)
	{
		return NULL;
	}
	// 先递归到链表最后一个节点，从后向前删除，递归使用的栈就记录了整个链表所有信息
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
	l=ListInit(a,7);
	ans=removeElements(l,6);
	ListPrint(ans);
}