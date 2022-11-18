#include <test.h>

// #二叉树 #递归
void swap(struct TreeNode **a,struct TreeNode **b)
{
	struct TreeNode *t=*a;
	*a=*b;
	*b=t;
}

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
	CreateBiTree(&T,l,&i);
	invertTree(T);
	printf("%d",ans);
}