#include <test.h>
#include <stdbool.h>
// #BST [[leetcode700]] #中序遍历
#include <limits.h>

//中序遍历
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

	return ans1&&ans2;
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