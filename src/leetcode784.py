from typing import  List 

# #回溯 #二叉树 #字符串
class Solution:
	def __init__(self):
		self.ans=[]

	def letterCasePermutation(self, s: str) -> List[str]:
		self.l=len(s)
		wait=[c for c in s]
		self.dfs(0,wait)
		return self.ans

	def dfs(self,pos:int,s:List[str]):
		#如果是数字，持续向前走
		while pos<self.l and s[pos].isdigit():
			pos+=1
		# 判断是否走完字符串
		if pos==self.l:
			self.ans.append("".join(s))
			return
		self.dfs(pos+1,s)#先遍历到firstchild 
		s[pos]=s[pos].swapcase()#后序遍历改变状态
		self.dfs(pos+1,s)#先序遍历到另一条分支
		s[pos]=s[pos].swapcase()#状态回退

						

if __name__ == "__main__":
	s=Solution().letterCasePermutation("a2b1")
	print(s)

			
