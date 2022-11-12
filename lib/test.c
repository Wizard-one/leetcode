#include <test.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



struct ListNode* init(int* l,int ns)
{
	struct ListNode * r,*rh;
	r=malloc(sizeof(struct ListNode));
	rh=r;
	r->next=NULL;
	for (size_t i = 0; i < ns; i++)
	{
		
		r->val=l[i];
		if (i==ns-1)
		{
			r->next=NULL;
			break;
		}
		
		r->next=malloc(sizeof(struct ListNode));
		r=r->next;
		r->next=NULL;
	}
	return rh;
}

void listprint(struct ListNode * l)
{
	while (l!=NULL)
	{
		printf("%d,",l->val);
		l=l->next;
	}
}