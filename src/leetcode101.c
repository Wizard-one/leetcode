#include <test.h>

// #递归 #二叉树 

bool check(struct TreeNode* l,struct TreeNode *r)
{
	if (!l&&!r)
		return true;
	if (!l||!r)
		return false;

	return l->val==r->val && check(l->left,r->right) && check(l->right,r->left);
}

bool isSymmetric(struct TreeNode* root){
	if ((!root->left)&&(!root->right))
	{
		return true;
	}
	else if ((root->left!=NULL)&&(root->right==NULL))
	{
		return false;
	}
	else if ((root->right!=NULL)&&(root->left==NULL))
		return false;
	return check(root->left,root->right);
}

int main(){
	int l[]={0,1,2,3,-1,-1,4,-1,-1,2,4,-1,-1,3,-1,-1},i=0;
	struct TreeNode *T;
	bool ans;
	CreateBiTree(&T,l,&i);
	ans=isSymmetric(T);
	printf("%d",ans);
}