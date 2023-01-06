from lib.test import *
"""
40. 组合总和 II

 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。 
 """

# [[39]] #组合 #回溯
class Solution:

	def __init__(self) -> None:
		self.ans=[]

	def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
		# 预先排序去除大于target的元素
		candidates.sort()
		for i in range(len(candidates)):
			if candidates[i]>target:
				candidates=candidates[:i]
				break
		# 使用队列来维护待选列表
		wait=candidates
		walk=[]
		self.backtrack(wait,walk,target)
		return self.ans

	def backtrack(self,wait:collections.deque,walk:List[int],target:int):
		""" 
		walk : 记录走过的路径
		"""
		# 当前选择已经超过target 直接完成选择
		if target==0:
			# 等于target 记录路径
			self.ans.append(walk.copy())
			return
		
		for i in range(len(wait)):
			if i>0 and wait[i-1]==wait[i]:
				continue
			cur=wait[i]
			walk.append(cur)
			target-=cur
			if target<0:
				# 剪枝优化，
				# 由于我们已经提前排序，所以当target 小于0 cur后面都是比cur大的数
				# 余下我们都不需要进行选择，只需要进行撤销路径
				target+=cur
				walk.pop()
				return
			nextwait=wait[i+1:].copy()#选择，每一个栈还是要一个新的变量，不然再回溯的过程中会将原始变量弹空
			self.backtrack(nextwait,walk,target)#向下搜索
			# 当该元素的所有可能都被遍历选择过后再弹出该元素
			# 例如 2,3,6,7 t=7 选择 2,2,2,2 之后 回溯到 2,2 这个决策分支此时所有2 已经全部选过了，所以可以撤销该决策分支 
			target+=cur
			#撤销路径的记录
			walk.pop()

if __name__ == "__main__":
	pass