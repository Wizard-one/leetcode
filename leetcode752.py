from lib.test import *
"""752. 打开转盘锁
 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。

  """
class Solution:

	def select(self,s:List[int],j:int)->Tuple[str]:
		newcur=s.copy()
		if newcur[j]==9:
			newcur[j]=0
			su="".join([str(i) for i in newcur])
			newcur[j]=8
			sd="".join([str(i) for i in newcur])
		elif newcur[j]==0:
			newcur[j]=1
			su="".join([str(i) for i in newcur])
			newcur[j]=9
			sd="".join([str(i) for i in newcur])
		else:
			newcur[j]+=1
			su="".join([str(i) for i in newcur])
			newcur[j]-=2
			sd="".join([str(i) for i in newcur])
		return su,sd

	def openLock(self, deadends: List[str], target: str) -> int:
		deadends=set(deadends)
		if "0000" in deadends:
			return -1
		q=collections.deque(["0000"])
		count=0
		while(q):
			sz=len(q)
			for i in range(sz):
				cur=q.popleft()
				if target==cur:
					return count
				cur=[int(i) for i in cur]
				for j in range(4):
					su,sd=self.select(cur,j)
					if su not in deadends:
						q.append(su)
						deadends.add(su)
					if sd not in deadends:
						q.append(sd)
						deadends.add(sd)
			count+=1
		return -1

	


					
