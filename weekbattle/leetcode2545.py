from lib.test import *
import numpy as np
"""
2545. 根据第 K 场考试的分数排序
 班里有 m 位学生，共计划组织 n 场考试。给你一个下标从 0 开始、大小为 m x n 的整数矩阵 score ，其中每一行对应一位学生，而 score[i][j] 表示第 i 位学生在第 j 场考试取得的分数。矩阵 score 包含的整数 互不相同 。

另给你一个整数 k 。请你按第 k 场考试分数从高到低完成对这些学生（矩阵中的行）的排序。

返回排序后的矩阵。 """

# #排序
class Solution:
	def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
		sc=np.array(score)
		ind=sc[:,k].argsort()
		ind=np.flip(ind)
		ans=sc[ind].tolist()
		return ans

if __name__ == "__main__":
	s=Solution().sortTheStudents
	print(s([[10,6,9,1],[7,5,11,2],[4,8,3,15]],2))