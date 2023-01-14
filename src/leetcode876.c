#include <test.h>
#include <stdlib.h>
#include <stdio.h>
// #双指针 #链表 #快慢指针
/* 876. 链表的中间结点

给定一个头结点为 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。 */

// 一个指针速度=1 一个速度=2就解决问题
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

int main()
{
	int a[]={1,2,3,4,5};
	struct ListNode* h;
	h=ListInit(a,5);
	h=middleNode(h);
	ListPrint(h);
}