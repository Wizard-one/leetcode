from lib.test import *

""" 304. 二维区域和检索 - 矩阵不可变

给定一个二维矩阵 matrix，以下类型的多个请求：

    计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。

实现 NumMatrix 类：

    NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
    int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1) 、右下角 (row2, col2) 所描述的子矩阵的元素 总和 。
"""
# #前缀和 #matrix
class NumMatrix:
	""" 避免重复计算，做一个前缀和矩阵 """
	def __init__(self, matrix: List[List[int]]):
		# 为了解决 row==0 col==0 的问题 presum 需要存储 (0,0,i-1,j-1)
		m,n=len(matrix),len(matrix[0])
		self.presum=[]
		# 矩阵初始化
		for i in range(m+1):
			self.presum.append([0]*(n+1))
		for i in range(1,m+1):
			for j in range(1,len(matrix[0])+1):
				# 上一行+上一列+自己-重复的左上角
				self.presum[i][j]=self.presum[i][j-1]+self.presum[i-1][j]+matrix[i-1][j-1]-self.presum[i-1][j-1]


	def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
		# 由于前缀和已经前置存储一位，不需要对边界进行判断
		return self.presum[row2+1][col2+1]-self.presum[row1][col2+1]-self.presum[row2+1][col1]+self.presum[row1][col1]
if __name__ == "__main__":
	na=NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]])
	print(na.presum)

# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)