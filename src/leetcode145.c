#include <test.h>

// #二叉树 #递归 #后序遍历
int GetVal(struct TreeNode* root,int *result,int* n)
{
	if (root==NULL)
	{
		return 0;
	}
	GetVal(root->left,result,n);
	GetVal(root->right,result,n);
	result[(*n)++]=root->val;
    return 1;
}

/* 标准后序遍历 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
	int *ans;
	*returnSize=0;
	ans=malloc(100*sizeof(int));
    if(root!=NULL)
        GetVal(root,ans,returnSize);
    return ans;
}