#include <test.h>
#include <stdio.h>
#include <stdlib.h>

// #BST #二叉树 #中序遍历 #递归 #二分法 time: O(n) space: O(logn)

struct TreeNode* CreateBSTNode(int* nums, int left,int right)
{
	if (left>right)
	{
		return NULL;
	}
	int mid=(left+right)/2;
	struct TreeNode *new;
	new=malloc(sizeof(struct TreeNode));
	new->val=nums[mid];
	new->left=CreateBSTNode(nums,left,mid-1);
	new->right=CreateBSTNode(nums,mid+1,right);
	return new;
}

//中序遍历
void GetBST(struct TreeNode *root,int** nums,int* idx)
{
	if (!root)
	{
		return;
	}
	GetBST(root->left,nums,idx);
	(*nums)[(*idx)++]=root->val;//记录前一个val
	GetBST(root->right,nums,idx);
}


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
	struct TreeNode *root;
	root=CreateBSTNode(nums,0,numsSize-1);
	return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key){

	int *nums,idx=0;
	nums=malloc(sizeof(int)*10001);
	GetBST(root,&nums,&idx);
	int i;
	for (i = 0; i < idx; i++)
	{
		if (nums[i]==key)
		{
			break;
		}
	}
	if (i==idx)
	{
		return root;
	}

	

	for ( i; i < idx; i++)
	{
		nums[i]=nums[i+1];
	}
	idx--;
	for (size_t j = 0; j < idx; j++)
	{
		printf("%d,",nums[j]);
	}
	if (idx==0)
	{
		return NULL;
	}
	
	root=CreateBSTNode(nums,0,idx-1);
	return root;
}


int main(){
	int in[]={2,3,4,5,6,7},pre[]={5,3,2,4,6,7};
	struct TreeNode *root=TreeInit_prein(pre,in,6);
	root=deleteNode(root,3);
	TreePrint(root);
}