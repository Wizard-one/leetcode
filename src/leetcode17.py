from lib.test import *

""" 17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 """
# #字符串 #回溯 #排列 

class Solution:
	""" 这个问题是固定位置的组合, 
	即 2-> 'abc' 3 -> 'def'
	23 对应先在 abc 中选一个 然后再def 中选一个
	所以 223 232 这并不是同一种情况无需对给定数字位进行排序

	由于要返回路径上所有选择,所以使用回溯来暴力搜索
	"""
	def __init__(self) -> None:
		self.ans=[]
		self.depth=0

	def letterCombinations(self, digits: str) -> List[str]:
		table={"2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}
		n=len(digits)
		if n==0:
			return []
		walk=[]
		wait=[]
		# 使用栈来维护备选集合, 倒序制作
		for i in range(len(digits)):
			c=digits[n-i-1]
			wait.append(table[c])
		self.backtrace(wait,walk)
		return self.ans
		# return list(set(self.ans))

	def backtrace(self, wait:List[int],walk:List[str]):
		"""
		docstring
		"""
		if not wait:
			self.ans.append("".join(walk))
			return
		# 弹出一个选择
		cur=wait.pop()
		for c in cur:
			# 选择每一个字符时都需要重新做一次拷贝,
			# 因为在向下递归的过程中上一步弹栈会反复执行,而nextwait这个变量的生命周期在整个for 循环中都会被调用
			nextwait=wait.copy()			
			walk.append(c)#在一个字符组中选择一个
			self.backtrace(nextwait,walk)
			walk.pop()#撤销选择
				
if __name__ == "__main__":
	s=Solution().letterCombinations
	print(s(""))

