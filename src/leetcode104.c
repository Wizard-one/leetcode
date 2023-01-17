#include <test.h>
// #二叉树 #递归 #前序搜索 #深度优先搜索


/* 104. 二叉树的最大深度

给定一个二叉树，找出其最大深度。

 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。
 */

/* 简单的深度优先搜索，维护当前深度与最大深度两个变量 */
#define IMAX(a,b) (a>b)?(a):(b)
void GetDeepth(struct TreeNode* root,int *deep,int *maxdeep)
{	
	if (root==NULL)
	{
		*maxdeep=IMAX(*deep,*maxdeep);//记录最深的栈
		return;
	}
	// 前序位置记录深度
	(*deep)++;
	GetDeepth(root->left,deep,maxdeep);
	GetDeepth(root->right,deep,maxdeep);
	//后序位置弹栈都回退深度
	(*deep)--;
    return;
}

int maxDepth(struct TreeNode* root){
	int maxdeep=0,deep=0;
	if (!root)
	{
		return maxdeep;
	}
	GetDeepth(root,&deep,&maxdeep);
	return maxdeep;
}

int main(){
	int l[]={0,3,9,-1,-1,20,15,-1,-1,7,-1,-1},i=0;
	struct TreeNode * T;
	TreeInit(&T,l,&i);
	i=maxDepth(T);
	printf("%d",i);

}