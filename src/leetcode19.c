#include <test.h>
#include <stdlib.h>
#include <stdio.h>

//#哑节点 #双指针 #快慢指针
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	struct ListNode* fcur=head,*scur,*dummy;
	dummy=malloc(sizeof(struct ListNode));
	dummy->next=head;
	scur=dummy;
	for (size_t i = 0; i < n; i++)
	{
		fcur=fcur->next;
	}
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
	h=init(a,5);
	h=removeNthFromEnd(h,2);
	listprint(h);
	h=init(b,2);
	h=removeNthFromEnd(h,2);
	listprint(h);
	h=init(b,2);
	h=removeNthFromEnd(h,1);
	listprint(h);
	int c[]={1,2,3};
	h=init(c,3);
	h=removeNthFromEnd(h,2);
	listprint(h);
	int d[]={1};
	h=init(c,1);
	h=removeNthFromEnd(h,1);
	listprint(h);

}