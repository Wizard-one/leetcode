#include <stdlib.h>
#include <stdio.h>

#define IMAX(a,b) (a>b)?(a):(b)

// #深度优先搜索 #matrix
void searchArea(int r,int c,int** grid, int gridSize, int* gridColSize,int* area)
{
	if (r>=gridSize||r<0)
	{
		return;
	}
	else if (c>=gridColSize[r]||c<0)
	{
		return;
	}
	if (grid[r][c]==1)
	{
		grid[r][c]=0;
		(*area)++;
	}
	else
	{
		return;
	}
	
	searchArea(r+1,c,grid,gridSize,gridColSize,area);
	searchArea(r-1,c,grid,gridSize,gridColSize,area);
	searchArea(r,c+1,grid,gridSize,gridColSize,area);
	searchArea(r,c-1,grid,gridSize,gridColSize,area);

	return;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
	int maxarea=0,area=0;
	for (size_t i = 0; i < gridSize; i++)
	{
		for (size_t j = 0; j < gridColSize[i]; j++)
		{
			if (grid[i][j]==1)
			{
				searchArea(i,j,grid,gridSize,gridColSize,&area);
				maxarea=IMAX(maxarea,area);
				area=0;
			}
		}
	}
	return maxarea;
}
#define N 13
#define M 8
int main(){
	int map[M][N]={{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
	int **grid;
	int gc[M];
	grid=malloc(sizeof(int*)*M);
	for (size_t i = 0; i < M; i++)
	{
		grid[i]=malloc(sizeof(int)*N);
	}
	for (size_t i = 0; i < M; i++)
	{
		gc[i]=N;
		for (size_t j = 0; j < N; j++)
		{
			grid[i][j]=map[i][j];
		}
	}
	int ans;
	ans=maxAreaOfIsland(grid,M,gc);
	printf("%d",ans);

}