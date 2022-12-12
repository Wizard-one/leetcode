#include <stdio.h>
#include <stdbool.h>
#include <test.h>

// #递归 #二叉树 [[leetcode700]] #深度优先搜索 time: O(N) space: O(H) 树深度

/*112. 路径总和

 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

叶子节点 是指没有子节点的节点。 */


bool hasPathSum(struct TreeNode* root, int targetSum){
	if (!root)
	{
		// 给了一个空树
		return false;
	}
	else if(root->left==NULL && root->right==NULL)
	{
		// 到达叶子节点
		return targetSum==root->val;
	}
	// 没到达就减去当前值,搜余下值
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