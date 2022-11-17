#include <test.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



struct ListNode* ListInit(int* l,int ns)
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

void ListPrint(struct ListNode * l)
{
	while (l!=NULL)
	{
		printf("%d,",l->val);
		l=l->next;
	}
	printf("\n");
}

/**
 * @brief Create a Bi Tree object
 * 
 * @param T Tree address
 * @param nums list use -1 mark NULL
 * @param idx list index
 */
void CreateBiTree(struct TreeNode **T,int *nums,int *idx)
{
	(*idx)++;
	if(nums[*idx]==-1)
		*T=NULL;
	else
	{
		*T=(struct TreeNode*)malloc(sizeof(struct TreeNode));
		if(! *T)
			exit(-1);
		(*T)->val=nums[(*idx)];
		CreateBiTree(&(*T)->left,nums,idx);
		CreateBiTree(&(*T)->right,nums,idx);
	}
}