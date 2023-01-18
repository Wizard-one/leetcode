from lib.test import *
"""752. 打开转盘锁
 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。

  """

# #广度优先搜索 
class Solution:
	""" 
	求最短路，使用BFS 每次转动可以+1 or -1 然后处理 0-1=9 以及9+1=0的两个情况

	而deadends 直接视为走过的路径即可，同时单独处理 起始点0000为 deadends 
	"""
	def openLock(self, deadends: List[str], target: str) -> int:
		def getNxt(char):
			# 简单化处理 -1 e.g 0-1=9 %10 =9
			prev = str((int(char) + 9) % 10)
			# 同时处理 +1
			nxt = str((int(char) + 1) % 10)
			return [prev, nxt]
		# 使用hash表加速判断是否走过
		deadends=set(deadends)
		if "0000" in deadends:
			return -1
		q=collections.deque(["0000"])
		count=0
		# 标准BFS
		while(q):
			sz=len(q)
			for i in range(sz):
				cur=q.popleft()
				if target==cur:
					return count
				cur=list(cur)
				for j in range(4):
					temp=cur[j]
					select=getNxt(temp)
					for c in select:
						cur[j]=c
						s="".join(cur)
						# 判断是否走过或者属于 deadends 
						if s not in deadends:
							q.append(s)
							deadends.add(s)
						cur[j]=temp
			count+=1
		return -1

if __name__ == "__main__":
	s=Solution().openLock
	s(["8888"],"0009")
	


					
