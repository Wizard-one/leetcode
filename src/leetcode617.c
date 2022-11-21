#include <test.h>
#include <stdio.h>
#include <stdlib.h>
// #树 #递归
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
	if (!root1)
	{
		return root2;
	}
	else if (!root2)
	{
		return root1;
	}

	struct TreeNode *merge;
	merge=malloc(sizeof(struct TreeNode));
	merge->val=root1->val+root2->val;
	merge->left=mergeTrees(root1->left,root2->left);
	merge->right=mergeTrees(root1->right,root2->right);
	return merge;	
}

int main(){
	struct TreeNode* r1,*r2,*ans;
	int l1[]={0,1,3,5,-1,-1,4,-1,-1,2,-1,-1},i=0;
	TreeInit(&r1,l1,&i);
	i=0;
	int l2[]={0,2,1,-1,4,-1,-1,3,-1,7,-1,-1};
	TreeInit(&r2,l2,&i);
	ans=mergeTrees(r1,r2);
	TreePrint(ans);
}