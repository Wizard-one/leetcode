#include <test.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/**
 * @brief init list from int array
 * 
 * @param l int array
 * @param ns array length
 * @return struct ListNode* list head 
 */
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
/**
 * @brief print List
 * 
 * @param l input list
 */
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
 * @brief 构建子树
 * 
 * @param hash 中序遍历的hash 表 key=tree node value; value=该value 对应的中序遍历idx 
 * @param preorder 先序遍历数组
 * @param preleft 先序遍历中左子树开始的位置
 * @param preright 先序遍历中右子树开始的位置
 * @param instart 中序遍历序列中一颗子树开始位置
 * @param inend 中序遍历序列中一颗子树结束位置
 * @return struct TreeNode* 
 */
struct TreeNode* subTree(int *hash,int* preorder,int preleft,int preright,int instart,int inend)
{
	if (preleft>preright)
	{
		return NULL;
	}
	struct TreeNode *root=malloc(sizeof(struct TreeNode));
	root->val=preorder[preleft];//先序遍历区间第一个节点为根节点
	int inroot=hash[root->val+3000];//中序遍历中定位到根节点idx
	int lnum=inroot-instart;//left subtree num
 	// 左子树创建:
	// 先序列表左子树开始位置显然就是当前根节点+1, 右子树开始位置就是左子树的数目+当前根节点位置
	// 中序列表开始位置不变，结束位置是当前根节点位置-1
	root->left=subTree(hash,preorder,preleft+1,preleft+lnum,instart,inroot-1);
	// 右子树创建:
	// 先序列表左子树开始位置是当前根节点+1+左子树长度, 右子树开始位置不变
	// 中序列表开始位置是当前根节点位置+1，结束位置不变
	root->right=subTree(hash,preorder,lnum+preleft+1,preright,inroot+1,inend);
	return root;
}

/**
 * @brief 使用先序遍历与中序遍历构造二叉树
 * 
 * @param preorder 先序遍历表
 * @param inorder 先序遍历表
 * @param Size 二叉树总节点数
 * @return struct TreeNode* 
 */
struct TreeNode* TreeInit_prein(int* preorder,int* inorder, int Size){
	int hash[6000]={0};
	struct TreeNode*root;
	// 构建hash表降低搜索复杂度
	for (size_t i = 0; i < Size; i++)
	{
		hash[inorder[i]+3000]=i;
	}
	root=subTree(hash,preorder,0,Size-1,0,Size-1);
	return root;
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