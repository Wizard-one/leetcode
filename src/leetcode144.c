#include <stdlib.h>
#include <stdio.h>
#include <test.h>

// #树 #递归 #前序搜索
int GetVal(struct TreeNode* root,int *result,int* n)
{
	result[(*n)++]=root->val;
	if (root->left!=NULL)
	{
		GetVal(root->left,result,n);
	}
	if(root->right!=NULL)
	{
		GetVal(root->right,result,n);
	}
    return 0;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int *ans,n=0;
	ans=malloc(100*sizeof(int));
    if(root!=NULL)
        GetVal(root,ans,&n);
    *returnSize=n;
    return ans;
}

int main(){

}