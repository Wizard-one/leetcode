#include <test.h>

/* 337. 打家劫舍 III

小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
 */

// #动态规划 #二叉树
/* 自顶而下的动态规划

每一个节点的选择就是 抢 / 不抢 所以状态也只有 被抢 与 不被抢

那么就是对于遍历这个二叉树需要在什么位置进行选择. 因为不涉及到左右节点的选择,所以不是中序遍历

那么进入节点前能否知道当前节点是否被选择呢? 可以

具体来说就是, 前序决定 抢 or 不抢 然后抢就去下下家,不抢就去下家 然后比较两者结果,
但这样就需要通过 备忘录来记录当前节点是否已经被选择过,(消除重叠子问题)

那么在离开节点后能否决定当前节点是否选择呢? 可以 更加巧妙

我们只需在每一个节点记录2个状态,当前节点抢 or 不抢

然后退出节点前比较,当前抢,下一个不抢 与 当前抢,下一个可抢可不抢的大小即可
 */
#define IMAX(a,b) (a>b)?(a):(b)
int* travel(struct TreeNode * root)
{
	int *ans;
	ans=calloc(2,sizeof(int));
	if(!root)
		return ans;
	int* lval=travel(root->left);
	int* rval=travel(root->right);
	// 当前抢,下一个不抢
	int rob=root->val+lval[1]+rval[1];
	// 当前不抢,下一个可抢可不抢,看大小
	int norob=(IMAX(lval[0],lval[1]))+(IMAX(rval[0],rval[1]));
	ans[0]=rob;
	ans[1]=norob;
	return ans;
}

int rob(struct TreeNode* root){
	int* ans=travel(root);
	return IMAX(ans[0],ans[1]);
}