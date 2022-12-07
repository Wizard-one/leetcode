from lib.test import *

# #二叉树 [[235]] #递归

""" 236. 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

采用了一个非常精巧的设计, 结果一共有3种情况
1. p q 分别位于左右子树上-> 公共先祖就是当前root
2. p, q 同时位于左子树-> 公共先祖就是当前root 的左子树
3. p, q 同时位于右子树-> 公共先祖就是当前root 的右子树

使用先序遍历去搜索目标两个节点。栈最深一层必然返回q或p本身。

情况2,3: 当从左/右子树上只搜到p or q时,说明p, q本身就是公共先祖. 

情况1: 当同时返回 p,q 的root 不论root 处于初始root的什么子树, 只要不进一步修改该root值, 栈的回溯保证了该root就是最近先祖
"""

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # 先序搜索
        if(root==p or root==q or root==None):
            return root
        # 遍历左子树
        left=self.lowestCommonAncestor(root.left,p,q)
        # 遍历右子树
        right=self.lowestCommonAncestor(root.right,p,q)
        # 如果返回的左右节点都不为空，说明两个节点分别位于左右子树，那么公共先祖就是当前root
        if left!=None and right!=None:
            return root
        # 如果右节点是空的，显然公共先祖是左节点，反之亦然
        if left!=None:
            return left
        else:
            return right
        

                
if __name__ == "__main__":
    s=Solution().lowestCommonAncestor
    root=TreeInit_prein([3,5,6,2,7,4,1,0,8],[6,5,7,2,4,3,0,1,8])
    # root=s(root,5,4)
    r1=TreeNode(1)
    r1.left=TreeNode(2)
    r1.right=TreeNode(3)
    root=s(r1,TreeNode(3),TreeNode(2))
    print(root.val)