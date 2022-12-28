
"""
844. 比较含退格的字符串

给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。
"""
from lib.test import *

# #栈 #模拟 #字符串

""" 直接使用栈来模拟这个过程 """
class Solution:
	def backspaceCompare1(self, s: str, t: str) -> bool:
		s1=[]
		for c in s:
			# 遇到# pop
			if len(s1)!=0 and c=="#":
				s1.pop()
			elif len(s1)==0 and c=="#":
				continue
			else:
				s1.append(c)
		s2=[]
		for c in t:
			if len(s2)!=0 and c=="#":
				s2.pop()
			elif len(s2)==0 and c=="#":
				continue
			else:
				s2.append(c)
		# 最后比较两个栈是否相同
		if s1==s2:
			return True
		else:
			return False
				

