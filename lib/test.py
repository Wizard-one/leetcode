from typing import Optional,List,Set,Tuple
import collections
import math
import queue

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def ListInit(nums:List[int]):
	dummy=ListNode()
	cur=dummy
	for i in nums:
		cur.next=ListNode(i)
	return dummy.next

def ListPrint(l:ListNode):
	"""
	docstring
	"""
	s=""
	while(l):
		s+=f"{l.val}"
		l=l.next
	print(s)

def	TreeInit(nums:List[int],idx:List[int])->TreeNode:
	"""
	为了保证是地址传递 idx必须是list
	"""
	idx[0]+=1
	if(nums[idx[0]]==-1):
		return None
	else:
		T=TreeNode()
		if(T==None):
			raise ValueError
		T.val=nums[idx[0]]
		T.left=TreeInit(nums,idx)
		T.right=TreeInit(nums,idx)
		return T
		
def HeapAdjust(nums:List[int],start:int,end:int):
	""" 大顶堆的调整 """
	parent=start
	child=start*2+1
	while(child<=end):
		if child<end and nums[child]<nums[child+1]:
			child+=1
		if nums[parent]>nums[child]:
			return
		else:
			temp=nums[child]
			nums[child]=nums[parent]
			nums[parent]=temp
			parent=child
			child=child*2+1

def TreeInit_prein(preorder: List[int], inorder: List[int]) -> TreeNode:
	""" 
	根据先序遍历与中序遍历构造二叉树，但二叉树val 不能有重复
	"""
	def myBuildTree(preorder_left: int, preorder_right: int, inorder_left: int, inorder_right: int):
		if preorder_left > preorder_right:
			return None
		
		# 前序遍历中的第一个节点就是根节点
		preorder_root = preorder_left
		# 在中序遍历中定位根节点
		inorder_root = index[preorder[preorder_root]]
		
		# 先把根节点建立出来
		root = TreeNode(preorder[preorder_root])
		# 得到左子树中的节点数目
		size_left_subtree = inorder_root - inorder_left
		# 递归地构造左子树，并连接到根节点
		# 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
		root.left = myBuildTree(preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1)
		# 递归地构造右子树，并连接到根节点
		# 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
		root.right = myBuildTree(preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right)
		return root
	
	n = len(preorder)
	# 构造哈希映射，帮助我们快速定位根节点
	index = {element: i for i, element in enumerate(inorder)}
	return myBuildTree(0, n - 1, 0, n - 1)