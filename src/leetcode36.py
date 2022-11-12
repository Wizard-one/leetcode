from typing import List
import numpy as np


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
