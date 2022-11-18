#include <stdio.h>
#include <stdbool.h>
#include <test.h>

// #递归 #二叉树 [[leetcode700]]
bool hasPathSum(struct TreeNode* root, int targetSum){
	if (!root)
	{
		return false;
	}
	else if(root->left==NULL && root->right==NULL)
	{
		return targetSum==root->val;
	}
	return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);
}
int main(){
	int l[]={0,5,4,11,7,-1,-1,2,-1,-1,-1,8,13,-1,-1,4,-1,1,-1,-1};
	int i=0,ans=0;
	struct TreeNode *t;
	TreeInit(&t,l,&i);
	ans=hasPathSum(t,22);
	printf("%d",ans);
}