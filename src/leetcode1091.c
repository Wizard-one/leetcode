#include <test.h>
/*1091. 二进制矩阵中的最短路径

 给你一个 n x n 的二进制矩阵 grid 中，返回矩阵中最短 畅通路径 的长度。如果不存在这样的路径，返回 -1 。

二进制矩阵中的 畅通路径 是一条从 左上角 单元格（即，(0, 0)）到 右下角 单元格（即，(n - 1, n - 1)）的路径，该路径同时满足下述要求：

    路径途经的所有单元格都的值都是 0 。
    路径中所有相邻的单元格应当在 8 个方向之一 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。

畅通路径的长度 是该路径途经的单元格总数。
 */

// #深度优先搜索 #matrix #超时
typedef struct pos{
	int i;
	int j;
}pos;

int xm[]={-1,0,1},ym[]={-1,0,1};


int dfs(int** grid, int n,pos loc, int length,int *minlen)
{
	int **gridcopy;

	if (loc.i==n-1 && loc.j==n-1)
	{
		(*minlen)=(*minlen)>length?length:(*minlen);
		return 1;
	}
	else
	{
	
		gridcopy=malloc(n*sizeof(int *));
		for (size_t i = 0; i < n; i++)
		{
			gridcopy[i]=malloc(n*sizeof(int));
			for (size_t j = 0; j < n; j++)
			{
				gridcopy[i][j]=grid[i][j];
			}
			
		}
		gridcopy[loc.i][loc.j]=1;
		length++;
	}
	int res=0;
	pos temp;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (loc.i+xm[i]<0 || loc.i+xm[i]>=n ||loc.j+ym[j]<0 || loc.j+ym[j]>=n || grid[loc.i][loc.j]!=0||(xm[i]==0&&ym[j]==0))
			{
				continue;
			}
			temp.i=loc.i+xm[i];
			temp.j=loc.j+ym[j];
			res=dfs(gridcopy,n,temp,length,minlen);
		}
	}
	return res;
}

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize){
	int length=1;
	if (grid[0][0] || grid[gridSize-1][gridSize-1])
	{
		return -1;
	}
	int minlen=gridSize*gridSize;
	pos loc={0,0};
	dfs(grid,gridSize,loc,length,&minlen);
	if (minlen==gridSize*gridSize && gridSize!=1)
		return -1;
	return minlen;
}

#define N 3
int main(int argc, char const *argv[])
{
	int l[N][N]={{0,0,0},{1,1,0},{1,1,0}};
	int **pl,gc[]={N,N,N};
	pl=malloc(N*sizeof(int *));
	for (size_t i = 0; i < N; i++)
	{
		pl[i]=malloc(N*sizeof(int));
		for (size_t j = 0; j < N; j++)
		{
			pl[i][j]=l[i][j];
		}
		
	}
	int ans=shortestPathBinaryMatrix(pl,N,gc);
	printf("%d",ans);
	return 0;
}
