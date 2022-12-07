#include <test.h>
#include <stdio.h>
#include <stdlib.h>
// #中序遍历 #递归 #二叉树 #BST time: O(H+k) H树高度 最大值为N+k space: O(H) 最多用树高度个栈维护值
/*  二叉搜索树中第K小的元素
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

简单的中序遍历,要注意值的选取与维护都需要在中序中完成
 */

int dfs(struct TreeNode* root, int *k){
	int v1,v2;
	if (!root)
	{
		return -1;
	}
	v1=dfs(root->left,k);
	// k的维护在中间才是中序遍历
	(*k)--;
	if ((*k)==0)
		return root->val;
	v2=dfs(root->right,k);
	if (v1!=-1)
		return v1;
	if(v2!=-1)
		return v2;
	return -1;
}


int kthSmallest(struct TreeNode* root, int k){
	return dfs(root,&k);
}
