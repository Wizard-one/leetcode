#include <test.h>
#include <stdbool.h>
// #BST [[leetcode700]] #中序遍历 [[92]]
#include <limits.h>

/* 98. 验证二叉搜索树
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

    节点的左子树只包含 小于 当前节点的数。
    节点的右子树只包含 大于 当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。
 */

/* BST按照中序遍历就是递增序列，所以只需要记录前一个值然后比较即可 */
bool midVaildBST(struct TreeNode *root,int* val)
{
	bool ans1,ans2;
	if (!root)
	{
		return true;
	}
	ans1=midVaildBST(root->left,val);
	if (root->val<=*val)
	{
		return false;
	}
	*val=root->val;//记录前一个val
	ans2=midVaildBST(root->right,val);

	return ans1&&ans2;//递归完成后的返回形式
}

bool isValidBST(struct TreeNode* root){
	long pre=LONG_MIN;//注意数据范围，要么使用这个，要么对左子树遍历一次获取firstleftchild
	return midVaildBST(root,&pre);
}

int main(){
	// int l[]={0,0,-2,-1,-1,-1};
	int l[]={0,2,1,-1,-1,3,-1,-1};
	int i=0;
	struct TreeNode* T;
	TreeInit(&T,l,&i);
	TreePrint(T);
	printf("%d",isValidBST(T));
}