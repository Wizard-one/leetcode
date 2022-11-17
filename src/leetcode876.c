#include <test.h>
#include <stdlib.h>
#include <stdio.h>
// #双指针 #链表 # 快慢指针
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