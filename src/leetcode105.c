#include <test.h>
#include <stdio.h>
#include <stdlib.h>
// #二叉树 #先序遍历 #中序遍历 #mid #递归 #hash

/* 105. 从前序与中序遍历序列构造二叉树
难点有以下几点:
- 确定中序遍历与先序遍历之间关系，以及弄明白为什么能唯一确定一颗二叉树
- 提取出两者之间关键信息: 先序遍历提供什么是根节点，中序遍历提供左右子树分别有多少个
- 如何用先序遍历递归维护树的构建过程
- 想到使用hash表降低搜索下标时间复杂度

总体思想:
先序遍历为
root->left tree-> right tree
中序遍历为
left tree->root-> right tree
可以发现先序遍历直接给出了一个先序遍历区间第一个节点为根节点，但是没有给出哪些节点属于左子树，哪些节点属于右子树。
而通过先序遍历确定根节点之后，在中序遍历中定位到根节点idx 就能发现左边的全是左子树，右边的全是右子树。从而获得了左右子树的节点数目

确定了左右子树节点数目之后回到对先序遍历数组拆分例如
3 | 9 | 20 15 7
ro  l   right
然后将分组后左右区间分别递归的创建左右子树
 */

/**
 * @brief 构建子树
 * 
 * @param hash 中序遍历的hash 表 key=tree node value; value=该value 对应的中序遍历idx 
 * @param preorder 先序遍历数组
 * @param preleft 先序遍历中左子树开始的位置
 * @param preright 先序遍历中右子树开始的位置
 * @param instart 中序遍历序列中一颗子树开始位置
 * @param inend 中序遍历序列中一颗子树结束位置
 * @return struct TreeNode* 
 */
struct TreeNode* subTree(int *hash,int* preorder,int preleft,int preright,int instart,int inend)
{
	if (preleft>preright)
	{
		return NULL;
	}
	struct TreeNode *root=malloc(sizeof(struct TreeNode));
	root->val=preorder[preleft];//先序遍历区间第一个节点为根节点
	int inroot=hash[root->val+3000];//中序遍历中定位到根节点idx
	int lnum=inroot-instart;//left subtree num
 	// 左子树创建:
	// 先序列表左子树开始位置显然就是当前根节点+1, 右子树开始位置就是左子树的数目+当前根节点位置
	// 中序列表开始位置不变，结束位置是当前根节点位置-1
	root->left=subTree(hash,preorder,preleft+1,preleft+lnum,instart,inroot-1);
	// 右子树创建:
	// 先序列表左子树开始位置是当前根节点+1+左子树长度, 右子树开始位置不变
	// 中序列表开始位置是当前根节点位置+1，结束位置不变
	root->right=subTree(hash,preorder,lnum+preleft+1,preright,inroot+1,inend);
	return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
	int hash[6000]={0};
	struct TreeNode*root;
	// 构建hash表降低搜索复杂度
	for (size_t i = 0; i < inorderSize; i++)
	{
		hash[inorder[i]+3000]=i;
	}
	root=subTree(hash,preorder,0,preorderSize-1,0,preorderSize-1);
	return root;
}

int main(){
	int pre[]={3,9,20,15,7},in[]={9,3,15,20,7};
	buildTree(pre,5,in,5);
}