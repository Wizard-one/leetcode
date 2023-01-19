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

# #双向BFS
class Solution:
	""" 这边添加一个双向BFS优化的示例。
	使用两个hashset 而非队列进行维护，轮流扩散 h1 h2 虽然最坏情况都是O(N) 但是会有两者提前相遇的情况，即存在遍历更少节点的可能
	
	而始终从len小的hashset添加新的节点可以进一步减少遍历走过的节点数目
	"""
	def openLock(self, deadends: List[str], target: str) -> int:
		def getNxt(char):
			prev = str((int(char) + 9) % 10)
			nxt = str((int(char) + 1) % 10)
			return [prev, nxt]

		if '0000' in deadends or target in deadends:
			return -1
		if target == '0000':
			return 0
		deadends = set(deadends)
		visited = set(['0000', target])
		# 起始hashset 终止hashset
		startVis, endVis = set(['0000']), set([target])
		res = 1
		# 一定要两者都不为空，任意有一者为空说明可行路径都被走过了
		while startVis and endVis:
			# hashset 不可变 这边新建一个作为next
			nxtVis = set()
			# 始终从长度小的hashset进行扩散，这样添加的节点数少
			if len(startVis) > len(endVis):
				startVis, endVis = endVis, startVis
			for cur in startVis:
				cur = list(cur)
				for i in range(4):
					pd = cur[i]
					for d in getNxt(pd):
						cur[i] = d 
						nxt = ''.join(cur)
						if nxt not in deadends:
							if nxt in endVis:
								return res
							if nxt not in visited:
								visited.add(nxt)
								nxtVis.add(nxt)
					# 回退选择pd
					cur[i] = pd
			# 存储下一个hashset
			startVis = nxtVis
			# 注意是轮流走，而不是同时走，所以每次+1 即可
			res += 1
		return -1


if __name__ == "__main__":
	s=Solution().openLock
	s(["8888"],"0009")
	


					
