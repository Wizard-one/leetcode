#include <test.h>
#include <stdlib.h>
#include <stdio.h>

//#哑节点 #双指针 #快慢指针
/* 删除链表的倒数第 N 个结点 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	struct ListNode* fcur=head,*scur,*dummy;
	dummy=malloc(sizeof(struct ListNode));//哑节点维护头节点删除的情况
	dummy->next=head;
	scur=dummy;
	for (size_t i = 0; i < n; i++)
	{
		fcur=fcur->next;//快指针先移动n次
	}
	// 然后指针同时移动,快指针到头就启动删除
	while (fcur!=NULL)
	{
		fcur=fcur->next;
		scur=scur->next;
	}
	scur->next=scur->next->next;
	return dummy->next;
}

int main()
{
	int a[]={1,2,3,4,5};
	int b[]={1,2};
	struct ListNode* h;
	h=ListInit(a,5);
	h=removeNthFromEnd(h,2);
	ListPrint(h);
	h=ListInit(b,2);
	h=removeNthFromEnd(h,2);
	ListPrint(h);
	h=ListInit(b,2);
	h=removeNthFromEnd(h,1);
	ListPrint(h);
	int c[]={1,2,3};
	h=ListInit(c,3);
	h=removeNthFromEnd(h,2);
	ListPrint(h);
	int d[]={1};
	h=ListInit(c,1);
	h=removeNthFromEnd(h,1);
	ListPrint(h);

}