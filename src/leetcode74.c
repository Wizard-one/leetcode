/* 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

    每行中的整数从左到右按升序排列。
    每行的第一个整数大于前一行的最后一个整数。
 */
// [[240]] #搜索 #matrix 
/* 同240 完全一致 */

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
	int m=matrixSize,n=matrixColSize[0];
	int x=0,y=n-1;
	while (x<m&&y>=0)
	{
		if (matrix[x][y]==target)
		{
			return true;
		}
		else if (matrix[x][y]<target)
		{
			x++;
		}
		else
		{
			y--;
		}
	}
	return false;
	
}