#include <test.h>
#include <stdio.h>
#include <stdlib.h>

// #BST #二叉树 #中序遍历 #递归
/* 将排序好的数组转化为一颗二叉搜索树

确定好可以选择中间节点作为root 之后 就可以通过拆分区间来实现递归

 */

struct TreeNode* CreateBSTNode(int* nums, int numsSize)
{
	if (numsSize==0)
	{
		return NULL;
	}
	struct TreeNode *new;
	new=malloc(sizeof(struct TreeNode));
	new->val=nums[numsSize/2];
	new->left=NULL;
	new->right=NULL;
	int *lnums,*rnums;
	lnums=malloc(sizeof(int)*numsSize/2);//拆分左右区间
	rnums=malloc(sizeof(int)*numsSize-numsSize/2-1);
	//左右区间赋值
	for (size_t i = 0; i < numsSize/2; i++)
	{
		lnums[i]=nums[i];
	}
	for (size_t i = numsSize/2+1; i < numsSize; i++)
	{
		rnums[i-(numsSize/2+1)]=nums[i];
	}
	new->left=CreateBSTNode(lnums,numsSize/2);
	new->right=CreateBSTNode(rnums,numsSize-numsSize/2-1);
	return new;
}



struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
	struct TreeNode *root;
	root=CreateBSTNode(nums,numsSize);
	return root;
}


int main(){
	int l[]={-10,-3,0,4,5,9};
	struct TreeNode *root=sortedArrayToBST(l,6);
	TreePrint(root);
}