#排序 #matrix time: O(m*nlogn)

""" 给你一个 m x n 大小的矩阵 grid ，由若干正整数组成。

执行下述操作，直到 grid 变为空矩阵：

    从每一行删除值最大的元素。如果存在多个这样的值，删除其中任何一个。
    将删除元素中的最大值与答案相加。

注意 每执行一次操作，矩阵中列的数据就会减 1 。

返回执行上述操作后的答案。
 """



from lib.test import *
class Solution:
	def deleteGreatestValue(self, grid: List[List[int]]) -> int:
		# 先对列排序
		for col in grid:
			col.sort()
		m=len(grid)
		n=len(grid[0])
		s=[]
		for i in range(n):
			ma=0
			for j in range(m):
				# 遍历每一行找出最大的元素
				if grid[j][i]>ma:
					ma=grid[j][i]
			# 加入结果集合
			s.append(ma)
		return sum(s)#返回和

if __name__ == "__main__":
	s=Solution().deleteGreatestValue
	ans=s([[10]])
	print(ans)