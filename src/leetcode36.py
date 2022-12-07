from typing import List
import numpy as np

# #matrix 

""" 
36. 有效的数独


请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

    数字 1-9 在每一行只能出现一次。
    数字 1-9 在每一列只能出现一次。
    数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）

 

注意：

    一个有效的数独（部分已被填充）不一定是可解的。
    只需要根据以上规则，验证已经填入的数字是否有效即可。
    空白格用 '.' 表示。

 """
class Solution:
	def isValidSudoku(self, board: List[List[str]]) -> bool:
		board=np.array(board)
		for row in board:
			v,c=np.unique(row,return_counts=True)
			if np.any(c[1:]>1):
				return False
		for i in range(board.shape[1]):
			col=board[:,i]
			v,c=np.unique(col,return_counts=True)
			if np.any(c[1:]>1):
				return False
		for i in range(3):
			for j in range(3):
				cell=board[i*3:(i+1)*3,j*3:(j+1)*3].ravel()
				v,c=np.unique(cell,return_counts=True)
				if np.any(c[1:]>1):
					return False
		return True
	

if __name__ == "__main__":
	s=Solution()
	board=[["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
	ans=s.isValidSudoku(board=board)
	print(ans)
