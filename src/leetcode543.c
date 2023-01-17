#include <test.h>


/*
543. 二叉树的直径

 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
 */
// #二叉树 #遍历 #后序

#define IMAX(a,b) (a>b)?(a):(b)
/* 最大直径为每一个节点左子树最大深度+右子树最大深度的最大值

最大深度使用后序遍历进行维护，而最大直径再退出节点时也可以顺便维护了
 */
int traverse(struct TreeNode* root,int *maxD)
{
	if (!root)
	{
		return 0;
	}
	int leftdepth=traverse(root->left,maxD);
	int	rightdepth=traverse(root->right,maxD);
	int D=leftdepth+rightdepth;//当前节点的最大直径
	(*maxD)=IMAX(D,(*maxD));//维护全局最大直径
	return 1+(IMAX(leftdepth,rightdepth));//返回最大深度
}
int diameterOfBinaryTree(struct TreeNode* root){
	int maxD=0;
	traverse(root,&maxD);
	return maxD;
}

int main(int argc, char const *argv[])
{
	struct TreeNode *head;
	int l[]={-1,2,3,1,-1,-1,-1,-1},i=0;
	TreeInit(&head,l,&i);
	int ans=diameterOfBinaryTree(head);
	printf("%d",ans);
	return 0;
}
