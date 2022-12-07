from lib.test import *

# #设计 #BST #中序遍历
class BSTIterator:
	""" 173. 二叉搜索树迭代器
	实现一个二叉搜索树迭代器类BSTIterator ,表示一个按中序遍历二叉搜索树(BST)的迭代器：

    BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字,且该数字小于 BST 中的任何元素。
    boolean hasNext() 如果向指针右侧遍历存在数字,则返回 true ；否则返回 false 。
    int next()将指针向右移动,然后返回指针处的数字。

	注意,指针初始化为一个不存在于 BST 中的数字,所以对 next() 的首次调用将返回 BST 中的最小元素。

	你可以假设 next() 调用总是有效的,也就是说,当调用 next() 时,BST 的中序遍历中至少存在一个下一个数字。
	"""
	""" 
	用栈去模拟中序遍历的过程
	"""
	def __init__(self, root: Optional[TreeNode]):
		self.stack:List[TreeNode]=[]
		self.cur=root

	def next(self) -> int:
		# 前置先将所有左子树加入
		while self.cur!=None:
			self.stack.append(self.cur)
			self.cur=self.cur.left

		self.cur=self.stack.pop()
		val=self.cur.val
		# 后置将加入一个右子树
		self.cur=self.cur.right
		return val


	def hasNext(self) -> bool:
		# 因为栈不是一开始就做好的所以要检测指针是否为空
		return self.cur!=None or len(self.stack)!=0


if __name__ == "__main__":
	case=["next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]
	bst=TreeInit_prein([7,3,15,9,20],[3,7,9,15,20])
	obj=BSTIterator(bst)
	for op in case:
		val=eval(f"obj.{op}()")
		print(val)
	
# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()