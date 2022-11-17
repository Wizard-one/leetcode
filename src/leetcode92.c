#include <test.h>
#include <stdlib.h>

// #树 #递归 #中序搜索
int GetVal(struct TreeNode* root,int *result,int* n)
{
	if (root==NULL)
	{
		return 0;
	}
	GetVal(root->left,result,n);
	result[(*n)++]=root->val;
	GetVal(root->right,result,n);
    return 1;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int *ans;
	*returnSize=0;
	ans=malloc(100*sizeof(int));
	struct TreeNode *firstleft;
    if(root!=NULL)
        GetVal(root,ans,returnSize);
    return ans;
}