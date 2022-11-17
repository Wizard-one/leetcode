#include <test.h>
#include <stdlib.h>

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
	struct TreeNode* root;
	while ((front)!=(rear))
	{
		int last=(front);//标记当前层位置
		int col=0;
        result[*returnSize] = (int*)malloc(sizeof(int) * (last - (rear)));
		while ((rear)<last)	
		{
			root=queue[(rear)++];
			result[*returnSize][col++]=root->val;
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

/* int** levelOrder(struct TreeNode* root,int* returnSize,int** returnColumnSizes)
{
    *returnSize = 0;
    if(root == NULL)
        return NULL;
    int** returnNums = (int**)malloc(sizeof(int*) * 2001);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2001);
    struct TreeNode* queueDat[2001];
    int  queueFront = 0;
    int  queueRear  = 0;
    struct TreeNode* cur;

    queueDat[queueRear++] = root;
    while(queueFront != queueRear)
    {
        int colSize = 0;
        int last = queueRear;
        returnNums[*returnSize] = (int*)malloc(sizeof(int) * (last - queueFront));
        while(queueFront < last)
        {
            cur = queueDat[queueFront++];
            returnNums[*returnSize][colSize++] = cur ->val;
            if(cur -> left != NULL)
                queueDat[queueRear++] = cur -> left;
            if(cur -> right != NULL)
                queueDat[queueRear++] = cur -> right;
        }
        (*returnColumnSizes)[*returnSize] = colSize;
        (*returnSize)++;
    }
    return returnNums;
}
 */
int main(){
	struct TreeNode *t=TreeNodeInit(3);
	t->left=TreeNodeInit(9);
	t->right=TreeNodeInit(20);
	t->right->right=TreeNodeInit(7);
	t->right->left=TreeNodeInit(15);
	int r,*rr;
	levelOrder(t,&r,&rr);
}