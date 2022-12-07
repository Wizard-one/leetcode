from lib.test import *

#  #二叉树 #序列化 #设计 #hard

""" 297. 二叉树的序列化与反序列化
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
""" 
class Codec:
	"""
	前序遍历实现字符串输出，然后同样前序遍历解析字符串
	"""

	def __init__(self):
		"""
		存一个类的属性，用于保存序列化的字符串
		"""
		self.data=""

	def preorder(self,root:TreeNode,):
		"""
		简单的前序遍历，用NULL标记空节点
		"""
		if(root==None):
			self.data+=" NULL"
			return
		
		self.data+=f" {root.val}"
		self.preorder(root.left)
		self.preorder(root.right)
		
	def	TreeInit(self,nums:List[int],idx:List[int])->TreeNode:
		"""
		为了保证是地址传递 idx必须是list
		"""
		idx[0]+=1
		if(nums[idx[0]]==None):
			return None
		else:
			T=TreeNode()
			if(T==None):
				raise ValueError
			T.val=nums[idx[0]]
			T.left=self.TreeInit(nums,idx)
			T.right=self.TreeInit(nums,idx)
			return T

	def serialize(self, root):
		"""Encodes a tree to a single string.
		
		:type root: TreeNode
		:rtype: str
		"""
		self.preorder(root)
		return self.data
		

	def deserialize(self, data:str):
		"""Decodes your encoded data to tree.
		
		:type data: str
		:rtype: TreeNode
		"""
		i=[-1]
		data=data.split()
		nums=[]
		for s in data:
			if s!="NULL":
				nums.append(int(s))
			else:
				nums.append(None)
		return self.TreeInit(nums,i)
		

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))