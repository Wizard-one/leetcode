#include <test.h>

// #二叉树 #前序遍历

/* 226. 翻转二叉树

给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。 */


void swap(struct TreeNode **a,struct TreeNode **b)
{
	struct TreeNode *t=*a;
	*a=*b;
	*b=t;
}
/* 前序遍历去翻转 */
void invert(struct TreeNode **l, struct TreeNode **r)
{
	if ((*l)==NULL&&(*r)==NULL)
	{
		return;
	}
	else if((*l)==NULL&&(*r)!=NULL)
	{
		(*l)=*r;
		(*r)=NULL;
		invert(&((*l)->left),&((*l)->right));
		return;
	}
	else if((*r)==NULL&&(*l)!=NULL)
	{
		(*r)=*l;
		(*l)=NULL;
		invert(&((*r)->left),&((*r)->right));
		return;
	}

	swap(l,r);
	invert(&((*l)->left),&((*l)->right));
	invert(&((*r)->left),&((*r)->right));
}


struct TreeNode* invertTree(struct TreeNode* root){
	if (!root)
	{
		return NULL;
	}
	
	invert(&(root->left),&(root->right));
	return root;
}

int main(){
	int l[]={0,1,2,-1,-1,-1},i=0;
	struct TreeNode *T;
	bool ans;
	TreeInit(&T,l,&i);
	invertTree(T);
	printf("%d",ans);
}