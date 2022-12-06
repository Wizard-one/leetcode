#include <test.h>
#include <stdio.h>
#include <stdlib.h>

// #BST #二叉树 #中序遍历 #递归 time: O(n) space: O(n)

/* 450. 删除二叉搜索树中的节点

给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

    首先找到需要删除的节点；
    如果找到了，删除它。

有以下几个难点:
- 坚定的使用递归deleteNode函数本身来实现
- 分类讨论

就如提示所说分成两步
1. 找节点，这就根据BST性质去递归的找
2. 删除节点
需要分情况讨论被删除节点的情况
1. 左右子叶都为空: 删除本身
2. 左子叶为空: 返回右子叶
3. 右子叶为空: 返回左子叶
3. 都不为空: 找树中最小节点替换
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key){
	if (!root)
	{
		return NULL;
	}
	
	if (root->val>key)
	{
		// 当前值大于key key一定在左子树，所以左子树是更新过的
		root->left=deleteNode(root->left,key);
		return root;
	}
	else if (root->val<key)
	{
		/* 同理 */
		root->right=deleteNode(root->right,key);
		return root;
	}
	else
	{
		if (!root->left&&!root->right)
		{
			// 左右节点都为空
			// 直接删除自身
			return NULL;
		}
		else if (root->left&&!root->right)
		{
			// 左子树不为空，右子树为空
			// 返回左子树
			return root->left;
		}
		else if (!root->left&&root->right)
		{
			/* 反之亦然 */
			return root->right;
		}
		else
		{
			// 左右子树都不为空
			/* 将当前节点替换为右子树的最小节点 */
			struct TreeNode *swp=root->right;
			while (swp->left)
			{
				/* 最小节点一定在一个没有左子树的节点，BST性质 */
				swp=swp->left;
			}
			// 因为要替换，所以要在当前节点的右子树中删除替换的节点，不然返回值还是会被保留
			root->right=deleteNode(root->right,swp->val);
			// 将原有节点的左右子树继承到替换后的节点
			swp->left=root->left;
			swp->right=root->right;
			//这里返回就代表了替换调原有节点
			return swp;
		}
		
	}
	
}


int main(){
	int in[]={2,3,4,5,6,7},pre[]={5,3,2,4,6,7};
	struct TreeNode *root=TreeInit_prein(pre,in,6);
	root=deleteNode(root,3);
	TreePrint(root);
}