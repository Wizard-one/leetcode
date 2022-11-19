#include <test.h>

// #二叉树 #迭代 [[leetcode700]] #BST

/**
 * @brief 二叉搜索树的插入
 * 
 * @param root 被插入的BST
 * @param val 被插入的val
 * @return struct TreeNode* 
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
	struct TreeNode *ans=malloc(sizeof(struct TreeNode)),*cur=root;
    
	ans->val=val;
	ans->left=NULL;
	ans->right=NULL;
    if(!root)
        return ans;
	while (1)
	{
		// 当前val 小于目标，说明应该插入到右侧
		if (cur->val<val)
		{
			/* 右侧非空说明还有值继续向右搜索 */
			if (cur->right!=NULL)
			{
				cur=cur->right;
			}
			/* 右侧空了说明可以插入 */
			else
			{
				cur->right=ans;
				return root;
			}
		}
		else
		{
			// 当前val 小于目标，说明应该插入到左侧
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