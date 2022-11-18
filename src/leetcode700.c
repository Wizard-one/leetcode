#include <stdlib.h>
#include <stdio.h>
#include <test.h>

// #二叉树 #递归 [[leetcode112]] #BST
int GetVal(struct TreeNode* root,int *result,int* n)
{
	if (root==NULL)
	{
		return 0;
	}
	result[(*n)++]=root->val;
	GetVal(root->left,result,n);
	GetVal(root->right,result,n);
    return 1;
}

struct TreeNode* searchBST(struct TreeNode* root, int val){
	struct TreeNode* ans;
	if (root==NULL)
	{
		return NULL;
	}
	else if (root->val==val)
		return root;
	ans=searchBST(root->left,val);
	if (ans)
		return ans;
	ans=searchBST(root->right,val);
	if (ans)
		return ans;
	else
		return NULL;
}

int main(){
	int l[]={0,4,2,1,-1,-1,3,-1,-1,7,-1,-1},i=0;
	struct TreeNode *T,*ans;
	TreeInit(&T,l,&i);
	ans=searchBST(T,2);
	TreePrint(ans);
}