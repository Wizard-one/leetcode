#include <test.h>

// #二叉树 #迭代 [[leetcode700]] #BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
	struct TreeNode *ans=malloc(sizeof(struct TreeNode)),*cur=root;
    
	ans->val=val;
	ans->left=NULL;
	ans->right=NULL;
    if(!root)
        return ans;
	while (1)
	{
		if (cur->val<val)
		{
			if (cur->right!=NULL)
			{
				cur=cur->right;
			}
			else
			{
				cur->right=ans;
				return root;
			}
		}
		else
		{
			if (cur->left!=NULL)
				cur=cur->left;
			else
			{
				cur->left=ans;
				return root;
			}
		}
	}
	return root;
}

int main(){
	int l[]={0,4,2,1,-1,-1,3,-1,-1,7,-1,-1},i=0;
	struct TreeNode *T,*ans;
	TreeInit(&T,l,&i);
	ans=insertIntoBST(T,5);
	TreePrint(ans);
}