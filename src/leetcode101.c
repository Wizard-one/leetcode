#include <test.h>

// #递归 #二叉树 

/* 101. 对称二叉树
给你一个二叉树的根节点 root ， 检查它是否轴对称。 */


/* 对称的维护就是镜像的去检查
 */
bool check(struct TreeNode* l,struct TreeNode *r)
{
	if (!l&&!r)
		return true;
	if (!l||!r)
		return false;
	// 根节点的左子树向左走，右子树向右走，同样的检查左子树的右子树与右子树的左子树
	return l->val==r->val && check(l->left,r->right) && check(l->right,r->left);
}

bool isSymmetric(struct TreeNode* root){
	/* 因为要访问左右子树所以需要单独处理这些情况 */
	if ((!root->left)&&(!root->right))
	{
		return true;
	}
	else if ((root->left!=NULL)&&(root->right==NULL))
	{
		return false;
	}
	else if ((root->right!=NULL)&&(root->left==NULL))
		return false;
	return check(root->left,root->right);
}

int main(){
	int l[]={0,1,2,3,-1,-1,4,-1,-1,2,4,-1,-1,3,-1,-1},i=0;
	struct TreeNode *T;
	bool ans;
	TreeInit(&T,l,&i);
	ans=isSymmetric(T);
	printf("%d",ans);
}