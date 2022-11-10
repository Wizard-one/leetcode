#include <stdio.h>
#include <stdlib.h>
/* 
行列置零, 做一个行列hash表, 行列index 为独立,所以可以用数组代替
 */
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
	int m=matrixSize,n=matrixColSize[0];
	int *row,*col;
	row=calloc(m,sizeof(int));
	col=calloc(n,sizeof(int));
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