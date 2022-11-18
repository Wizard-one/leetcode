#include <test.h>
#define IMAX(a,b) (a>b)?(a):(b)
// #二叉树 #递归 #前序搜索 #深度搜索
void GetDeepth(struct TreeNode* root,int *deep,int *maxdeep)
{
	
	(*deep)++;
	if (root==NULL)
	{
		(*deep)--;//每一次递归弹栈都减少一次度深度
		*maxdeep=IMAX(*deep,*maxdeep);//记录最深的栈
		return;
	}
	GetDeepth(root->left,deep,maxdeep);
	GetDeepth(root->right,deep,maxdeep);
	(*deep)--;
    return;
}

int maxDepth(struct TreeNode* root){
	int maxdeep=0,deep=0;
	if (!root)
	{
		return maxdeep;
	}
	GetDeepth(root,&deep,&maxdeep);
	return maxdeep;
}

int main(){
	int l[]={0,3,9,-1,-1,20,15,-1,-1,7,-1,-1},i=0;
	struct TreeNode * T;
	TreeInit(&T,l,&i);
	i=maxDepth(T);
	printf("%d",i);

}