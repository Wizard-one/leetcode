#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <test.h>
typedef struct boundary
{
	int l;
	int r;
	int t;
	int b;
} boundary;


int ** GetSub(int **mat,boundary bc)
{
	int **submat;
	submat=malloc(sizeof(int *)*(bc.b-bc.t+1));
	if (bc.b==bc.t && bc.r==bc.l)
	{
		submat[0]=malloc(sizeof(int));
		submat[0][0]=mat[0][0];
		return submat;
	}
	
	for (size_t i = bc.t; i <=bc.b; i++)
	{
		submat[i]=malloc(sizeof(int)*(bc.r-bc.l+1));
		for (size_t j = bc.l; j <= bc.r; j++)
		{
			submat[i-bc.t][j-bc.l]=mat[i][j];
		}
	}
	return submat;
}

void GetRC(boundary bc,int *row,int **col)
{
	(*row)=bc.b-bc.t+1;
	(*col)=malloc(sizeof(int)*(*row));
	for (size_t i = 0; i < (*row); i++)
	{
		(*col)[i]=bc.r-bc.l+1;
	}
}
/* 
尝试使用二维的二分法来解决，但是算法编写太复杂没能再规定时间内完成。
再加上子矩阵维护难度较高,这一版本就以bug收场

还是应该先做一份简单，按行的二分搜索。不能直接实现一个很复杂的算法。
 */
bool searchMatrixGG(int** matrix, int matrixSize, int* matrixColSize, int target){
	boundary bc;
	int i,j;
	bc.t=0;
	bc.b=matrixSize-1;
	bc.l=0;
	bc.r=matrixColSize[0]-1;
	int **submat;
	int *col,row;
	bool ans1,ans2,ans3,ans4;
	if (bc.l>bc.r || bc.t>bc.b)
		return false;
	// 进行二分搜索
	i=(bc.t+bc.b)/2;
	j=(bc.l+bc.r)/2;
	if (matrix[i][j]==target)
		return true;
	else if (matrix[i][j]>target)
	{
		// 给定矩阵行列严格递增，所以目标在左上角
		bc.b=i;
		bc.r=j;
		submat=GetSub(matrix,bc);
		GetRC(bc,&row,&col);
		ans1=searchMatrixGG(submat,row,col,target);
		return ans1;
	}
	else
	{
		// 当前matrix[i][j]小于target,则在右下角，右上角，左下角
		// 右上角
		bc.b=i;
		bc.l=j+1;
		if(bc.l>=matrixColSize[0])
			return false;
		GetRC(bc,&row,&col);
		submat=GetSub(matrix,bc);
		ans2=searchMatrixGG(submat,row,col,target);
		//右下角
		bc.b=matrixSize-1;
		bc.t=i+1;
		if(bc.t>=matrixSize)
		
			return false;

		GetRC(bc,&row,&col);
		submat=GetSub(matrix,bc);
		ans3=searchMatrixGG(submat,row,col,target);
		bc.l=0;
		bc.r=i;
		GetRC(bc,&row,&col);
		submat=GetSub(matrix,bc);
		ans4=searchMatrixGG(submat,row,col,target);
		return ans2||ans3||ans4;
	}
}

/* 240. 搜索二维矩阵 II
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

    每行的元素从左到右升序排列。
    每列的元素从上到下升序排列。
 */

// #搜索 #matrix  
/* 从右上角开始搜索，这样向下走都是变大，向左走都是变小 */
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

int main(){
	int mat[5][5]={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
	int **matp,n=5,nc[5]={5,5,5,5,5};
	matp=malloc(sizeof(int*)*n);
	for (size_t i = 0; i < n; i++)
	{
		matp[i]=malloc(sizeof(int)*n);
		for (size_t j = 0; j < n; j++)
		{
			matp[i][j]=mat[i][j];
		}
	}
	bool ans;
	ans=searchMatrix(matp,n,nc,5);
	printf("%d",ans);
}