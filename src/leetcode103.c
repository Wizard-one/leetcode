#include <stdio.h>
#include <stdlib.h>
#include <test.h>

// #层序遍历 #二叉树 [[114]] [[116]] [[102]]

/* 
二叉树的锯齿形层序遍历
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

需要翻转返回结果就应该想到利用stack的性质，FILO。同时调整子树入栈顺序就可以work了
 */

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	int **ans;
	(*returnSize)=0;
	*returnColumnSizes=calloc(sizeof(int),2000);
	if (root==NULL)
	{
		return ans;
	}
	int **result=malloc(sizeof(int*)*2000);
	struct TreeNode **stack,**prevstack;//需要维护2个栈，因为不能让下一层结果提前进入本层
	stack=malloc(sizeof(struct TreeNode *)*2000);
	prevstack=malloc(sizeof(struct TreeNode *)*2000);
	int top=0,prevtop=0,filp=1;
	prevstack[prevtop++]=root;
	while (prevtop>0)
	{
		int col=0;
		result[*returnSize] = (int*)malloc(sizeof(int) * (prevtop));
		// 将本层的栈用空
		while (prevtop>0)	
		{
			root=prevstack[(prevtop-1)];
			prevtop--;
			result[*returnSize][col++]=root->val;
			// 结果存到下一层的栈当中
			if (filp)
			{
				// 从左向右遍历就从左向右入栈
				if (root->left!=NULL)
					stack[(top)++]=root->left;
				if (root->right!=NULL)		
					stack[(top)++]=root->right;
			}
			else
			{
				// 从右向左就反之
				if (root->right!=NULL)		
					stack[(top)++]=root->right;
				if (root->left!=NULL)
					stack[(top)++]=root->left;
			}
		}
		if (filp)
			filp=0;
		else
			filp=1;		
		(*returnColumnSizes)[*returnSize]=col;
		(*returnSize)++;
		// 让本层栈与下一层栈交换,即下一层变成本层,本层(空栈) 变成下一层
		struct TreeNode **tmpstack;
		int tmp;
		tmp=top;
		top=prevtop;
		prevtop=tmp;
		tmpstack=stack;
		stack=prevstack;
		prevstack=tmpstack;
	}
	return result;
}

int main(){
	int pre[]={3,9,20,15,7},in[]={9,3,15,20,7};
	struct TreeNode *root=TreeInit_prein(pre,in,5);
	int resize,*recolsize,**re;
	re=zigzagLevelOrder(root,&resize,&recolsize);

}
