#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *
addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *re, *hre;
	int up=0;
	re = malloc(sizeof(struct ListNode));
	re->val = 0;
	re->next = NULL;
	hre = re;
	while ((l1 != NULL) || (l2 != NULL))
	{
		re->val =l1->val + l2->val+up;
		if (re->val > 9)
		{
			up= 1;
			re->val -= 10;
		}
		else
		{
			up= 0;
		}
		l1 = l1->next;
		l2 = l2->next;
		if (l1 == NULL && l2!=NULL)
		{
			l1 = malloc(sizeof(struct ListNode));
			l1->val = 0;
			l1->next = NULL;
		}else if (l2 == NULL && l1!=NULL)
		{
			l2 = malloc(sizeof(struct ListNode));
			l2->val = 0;
			l2->next = NULL;
		}
		if ((l1 != NULL) || (l2 != NULL))
		{
			re->next = malloc(sizeof(struct ListNode));
			re = re->next;
		}
	}
	if (up==1)
	{
		re->next = malloc(sizeof(struct ListNode));
		re->next->val=up;
		re->next->next=NULL;
	}
	else
	{
		re->next = NULL;
	}
	return hre;
}

struct ListNode *
setvalue(struct ListNode *l, int *n, int len)
{
	struct ListNode *h;
	h = l;
	for (size_t i = 0; i < len-1; i++)
	{

		l->val = n[i];
		l->next = malloc(sizeof(struct ListNode));
		l = l->next;
	}
	l->val=n[len-1];
	l->next = NULL;
	return h;
}

void show(struct ListNode *l)
{
	printf("%d", l->val);
	l = l->next;
	while (l!=NULL)
	{
		printf("%d", l->val);
		l = l->next;
	}
}
#define NUM 3
int main()
{
	int a[NUM] = {2,4,3}, b[NUM] = {5,6,4};
	struct ListNode *l1, *l2, *result;
	l1 = malloc(sizeof(struct ListNode));
	l2 = malloc(sizeof(struct ListNode));
	l1 = setvalue(l1, a, NUM);
	l2 = setvalue(l2, b, NUM);
	result = addTwoNumbers(l1, l2);
	show(result);
	return 0;
}