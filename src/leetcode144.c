#include <stdlib.h>
#include <stdio.h>
#include <test.h>

// #树 #递归 #前序搜索
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