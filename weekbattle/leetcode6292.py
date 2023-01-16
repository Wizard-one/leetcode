from lib.test import *
""" 
6292. 子矩阵元素加 1
给你一个正整数 n ，表示最初有一个 n x n 、下标从 0 开始的整数矩阵 mat ，矩阵中填满了 0 。

另给你一个二维整数数组 query 。针对每个查询 query[i] = [row1i, col1i, row2i, col2i] ，请你执行下述操作：

    找出 左上角 为 (row1i, col1i) 且 右下角 为 (row2i, col2i) 的子矩阵，将子矩阵中的 每个元素 加 1 。也就是给所有满足 row1i <= x <= row2i 和 col1i <= y <= col2i 的 mat[x][y] 加 1 。

返回执行完所有操作后得到的矩阵 mat 。 """

class Solution:
	def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
		m=len(queries)
		mat=[]
		base=[0]*n
		for i in range(n):
			mat.append(base.copy())
		for pos in queries:
			r0,c0,r1,c1=pos
			for i in range(r0,r1+1):
				for j in range(c0,c1+1):
					mat[i][j]+=1
		return mat


if __name__ == "__main__":
	s=Solution().rangeAddQueries
	print(s(3, [[1,1,2,2],[0,0,1,1]]))