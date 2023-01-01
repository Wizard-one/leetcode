#include <test.h>

/*  200. 岛屿数量

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。 */ 
// #深度优先搜索 #matrix [[695]]


/* 
照抄 695 深搜完事
 */
void searchArea(int r,int c,char** grid, int gridSize, int* gridColSize,int* area)
{
	if (r>=gridSize||r<0)
	{
		return;
	}
	else if (c>=gridColSize[r]||c<0)
	{
		return;
	}
	if (grid[r][c]=='1')
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

int numIslands(char** grid, int gridSize, int* gridColSize){
	int count=0,area=0;
	for (size_t i = 0; i < gridSize; i++)
	{
		for (size_t j = 0; j < gridColSize[i]; j++)
		{
			if (grid[i][j]=='1')
			{
				searchArea(i,j,grid,gridSize,gridColSize,&area);
				if (area!=0)
				{
					count++;
				}
				
				area=0;
			}
		}
	}
	return count;
}

#define N 5
#define M 4
int main(){
	char map[M][N]={{1,1,1,1,0},{1,1,0,1,0},{1,1,0,0,0},{0,0,0,0,0}};
	char **grid;
	int gc[M];
	grid=malloc(sizeof(char*)*M);
	for (size_t i = 0; i < M; i++)
	{
		grid[i]=malloc(sizeof(char)*N);
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
	ans=numIslands(grid,M,gc);
	printf("%d",ans);
}