from lib.test import *

""" 39. 组合总和

给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 """

# #回溯 #数组 #求和 #组合 [[46]] [[40]]

""" 
由于同一个数字可以 无限制重复使用，所以对于回溯模板只需要调整选择与撤销选择的过程

这里选择使用队列而不是循环来维护 待选择wait变量，当选择完成之后需要撤销选择时才将当前选择出队
"""
class Solution:

	def __init__(self) -> None:
		self.ans=[]

	def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
		# 预先排序去除大于target的元素
		candidates.sort()
		for i in range(len(candidates)):
			if candidates[i]>target:
				candidates=candidates[:i]
				break
		# 使用队列来维护待选列表
		wait=collections.deque(candidates)
		walk=[]
		self.backtrack(wait,walk,target)
		return self.ans

	def backtrack(self,wait:collections.deque,walk:List[int],target:int):
		""" 
		walk : 记录走过的路径
		"""
		if target==0:
			# 等于target 记录路径
			self.ans.append(walk.copy())
			return
		
		while(wait):
			cur=wait[0]
			walk.append(cur)
			target-=cur
			# 当前选择已经超过target 直接完成选择，剪枝优化
			if target<0:
				target+=cur
				wait.popleft()
				#撤销路径的记录
				walk.pop()
				return
			nextwait=wait.copy()#选择，每一个栈还是要一个新的变量，不然再回溯的过程中会将原始变量弹空
			self.backtrack(nextwait,walk,target)#向下搜索
			# 当该元素的所有可能都被遍历选择过后再弹出该元素
			# 例如 2,3,6,7 t=7 选择 2,2,2,2 之后 回溯到 2,2 这个决策分支此时所有2 已经全部选过了，所以可以撤销该决策分支 
			target+=cur
			wait.popleft()
			#撤销路径的记录
			walk.pop()

if __name__ == "__main__":
	s=Solution().combinationSum
	print(s([5,2,1],11))


		