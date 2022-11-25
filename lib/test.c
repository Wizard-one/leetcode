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
void TreeInit(struct TreeNode **T,int *nums,int *idx)
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
		TreeInit(&(*T)->left,nums,idx);
		TreeInit(&(*T)->right,nums,idx);
	}
}
/**
 * @brief 层序打印树
 * 
 * @param root 树根节点 
 */
void TreePrint(struct TreeNode* root)
{
	if (root==NULL)
	{
		printf("[]");
	}
	struct TreeNode **queue;
	queue=malloc(sizeof(struct TreeNode *)*2000);
	int front=0,rear=0;
	queue[front++]=root;
	while ((front)!=(rear))
	{
		int last=(front);//标记当前层位置
		int col=0;
		while ((rear)<last)	
		{
			root=queue[(rear)++];
			printf("%d,",root->val);
			if (root->left!=NULL)
				queue[(front)++]=root->left;
			if (root->right!=NULL)		
				queue[(front)++]=root->right;
		}
		printf("\n");
	}
}

/**
 * @brief 打印矩阵
 * 
 * @param mat 矩阵指针
 * @param matrixSize 矩阵row num
 * @param matrixColSize 矩阵col num
 */
void printmat(int **mat, int matrixSize, int* matrixColSize)
{
	for (size_t i = 0; i < matrixSize; i++)
	{
		for (size_t j = 0; j < matrixColSize[i]; j++)
		{
			printf("%d,",mat[i][j]);
		}
		printf("\n");
	}
}