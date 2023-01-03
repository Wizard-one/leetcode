#include <test.h>

/* 572. 另一棵树的子树

给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。

二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
  */

// #深度优先搜索 #子树 #二叉树

/* 
核心在于如何进行root 与 subroot 的同步移动，此处同步的含义有两个
- 同步向下移动
- 同步回退

考虑到一下这种val值出现相同但子树不一定相同的情况
root    subroot
  1        1
1

[3,4,5,1,null,2] ，[3,1,2] 

必须使用2个函数来维护，单个函数无法维护对于root子树的搜索

 */
// 专门用于搜索，检测当前root树是否和subRoot 完全一致
bool dfs(struct TreeNode * root,struct TreeNode* subRoot)
{
	if (!root&&!subRoot)
	{
		return true;
	}
	if ((!root&&subRoot)||(root&&!subRoot)||(root->val!=subRoot->val))
	{
		return false;
	}
	return dfs(root->left,subRoot->left)&&dfs(root->right,subRoot->right);	
}

// 维护子树搜索路径，维护搜索root的子树
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
	if (!root)
	{
		return false;
	}
	// 先搜搜当前root是否和subroot相同， 然后再搜右左子树，然后再搜索右子树
	return dfs(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
}

int main(int argc, char const *argv[])
{
	struct TreeNode *root,*sub;
	bool ans;
	int pre[]={3,4,1,5,2},mid[]={1,4,3,2,5},subpre[]={3,1,2},submid[]={1,3,2};
	root=TreeInit_prein(pre,mid,5);
	sub=TreeInit_prein(subpre,submid,3);
	ans=isSubtree(root,sub);
	// struct TreeNode *root1,*sub1;
	// int l[]={0,1,1,-1,-1,-1},subl[]={0,1,-1,-1};
	// int i=0;
	// TreeInit(&root1,l,&i);
	// i=0;
	// TreeInit(&sub1,subl,&i);
	// ans=isSubtree(root1,sub1);
	printf("%d",ans);
	return 0;
}
