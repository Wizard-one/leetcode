#include <test.h>
/*
124. 二叉树中的最大路径和

 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。 */

// #路径和 #二叉树 #子问题

/* 每一个节点维护当前的路径和，同时在考虑当前节点最大路径和时需要将左右子树的路径和相加再加上自己节点值

关键在于每个节点返回是路径和 而不是 最大路径和
 */

// 返回当前节点的路径和，传入最大路径和进行全局求解
int pathSum(struct TreeNode* root,int *maxsum)
{
	if (!root)
	{
		return 0;
	}
	int leftsum=pathSum(root->left,maxsum);//左子树路径和
	int rightsum=pathSum(root->right,maxsum);//右子树路径和
	int mysum=leftsum+rightsum+root->val;//左右子树路径和+自己 当前节点的可能最大路径和
	int mypathsum=fmax(leftsum,rightsum)+root->val;//当前节点路径和较大的那一个
	mypathsum=fmax(root->val,mypathsum);//可能路径叠加都是负数，所以还需要和自己比较一下
	//维护最大路径和时需要考虑 mysum
	*maxsum=fmax((*maxsum),mypathsum);
	(*maxsum)=fmax(mysum,(*maxsum));
	// 但由于不能走回头路，所以还是返回路径和，例如
	/* 
	  4
	/   \
	11  15
	/\
	7 2
	2是不能走的
	 */
	return mypathsum;
}


int maxPathSum(struct TreeNode* root){
	int max=-1002;
	pathSum(root,&max);
	return max;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
