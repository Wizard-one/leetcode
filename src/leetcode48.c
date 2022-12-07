#include <stdlib.h>
#include <stdio.h>

void printmat(int **mat, int matrixSize, int* matrixColSize)
{
	for (size_t i = 0; i < matrixSize; i++)
	{
		for (size_t j = 0; j < matrixColSize[i]; j++)
		{
			printf("%d,",mat[i][j]);
		}
		printf("\n");
	}
}


void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
/* 48. 旋转图像


 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 */


// 顺时针旋转等价于2次翻转
// #数组 #matrix
void rotate(int** matrix, int matrixSize, int* matrixColSize){
	// 对角线翻转
	for (size_t i = 0; i < matrixSize-1; i++)
	{
		for (size_t j = 0; j < matrixColSize[i]-i; j++)
		{
			swap(&matrix[i][j],&matrix[matrixSize-j-1][matrixColSize[i]-i-1]);
		}
	}
	// 上下翻转
	for (size_t i = 0; i < matrixSize/2; i++)
	{
		for (size_t j = 0; j < matrixColSize[i]; j++)
		{
			swap(&matrix[i][j],&matrix[matrixSize-i-1][j]);
		}
	}
}


int main()
{
	int mat[3][3]={{1,2,3},{4,5,6},{7,8,9}},**matp,n=3,nc[3]={3,3,3};
	matp=malloc(sizeof(int*)*n);
	for (size_t i = 0; i < n; i++)
	{
		matp[i]=malloc(sizeof(int)*n);
		for (size_t j = 0; j < n; j++)
		{
			matp[i][j]=mat[i][j];
		}
	}
	
	rotate(matp,n,nc);
	printmat(matp,n,nc);
	

}