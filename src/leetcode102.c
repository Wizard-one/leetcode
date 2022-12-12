#include <test.h>
#include <stdlib.h>


// #层序遍历 #二叉树 [[114]] #广度优先搜索 [[116]] #mid

/* 102. 二叉树的层序遍历

给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。 
*/

/* 标准层序遍历，一般来说是通过队列迭代去维护层序遍历的，即广度优先搜索 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	int **ans;
	(*returnSize)=0;
	*returnColumnSizes=calloc(sizeof(int),2000);
	if (root==NULL)
	{
		return ans;
	}
	int **result=malloc(sizeof(int*)*2000);
	struct TreeNode **queue;
	queue=malloc(sizeof(struct TreeNode *)*2000);
	int front=0,rear=0;
	queue[front++]=root;
	while ((front)!=(rear))
	{
		int last=(front);//标记当前层位置
		int col=0;
        result[*returnSize] = (int*)malloc(sizeof(int) * (last - (rear)));
		while ((rear)<last)	
		{
			// 从头部出队
			root=queue[(rear)++];
			result[*returnSize][col++]=root->val;
			// 将左右子树入队
			if (root->left!=NULL)
				queue[(front)++]=root->left;
			if (root->right!=NULL)		
				queue[(front)++]=root->right;
		}
		(*returnColumnSizes)[*returnSize]=col;
		(*returnSize)++;
	}
	return result;
}

int main(){
	struct TreeNode *t=TreeNodeInit(3);
	t->left=TreeNodeInit(9);
	t->right=TreeNodeInit(20);
	t->right->right=TreeNodeInit(7);
	t->right->left=TreeNodeInit(15);
	int r,*rr;
	levelOrder(t,&r,&rr);
}