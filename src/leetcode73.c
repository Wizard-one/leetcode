#include <stdio.h>
#include <stdlib.h>
/* 
73. 矩阵置零
做一个行列hash表, 行列index 为独立,所以可以用数组代替

给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 */
// #matrix #hash time: O(n*m) space: (n+m)
/* 优化： 可以用矩阵的第一行第一列存储 */
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
	int m=matrixSize,n=matrixColSize[0];
	int *row,*col;
	row=calloc(m,sizeof(int));//记录0出现行
	col=calloc(n,sizeof(int));
	// 先记录后赋值
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			/* code */
			if(matrix[i][j]==0)
			{
				row[i]=1;
				col[j]=1;
			}
		}
		
	}
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (row[i]==1 || col[j]==1)
			{
				matrix[i][j]=0;
			}
			
		}		
	}
}

int main(){
	int a[3][3]={{1,1,1},{1,0,1},{1,1,1}};
	int b[3]={3};
	setZeroes(a,3,b);
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			printf("%d,",a[i][j]);
		}
		printf("\n");
	}
	
}