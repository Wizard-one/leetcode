#include <test.h>
#include <stdio.h>
#include <stdlib.h>

// #BST #二叉树 #中序遍历 #递归 #二分法
/* 将排序好的数组转化为一颗二叉搜索树

确定好可以选择中间节点作为root 之后 就可以通过拆分区间来实现递归

实际上只需要传递区间的两个端点，不需要进行区间的赋值
 */
struct TreeNode* CreateBSTNode(int* nums, int left,int right)
{
	if (left>right)
	{
		return NULL;
	}
	int mid=(left+right)/2;
	struct TreeNode *new;
	new=malloc(sizeof(struct TreeNode));
	new->val=nums[mid];
	new->left=CreateBSTNode(nums,left,mid-1);
	new->right=CreateBSTNode(nums,mid+1,right);
	return new;
}



struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
	struct TreeNode *root;
	root=CreateBSTNode(nums,0,numsSize-1);
	return root;
}


int main(){
	int l[]={-10,-3,0,4,5,9};
	struct TreeNode *root=sortedArrayToBST(l,6);
	TreePrint(root);
}