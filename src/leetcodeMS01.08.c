#include <test.h>
#include <stdio.h>
#include <stdlib.h>

// #matrix #hash
/* 零矩阵
通过row col 两个变量来标记哪一行哪一列需要标记

空间优化就是用第一行与第一列来标记哪些行列需要标记,理由如下:

很显然需要置零的列会导致第一行也置零, 行也相同.


但相对应的需要额外的标记变量来记录第一行与第一列是否需要被置零

 */
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
	int *row,*col,m=matrixSize,n=matrixColSize[0];
	row=calloc(m,sizeof(int));
	col=calloc(n,sizeof(int));

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (matrix[i][j]==0)
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

