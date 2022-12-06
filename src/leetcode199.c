#include <test.h>
#include <stdlib.h>

// #层序遍历 #二叉树 [[114]] [[116]] [[102]] #广度优先搜索
/* 
199. 二叉树的右视图
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

测试用例给的很trick 要考虑
[1,2,3,null,5,null,4,6,9,null,null,8] 这种树的形状,即不能只是遍历最右侧节点,而是遍历每一个深度最右侧节点

有了深度这个概念可以用DFS 维护每一个深度只保存最右侧节点即可

这边采用的是BFS 其实就是返回层序遍历的最后一个节点.
 */

int* rightSideView(struct TreeNode* root, int* returnSize){
	int *result;
	(*returnSize)=0;
	if (root==NULL)
	{
		return result;
	}
	result=malloc(sizeof(int)*100);
	struct TreeNode **queue;//使用滑动窗来维护一个队列,内存有些浪费
	queue=malloc(sizeof(struct TreeNode *)*100);
	int front=0,rear=0;
	queue[front++]=root;
	while ((front)!=(rear))
	{
		int last=(front);//标记当前层位置
		while ((rear)<last)	
		{
			root=queue[rear];
			// 只保存层序遍历的最后一个节点
			if (rear==last-1)
			{
				result[*returnSize]=root->val;
			}
			rear++;
			if (root->left!=NULL)
				queue[(front)++]=root->left;
			if (root->right!=NULL)		
				queue[(front)++]=root->right;
		}
		(*returnSize)++;
	}
	return result;
}

int main(){
	int pre[]={1,2,5,3,4},in[]={2,5,1,3,4};
	struct TreeNode *root=TreeInit_prein(pre,in,5);
	int resize,*res;
	res=rightSideView(root,&resize);
	for (size_t i = 0; i < resize; i++)
	{
		printf("%d,",res[i]);
	}
}